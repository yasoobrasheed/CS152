/*
 * Yasoob Rasheed, yasoobr
 * CS152, Winter 2018
 * Homework 4
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sdll.h"

// Helper function: create a new node
node *node_new(char* v, node* p, node* n) {
    node* new_node = malloc(sizeof(node));
    char* val = strdup(v);
    new_node->value = val;
    new_node->prev = p;
    new_node->next = n;
    return new_node;
}

sdll *list_new() {
    sdll* list = malloc(sizeof(sdll));
    node* first = NULL;
    node* last = NULL;
    list->first = first;
    list->last = last;
    return list;
}

void list_free(sdll *list) {
    node* curr_node = list->first;
    while (curr_node) {
        node* next_node = curr_node->next;
        free(curr_node->value);
        free(curr_node);
        curr_node = next_node;    
    }
    free(list);
}

void node_show(FILE *f, node *nd) {
    if (nd) {
    fprintf(f, "Node Value: %s\n", nd->value);
        if (nd->prev) {
            fprintf(f, "Previous Node Value: %s\n", nd->prev->value);
        }
        if (nd->next) {
        fprintf(f, "Next Node Value: %s\n", nd->next->value);
        }
    } else {
        fprintf(f, "*NO NODE EXISTS HERE*\n");
    }
    fprintf(f, "----------------\n");
}

void list_show(FILE *f, sdll *list, char sep) {
    if (list == NULL) {
        fprintf(f, "*INSERT OPERATION RETURNED NULL* \n");
        return;
    }
    fprintf(f, "List Node Values: \n");
    fprintf(f, "----------------\n");
    node* curr_node = list->first;
    while (curr_node) {
        node_show(f, curr_node);
        curr_node = curr_node->next;
    }
}

node *find_first(sdll *list, char *val) {
    node* curr_node = list->first;
    while (curr_node) {
        if (strcmp(curr_node->value, val) == 0) {
            return curr_node;
        } else {
            curr_node = curr_node->next;
        }
    }
    return NULL;
}

node *get_first(sdll *list) {
    return list->first;
}

node *get_last(sdll *list) {
    return list->last;
}

node *get_next(sdll *list, node *nd) {
    return nd->next;
}

node *get_previous(sdll *list, node *nd) {
    return nd->prev;
}

node *get_at_index(sdll *list, size_t index) {
    int curr_index = 0;
    node* curr_node = list->first;
    while (curr_node) {
        if (curr_index == index) {
            return curr_node;
        } else {
            curr_node = curr_node->next;
            curr_index++;
        }
    }
    return NULL;
}

sdll *insert_after(sdll *list, char *sought_val, char *new_val) {
    node* curr_node = list->first;
    while (curr_node) {
        if  (strcmp(curr_node->value, sought_val) == 0) {
            node* new_node = malloc(sizeof(node));
            node* new_node_next = curr_node->next;
            curr_node->next = new_node;
            new_node->value = strdup(new_val);
            new_node->prev = curr_node;
            new_node->next = new_node_next;

            if (new_node_next) {
                new_node_next->prev = new_node;
            }
            if (curr_node == list->last) {
                list->last = new_node;
            }
            return list;
        } else {
            curr_node = curr_node->next;
        }
    }
    return NULL;
}

sdll *insert_before(sdll *list, char *sought_val, char *new_val) {
    node* curr_node = list->first;
    while (curr_node) {
        if (strcmp(curr_node->value, sought_val) == 0) {
            node* new_node = malloc(sizeof(node));
            node* new_node_prev = curr_node->prev;
            curr_node->prev = new_node;
            new_node->value = strdup(new_val);
            new_node->prev = new_node_prev;
            new_node->next = curr_node;

            if (new_node_prev) {
                new_node_prev->next = new_node;
            }
            if (curr_node == list->first) {
                list->first = new_node;
            }
            return list;
        } else {
            curr_node = curr_node->next;
        }
    }
    return NULL;
}

sdll *insert_at_index(sdll *list, size_t index, char *new_val) {
    node* curr_node = list->first;
    int curr_index = 0;
    while (curr_node) {
        if (curr_index == index) {
            node* new_node = malloc(sizeof(node));
            node* new_node_prev = curr_node->prev;
            curr_node->prev = new_node;
            new_node->value = strdup(new_val);
            new_node->prev = new_node_prev;
            new_node->next = curr_node;

            if (new_node_prev) {
                new_node_prev->next = new_node;
            }
            if (curr_index == 0) {
                list->first = new_node;
            }
            return list;
        } else {
            curr_index++;
            curr_node = curr_node->next;
        }
    }
    return NULL;
}

sdll *remove_first(sdll *list, char *sought_val) {
    node* curr_node = list->first;
    while (curr_node) {
        if (strcmp(curr_node->value, sought_val) == 0) {
            node* next_node = curr_node->next;
            node* prev_node = curr_node->prev;

            if (prev_node && next_node) {
                prev_node->next = next_node;
                next_node->prev = prev_node;
            } else if (!prev_node && next_node) {
                next_node->prev = prev_node;
            } else if (prev_node && !next_node) {
                prev_node->next = next_node;
            }

            if (curr_node == list->first) {
                list->first = next_node;
            } else if (curr_node == list->last) {
                list->last = prev_node;
            }
            free(curr_node->value);
            free(curr_node);
            return list;
        } else {
            curr_node = curr_node->next;
        }
    }
    return NULL;
}

sdll *remove_all(sdll *list, char *sought_val) {
    node* curr_node = list->first;
    int count_occurrences = 0;
    while (curr_node) {
        if (strcmp(curr_node->value, sought_val) == 0) {
            node* next_node = curr_node->next;
            node* prev_node = curr_node->prev;
            
            if (prev_node && next_node) {
                prev_node->next = next_node;
                next_node->prev = prev_node;
            } else if (!prev_node && next_node) {
                next_node->prev = prev_node;
            } else if (prev_node && !next_node) {
                prev_node->next = next_node;
            }

            if (curr_node == list->first) {
                list->first = next_node;
            } else if (curr_node == list->last) {
                list->last = prev_node;
            }

            free(curr_node->value);
            free(curr_node);
            curr_node = next_node;
            count_occurrences++;
        } else {
            curr_node = curr_node->next;
        }
    }
    if (count_occurrences) {
        return list;
    }
    return NULL;
}
