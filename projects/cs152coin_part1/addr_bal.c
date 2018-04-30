#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addr_bal.h"

//
//
// BUCKET FUNCTIONS
// 
//

bucket* bucket_cons(char* addr, double bal, unsigned long int hash, bucket* prev_head)
{
    bucket* new_bucket = malloc(sizeof(bucket));
    new_bucket->addr = strdup(addr);
    new_bucket->balance = bal;
    new_bucket->hash = hash;
    new_bucket->next = prev_head;
    return new_bucket;
}

int bucket_contains(char* addr, unsigned long int hash, bucket* b)
{
    while (b) {
        //if (b->hash == hash) {
            if (strcmp(b->addr, addr) == 0) {
                return 1;
            }
        //}
        b = b->next;
    }
    return 0;    
}

void bucket_free(bucket* b)
{
    while (b) {
        bucket* next_b = b->next;
        free(b->addr);
        free(b);
        b = next_b;
    }
}

void bucket_show(bucket* b)
{
    if (b) {
        while (b) {
            fprintf(stdout, "(%s, %f, %lu), ", b->addr, b->balance, b->hash);
            b = b->next;
        }
        printf("\n");
    }
}

//
//
// ADDR_BAL_T HASH SET AUX FUNCTIONS
//
//

unsigned long int good_hash(const char* addr)
{
    unsigned long int hash = 17;
    int addr_len = strlen(addr);
    for (int i = 0; i < addr_len; i++) {
        hash = 37 * hash + addr[i];
    }
    return hash;
}

void ab_insert(char* addr, double bal, addr_bal_t* ab)
{
    int hash = ab->hash_func(addr);
    int i = hash % ab->n_buckets;
    bucket* new_bucket = bucket_cons(addr, bal, hash, ab->buckets[i]);
    ab->buckets[i] = new_bucket;
}

void ab_show(addr_bal_t* ab)
{
    for (int i = 0; i < ab->n_buckets; i++) {
        if (ab->buckets[i]) {
            printf("%d: ", i);
            bucket_show(ab->buckets[i]);
        }
    }
    printf("\n");
}

//
//
// ADDR_BAL_T
//
//

addr_bal_t* addr_bal_new()
{
    addr_bal_t* ab = malloc(sizeof(addr_bal_t));
    ab->hash_func = good_hash;
    // Fixed Size Hash Table (5000)
    ab->buckets = malloc(5000 * sizeof(bucket*));
    ab->n_buckets = 5000;
    return ab;
}

void addr_bal_free(addr_bal_t* ab)
{
    for (int i = 0; i < ab->n_buckets; i++) {
        bucket_free(ab->buckets[i]);
    }
    free(ab->buckets);
    free(ab);
}

// Discussed Algorithm with Dustin Zhang
int get_balance(const char* addr, double* out_bal, addr_bal_t* ab)
{
    int hash = ab->hash_func((char*)addr);
    int i = hash % ab->n_buckets;
    if (bucket_contains((char*)addr, ab->hash_func((char*)addr), ab->buckets[i])) {
        if (ab->buckets[i]->next) {
            bucket* curr_bucket = ab->buckets[i];
            while (curr_bucket) {
                bucket* next_bucket = curr_bucket->next;
                if (curr_bucket->hash == hash) {
                    if (strcmp(curr_bucket->addr, addr) == 0) {
                        *out_bal = curr_bucket->balance;
                        return 1;
                    }
                }
                curr_bucket = next_bucket;
            }    
        } else {
            *out_bal = ab->buckets[i]->balance;
            return 1;
        }
    }
    return 0;
}

void set_balance(const char* addr, double bal, addr_bal_t* ab)
{
    double out_bal = 0;
    if (!get_balance(addr, &out_bal, ab)) {
        ab_insert((char*)addr, bal, ab);
        return;
    }
    
    int hash = ab->hash_func((char*)addr);
    int i = hash % ab->n_buckets;
    if (bucket_contains((char*)addr, ab->hash_func((char*)addr), ab->buckets[i])) {
        if (ab->buckets[i]->next) {
            bucket* curr_bucket = ab->buckets[i];
            while (curr_bucket) {
                bucket* next_bucket = curr_bucket->next;
                if (curr_bucket->hash == hash) {
                    if (strcmp(curr_bucket->addr, addr) == 0) {
                        curr_bucket->balance += bal;
                        return;
                    }
                }
                curr_bucket = next_bucket;
            }    
        } else {
            ab->buckets[i]->balance += bal;
            return;     
        }
    }
}
