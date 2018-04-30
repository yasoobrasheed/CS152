#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_bst_todo_format = "TODO [bst]: %s\nhalting\n";

bst* bst_singleton(vcard* vc)
{
    bst* b = malloc(sizeof(bst));
    b->vc = vc;
    b->lsub = b->rsub = NULL;
    return b;
}

int bst_insert(bst* t, vcard* vc)
{
    if (t == NULL) {
        fprintf(stderr, "Empty BST");
        exit(1);
    }

    int order = strcmp(vc->cnet, t->vc->cnet);

    if (order < 0) {
        if (t->lsub == NULL) {
            t->lsub = bst_singleton(vc);
            return 1;
        } else {
            bst_insert(t->lsub, vc);
        }
    } else if (order > 0) {
        if (t->rsub == NULL) {
            t->rsub = bst_singleton(vc);
            return 1;
        } else {
            bst_insert(t->rsub, vc);
        }
    } else {
        return 0;
    }
}

unsigned int bst_num_entries(bst* t)
{
    if (t == NULL) {
        return 0;
    }
    return bst_num_entries(t->lsub) + 1 + bst_num_entries(t->rsub);
}

unsigned int bst_height(bst* t)
{
    if (t == NULL) {
        return 0;
    } 
    int l = 1 + bst_height(t->lsub);
    int r = 1 + bst_height(t->rsub);
    if (l > r) {
        return l;
    } else if (l < r) {
        return r;
    }
}

vcard* bst_search(bst* t, const char* cnet, int* n_comparisons)
{
    if (t == NULL) {
        return NULL;
    }

    int order = strcmp(cnet, t->vc->cnet);

    if (order < 0) {
        *n_comparisons += 1;
        return bst_search(t->lsub, cnet, n_comparisons);
    } else if (order > 0) {
        *n_comparisons += 1;
        return bst_search(t->rsub, cnet, n_comparisons);
    } 
    *n_comparisons += 1;
    return t->vc;
}

unsigned int bst_prefix_show(FILE* f, bst* t, const char* prefix)
{
    if (t != NULL) {
        int order = strncmp(prefix, t->vc->cnet, strlen(prefix));

        if (order < 0) {
            bst_prefix_show(f, t->lsub, prefix);
        } else if (order > 0) {
            bst_prefix_show(f, t->rsub, prefix);
        } else {
            bst_prefix_show(f, t->lsub, prefix);
            vcard_show(f, t->vc);
            bst_prefix_show(f, t->rsub, prefix);
            return 1;
        }
    }
    return 0;
}

void bst_free(bst* t)
{
    if (t != NULL) {
        bst_free(t->lsub);
        bst_free(t->rsub);
        vcard_free(t->vc);
        free(t);
    }
}
