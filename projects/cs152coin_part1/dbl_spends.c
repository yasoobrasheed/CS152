#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dbl_spends.h"


dbl_spends_t* dbl_spends_new()
{
    dbl_spends_t* ds = malloc(sizeof(dbl_spends_t));
    ds->id = NULL;
    ds->addr = NULL;
    return ds;
}

void dbl_spends_free(dbl_spends_t* ds)
{   
    dbl_spends_t* curr_ds = ds;
    while (curr_ds) {
        dbl_spends_t* next_ds = ds->next;
        free((char*)ds->id);
        free((char*)ds->addr);
        free(ds);
        curr_ds = next_ds;
    }
}

void add_dbl_spend(const char* trans_id, const char* addr, dbl_spends_t* ds)
{  
    if (!ds->id) {
        ds->id = trans_id;
        ds->addr = addr;
        return;
    }
    dbl_spends_t* new_ds = dbl_spends_new();
    new_ds->id = trans_id;
    new_ds->addr = addr;
    ds->next = new_ds;
}

void dbl_spends_show(dbl_spends_t* ds, FILE* f)
{
    while (ds) {
        fprintf(f, "%s, %s\n", ds->id, ds->addr);
        ds = ds->next;
    }
}

// =======================================================================
// Add any other functions you need in order to implement dbl_spends below
// =======================================================================
