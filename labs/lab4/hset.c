#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hset.h"

unsigned long int good_hash(const char* s)
{
    unsigned long int hash = 17;
    int slen = strlen(s);
    for (int i = 0; i < slen; i++) {
        hash = 37 * hash + s[i];
    }
    return hash;
}

unsigned long int bad_hash(const char* s)
{
    unsigned long int hash = 0;
    int slen = strlen(s);
    for (int i = 0; i < slen; i++) {
        hash += s[i];
    }
    return hash;
}

hset* hset_new(unsigned long int(*hash_func)(const char*), size_t sz)
{
    hset* new_hset = malloc(sizeof(hset));
    if (new_hset == NULL) {
        fprintf(stderr, "Heap is full");
        exit(1);
    }
    new_hset->hash_func = hash_func;
    new_hset->buckets = malloc(sz * sizeof(bucket));
    if (new_hset->buckets == NULL) {
        fprintf(stderr, "Heap is full");
        exit(1);
    }
    new_hset->n_buckets = sz;
    return new_hset;
}

size_t hset_size(hset* hs)
{
    size_t size = 0;
    for (int i = 0; i < hs->n_buckets; i++) {
        size += bucket_size(hs->buckets[i]);
    }
    return size;
}

double hset_load_factor(hset* hs)
{
    return hset_size(hs) / hs->n_buckets;
}

size_t hset_max_bucket(hset* hs)
{
    double max_size = 0;
    for (int i = 0; i < hs->n_buckets; i++) {
        int size = bucket_size(hs->buckets[i]);
        if (size > max_size) {
            max_size = size;
        }    
    }
    return max_size;
}

size_t hset_insert(const char* s, hset* hs)
{
    int s_hash = hs->hash_func(s);
    int i = s_hash % hs->n_buckets;
    bucket* new_bucket = bucket_cons(s, s_hash, hs->buckets[i]);
    hs->buckets[i] = new_bucket;
    return bucket_size(new_bucket); 
}

int hset_contains(const char* s, hset* hs)
{
    for (int i = 0; i < hs->n_buckets; i++) {
        if (bucket_contains(s, hs->hash_func(s), hs->buckets[i]) == 1) {
            return 1;
        }
    }
    return 0;
}

void hset_show(hset* hs)
{
    for (int i = 0; i < hs->n_buckets; i++) {
        if (hs->buckets[i]) {
            printf("%d: ", i);
            bucket_show(hs->buckets[i]);
        }
    }
}

void hset_free(hset* hs)
{
    for (int i = 0; i < hs->n_buckets; i++) {
        bucket_free(hs->buckets[i]);
    }
    free(hs);
}
