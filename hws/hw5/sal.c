/*
 * Yasoob Rasheed, yasoobr
 * CS152, Winter 2018
 * Homework 5
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sal.h"

/* Create a new empty list. */
sal *list_new() {
    sal* list = malloc(sizeof(sal));
    list->values = NULL;
    list->num_items = 0;
    return list;
}

/* Free the whole list, including all strings. */
void list_free(sal *list) {
    for (int i = 0; i < list->num_items; i++) {
        free(list->values[i]);
    }
    free(list->values);
    free(list);
}

/* Display a reasonable textual version of the list to f, with sep between strings. */
void list_show(FILE *f, sal *list, char sep) {
    if (!list) {
        fprintf(f, "NULL Value Returned\n");
        return;
    }
    fprintf(f, "Array List: \n");
    fprintf(f, "Number of Items: %zu\n%c ", list->num_items, sep);
    for (int i = 0; i < list->num_items; i++) {
        fprintf(f, "%s %c ", list->values[i], sep);
    }
    fprintf(f, "\n");
}

/* Add (duplicate of) string to position 0, shifting any existing items to the right. */
sal *add_to_front(sal *list, char *val) {
    // Allocate Space in Memory 
    char* value = strdup(val);
    list->num_items = list->num_items + 1;
    list->values = realloc(list->values, list->num_items * sizeof(char*));

    for (int i = list->num_items - 1; i > 0; i--) {
        list->values[i] = list->values[i - 1];
    }
    list->values[0] = value;

    return list;
}

/* Return the index of the first occurrence of the node containing the string, or -1. */
int find_first(sal *list, char *val) {
    for (int i = 0; i < list->num_items; i++) {
        if (strcmp(list->values[i], val) == 0) {
            return i;
        }
    }
    return -1;
}

/* Return a pointer to the first string in the list. Return NULL if there isn't one. */
char *get_first(sal *list) {
    if (list->values[0]) {
        return list->values[0];
    }
    return NULL;
}

/* Return a pointer to the last string in the list. Return NULL if there isn't one. */
char *get_last(sal *list) {
    if (list->values[list->num_items - 1]) {
        return list->values[list->num_items - 1];
    }
    return NULL;
}

/* Return a pointer to the string at the given index, starting at 0.
 * Return NULL if there isn't one.
 */
char *get_at_index(sal *list, size_t index) {
    if (list->values[index]) {
        return list->values[index];
    }
    return NULL;
}

/* Insert a pointer to a duplicate of new_val after the first 
 * occurrence of the sought_val, if sought_val occurs in the list;
 * otherwise return NULL.
 */
sal *insert_after(sal *list, char *sought_val, char *new_val) {
    for (int i = 0; i < list->num_items; i++) {
        if (strcmp(list->values[i], sought_val) == 0) {
            char* value = strdup(new_val);
            list->num_items = list->num_items + 1;
            list->values = realloc(list->values, list->num_items * sizeof(char*));

            for (int j = list->num_items - 1; j > i + 1; j--) {
                list->values[j] = list->values[j - 1];
            }
            list->values[i + 1] = value;
            return list;
        } 
    }
    return NULL;
}

/* Insert a pointer to a duplicate of new_val before the first 
 * occurrence of the sought_val, if sought_val occurs in the list;
 * otherwise return NULL.
 */
sal *insert_before(sal *list, char *sought_val, char *new_val) {
    for (int i = 0; i < list->num_items; i++) {
        if (strcmp(list->values[i], sought_val) == 0) {
            char* value = strdup(new_val);
            list->num_items = list->num_items + 1;
            list->values = realloc(list->values, list->num_items * sizeof(char*));

            for (int j = list->num_items - 1; j > i; j--) {
                list->values[j] = list->values[j - 1];
            }
            list->values[i] = value;
            return list;
        } 
    }
    return NULL;
}

/* Insert a pointer to a duplicate of new_val in the given position.
 * Return NULL if the list has no such position.
 */
sal *insert_at_index(sal *list, size_t index, char *new_val) { 
    if (list->values[index]) {
        char* value = strdup(new_val);
        list->num_items = list->num_items + 1;
        list->values = realloc(list->values, list->num_items * sizeof(char*));

        for (int j = list->num_items - 1; j > index; j--) {
            list->values[j] = list->values[j - 1];
        }
        list->values[index] = value;
        return list;
    }
    return NULL;
}


/* Remove the first pointer containing an occurrence of sought_val,
 * if one exists, freeing its string.  If there is no such occurrence, 
 * return NULL.
 */
sal *remove_first(sal *list, char *sought_val) {
    for (int i = 0; i < list->num_items; i++) {
        if (strcmp(list->values[i], sought_val) == 0) {
            free(list->values[i]);
            
            //Shift everything
            for (int j = i; j < list->num_items; j++) {
                list->values[j] = list->values[j + 1];
            }

            list->num_items = list->num_items - 1;
            list->values = realloc(list->values, list->num_items * sizeof(char*));
            return list;
        }
    }
    return NULL;
}

/* Remove occurrences of sought_val, freeing the strings. If there is 
 * no such occurrence, return NULL.
 */
sal *remove_all(sal *list, char *sought_val) {
    int count_occurrences = 0;
    for (int i = 0; i < list->num_items; i++) {
        if (strcmp(list->values[i], sought_val) == 0) {
            free(list->values[i]);
            
            //Shift everything
            for (int j = i; j < list->num_items; j++) {
                list->values[j] = list->values[j + 1];
            }

            list->num_items = list->num_items - 1;
            list->values = realloc(list->values, list->num_items * sizeof(char*));
            count_occurrences++;
        }
    }
    if (count_occurrences != 0) {
        return list;
    }
    return NULL;
}

/* Perform the given action on every item in the list.
 * Act on the strings in place; this should not build a new list.
 */
sal *act_on_strings(sal *list, void(*f)(char*)) {
    for (int i = 0; i < list->num_items; i++) {
        f(list->values[i]);
    }        
    return list;

}

/* Remove from the list and free every string that does not pass the test.
 * Do not allocate a new array list. 
 */
sal *filter(sal *list, int(*test)(char*)) {
    for (int i = 0; i < list->num_items; i++) {
        if (test(list->values[i]) == 0) {
            free(list->values[i]);

            for (int j = i; j < list->num_items; j++) {
                list->values[j] = list->values[j + 1];
            }

            list->num_items = list->num_items - 1;
            list->values = realloc(list->values, list->num_items * sizeof(char*));
        }
    }
    return list;
}
