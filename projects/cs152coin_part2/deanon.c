#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "hmap.h"
#include "deanon.h"
#include "cs152coin.h"

deanon_t* deanon_new()
{
    deanon_t* deanon = malloc(sizeof(deanon_t));
    deanon->hmap = hmap_new();
    return deanon;
}

void deanon_free(deanon_t* d)
{
    // Rewrote hmap_free and bucket_free to not mess with the hashmap 
    // code that exists already, but still account for the freeing of 
    // the void pointers
    for (size_t i = 0; i < d->hmap->n_buckets; i++) {
        bucket_t* b = d->hmap->buckets[i];
        while (b != NULL) {
            bucket_t* prev_b = b;
            b = b->next;
            free(prev_b->key);
            cluster_free(prev_b->value);
            free(prev_b);
        }
    }
    free(d->hmap->buckets);
    free(d->hmap);
    free(d);
}

void add_address(const char* addr, deanon_t* d)
{
    cluster_t* singleton = cluster_new(addr);
    // If it already exists in the hmap, free it
    if (!hmap_put(addr, singleton, d->hmap)) {
        cluster_free(singleton);
    }
}

void add_associations(dep_wd_t* trans_inputs[], unsigned int num_inputs, deanon_t* d)
{
    for (int i = 0; i < num_inputs; i++) {
        add_address(trans_inputs[i]->addr, d);
        if (i > 0) {
            cluster_t* prev_cluster = hmap_get(trans_inputs[i - 1]->addr, d->hmap);
            cluster_t* curr_cluster = hmap_get(trans_inputs[i]->addr, d->hmap);
            snoc(prev_cluster, curr_cluster);
        }
    }
}

cluster_t* get_cluster(const char* addr, deanon_t* d)
{
    cluster_t* c = hmap_get(addr, d->hmap);
    while (c->prev) {
        c = c->prev;
    }
    return c;
}

cluster_t* cluster_new(const char* addr)
{
    cluster_t* cluster = malloc(sizeof(cluster_t));
    cluster->addr = strdup(addr);
    cluster->prev = NULL;
    cluster->next = NULL;
    return cluster;
} 

void cluster_free(cluster_t* c)
{   
    // Singleton cluster at every address, so we can free only the one and
    // still be sure we are freeing them all, looping through the hashmap
    free(c->addr);
    free(c);
}


// ===================================================================
// Add any other functions you need in order to implement deanon below
// ===================================================================


void cluster_print(cluster_t* c) {
    while (c) {
        printf("%s ", c->addr);
        c = c->next;
    }
    printf("\n");
}

cluster_t* traceback(cluster_t* c) {
    while (c->prev) {
        c = c->prev;
    }
    return c;
}

void snoc(cluster_t* c1, cluster_t* c2)
{
    cluster_t* curr_c1 = c1;
    while (curr_c1->next) {
        curr_c1 = curr_c1->next;  
    }  
    c1 = traceback(c1);
    c2 = traceback(c2);
    if (strcmp(c1->addr, c2->addr) != 0) {
        curr_c1->next = c2;
        c2->prev = curr_c1;
    }
}
