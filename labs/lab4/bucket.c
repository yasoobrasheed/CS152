#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hset.h"

bucket* bucket_cons(const char* s, unsigned long int hash, bucket* prev_head)
{

    bucket* new_bucket = malloc(sizeof(bucket));
    if (new_bucket == NULL) {
        fprintf(stderr, "Heap is full");
        exit(1);
    }
    char* str = strdup(s);
    new_bucket->string = str;
    new_bucket->hash = hash;
    new_bucket->next = prev_head;
    return new_bucket;
}

size_t bucket_size(bucket* b)
{
    size_t size = 0;
    while (b) {
        size += 1;
        b = b->next;
    }
    return size;
}

int bucket_contains(const char* s, unsigned long int hash, bucket* b)
{
    while (b) {
        if (b->hash == hash) {
            if (strcmp(b->string, s) == 0) {
                return 1;
            }
        }
        b = b->next;
    }
    return 0;    
}

void bucket_show(bucket* b)
{
    if (b) {
        while (b) {
            fprintf(stdout, "(%s, %lu), ", b->string, b->hash);
            b = b->next;
        }
        printf("\n");
    }
}

void bucket_free(bucket* b)
{
    bucket* curr_bucket = b;
    while (curr_bucket) {
        bucket* next_bucket = curr_bucket->next;
        free(curr_bucket->string);
        free(curr_bucket);
        curr_bucket = next_bucket;
    }
}

