/*
 * Yasoob Rasheed, yasoobr
 * CS152, Winter 2018
 * Homework 4
 */

#include <stddef.h>
#include <stdio.h>

/* "sdll" is an abbreviation for string doubly-linked list. */

#ifndef SDLL_H
#define SDLL_H

typedef struct sdll_node {
  char *value;
  struct sdll_node *next;
  struct sdll_node *prev;
} node;

typedef struct sdll_container {
    node *first;
    node *last;
} sdll;

/* HELPER FUNCTION: 
 * Create a new node on the heap 
 *
 * Inputs:
 * v: (char*) string value of node
 * p: (node*) previous node
 * n: (node*) next node
 *
 * Returns:
 * (node*) new node struct
 */
node *node_new(char* v, node* p, node* n);

/* Create a new empty list 
 *
 * Returns:
 * (sdll*) new list with first and last nodes set to NULL
 */
sdll *list_new();

/* Free the whole list, including all strings and the container
 *
 * Inputs:
 * list: (sdll*) list of nodes
 *
 * Returns:
 * (void) frees the list from the heap
 */
void list_free(sdll *list);

/* Display a reasonable textual version of the node to f
 *
 * Inputs:
 * f: (FILE*) where to output textual version of node
 * nd: (node*) node to print
 *
 * Returns:
 * (void) string representation of node
 */
void node_show(FILE *f, node *nd);

/* Display a reasonable textual version of the list to f, with sep between nodes
 *
 * Inputs:
 * f: (FILE*) where to output textual version of list
 * nd: (sdll*) list to print
 *
 * Returns:
 * (void) string representation of node
 */
void list_show(FILE *f, sdll *list, char sep);

/* Return the first occurrence of the node containing the string, or NULL
 *
 * Inputs:
 * list: (sdll*) list of nodes
 * val: (val*) string value
 *
 * Returns:
 * (node*) node in list
 */
node *find_first(sdll *list, char *val);

/* Return the first node in the list
 *
 * Inputs:
 * list: (sdll*) list of nodes
 *
 * Returns:
 * (node*) node in list
 */
node *get_first(sdll *list);

/* Return the last node in the list
 *
 * Inputs:
 * list: (sdll*) list of nodes
 *
 * Returns:
 * (node*) node in list
 */
node *get_last(sdll *list);

/* Return a pointer to the next node, or NULL
 * Note: the list pointer need not be used in the implementation
 *
 * Inputs:
 * list: (sdll*) list of nodes
 * nd: (node*) node in list
 *
 * Returns:
 * (node*) node in list
 */
node *get_next(sdll *list, node *nd);

/* Return a pointer to the previous node, or NULL. 
 * Note: the list pointer need not be used in the implementation
 *
 * Inputs:
 * list: (sdll*) list of nodes
 * nd: (node*) node in list
 *
 * Returns:
 * (node*) node in list
 */
node *get_previous(sdll *list, node *nd);

/* Return a pointer to the node at the given index, starting at 0
 *
 * Inputs:
 * list: (sdll*) list of nodes
 * index: (size_t) numeric location to grab node
 *
 * Returns:
 * (node*) node in list
 */
node *get_at_index(sdll *list, size_t index);

/* Insert a new node pointing to a duplicate of new_val after the first 
 * occurrence of the sought_val, if sought_val occurs in the list;
 * otherwise return NULL
 *
 * Inputs:
 * list: (sdll*) list of nodes
 * sought_val: (char*) string to search for in list
 * new_val: (char*) string to set new node value to
 *
 * Returns:
 * (sdll*) list of nodes
 */
sdll *insert_after(sdll *list, char *sought_val, char *new_val);

/* Insert a new node pointing to a duplicate of new_val before the first 
 * occurrence of the sought_val, if sought_val occurs in the list;
 * otherwise return NULL
 *
 * Inputs:
 * list: (sdll*) list of nodes
 * sought_val: (char*) string to search for in list
 * new_val: (char*) string to set new node value to
 *
 * Returns:
 * (sdll*) list of nodes
 */
sdll *insert_before(sdll *list, char *sought_val, char *new_val);

/* Insert a new node pointing to a duplicate of new_val in the given position.
 * Return NULL if the list has no such position.
 *
 * Inputs:
 * list: (sdll*) list of nodes
 * index: (char*) numeric location to grab node
 * new_val: (char*) string to set new node value to
 *
 * Returns:
 * (sdll*) list of nodes
 */
sdll *insert_at_index(sdll *list, size_t index, char *new_val);

/* Remove the first node containing an occurrence of sought_val,
 * if one exists, freeing it and its string.  If there is no such occurrence, 
 * return NULL
 *
 * Inputs:
 * list: (sdll*) list of nodes
 * sought_val: (char*) string to search for in list
 *
 * Returns:
 * (sdll*) list of nodes
 */
sdll *remove_first(sdll *list, char *sought_val);

/* Remove all nodes containing an occurrence of sought_val,
 * if they exist, freeing them and their strings. If there is no such occurrence, 
 * return NULL.
 *
 * Inputs:
 * list: (sdll*) list of nodes
 * sought_val: (char*) string to search for in list
 *
 * Returns:
 * (sdll*) list of nodes
 */
sdll *remove_all(sdll *list, char *sought_val);

#endif
