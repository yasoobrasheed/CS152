/*
 * Yasoob Rasheed, yasoobr
 * CS152, Winter 2018
 * Homework 4
 */

#include <stdio.h>
#include <stdlib.h>
#include "sdll.h"

sdll* build_list() {
    sdll* new_list = list_new();

    node* node_1 = node_new("APPLE", NULL, NULL);
    node* node_2 = node_new("APPLE", node_1, NULL);
    node* node_3 = node_new("PEAR", node_2, NULL);
    node* node_4 = node_new("POMELO", node_3, NULL);
    node* node_5 = node_new("PEAR", node_4, NULL);
    node* node_6 = node_new("HONEYDEW", node_5, NULL);

    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;
    node_5->next = node_6;

    new_list->first = node_1;
    new_list->last = node_6;

    return new_list;
}

int main() {
    sdll* empty_list = list_new();
    list_show(stdout, empty_list, '-');
    sdll* l = build_list();
    list_show(stdout, l, '-');
    
    printf("\n\n");
    
    printf("***First occurrence of POMELO***\n");
    node_show(stdout, find_first(l, "POMELO"));
    printf("***First occurrence of PEAR***\n");
    node_show(stdout, find_first(l, "PEAR"));
    printf("***FAILSAFE: First occurrence of CHEETOS***\n");
    node_show(stdout, find_first(l, "CHEETOS"));
    
    printf("\n\n");
    
    printf("***First node in the list***\n");
    node* n_first = get_first(l);
    node_show(stdout, n_first);
    printf("***Last node in the list***\n");
    node* n_last = get_last(l);
    node_show(stdout, n_last);
    
    printf("\n\n");

    printf("***Get next to first node in the list***\n");
    node_show(stdout, get_next(l, n_first));
    printf("***Get prev to last node in the list***\n");
    node_show(stdout, get_previous(l, n_last));
    printf("***FAILSAFE: Get prev to first node in the list***\n");
    node_show(stdout, get_previous(l, n_first));
    printf("***FAILSAFE: Get next to last node in the list***\n");
    node_show(stdout, get_next(l, n_last));
    
    printf("\n\n");
    
    printf("***Get at index 0***\n");
    node_show(stdout, get_at_index(l, 0));
    printf("***Get at index 4***\n");
    node_show(stdout, get_at_index(l, 4));
    printf("***FAILSAFE: Get at index 15***\n");
    node_show(stdout, get_at_index(l, 15));
    
    printf("\n\n");
    
    printf("***Insert GRAPE after first HONEYDEW***\n");
    list_show(stdout, insert_after(l, "HONEYDEW", "GRAPE"), '-');
    printf("***Insert GRAPE after first APPLE***\n");
    list_show(stdout, insert_after(l, "APPLE", "GRAPE"), '-');
    printf("***FAILSAFE: Insert BLACKBERRY after BLUEBERRY***\n");
    list_show(stdout, insert_after(l, "BLACKBERRY", "BLUEBERRY"), '-');

    printf("\n\n");
    
    printf("***Insert TOMATO before first APPLE***\n");
    list_show(stdout, insert_before(l, "APPLE", "TOMATO"), '-');
    printf("***Insert TOMATO before HONEYDEW (last index)***\n");
    list_show(stdout, insert_before(l, "HONEYDEW", "TOMATO"), '-');
    printf("***FAILSAFE: Insert TOMATO before BLUEBERRY***\n");
    list_show(stdout, insert_before(l, "BLUEBERRY", "TOMATO"), '-');
    
    printf("\n\n");
    
    printf("***Insert CHERRY at index 0***\n");
    list_show(stdout, insert_at_index(l, 0, "CHERRY"), '-');
    printf("***Insert CHERRY at index 5 ***\n");
    list_show(stdout, insert_at_index(l, 5, "CHERRY"), '-');
    printf("***FAILSAFE: Insert CHERRY at index 15***\n");
    list_show(stdout, insert_at_index(l, 15, "CHERRY"), '-');
    
    printf("\n\n");
 
    printf("***Remove first CHERRY (first element)***\n");
    list_show(stdout, remove_first(l, "CHERRY"), '-');
    printf("***Remove first PEAR***\n");
    list_show(stdout, remove_first(l, "PEAR"), '-');
    printf("***FAILSAFE: Remove first DORITO***\n");
    list_show(stdout, remove_first(l, "DORITO"), '-');

    printf("\n\n");
      
    printf("***Remove all instances of APPLE***\n");
    list_show(stdout, remove_all(l, "APPLE"), '-');
    printf("***FAILSAFE: Remove all instances of DORITO***\n");
    list_show(stdout, remove_all(l, "DORITO"), '-');

    list_free(l);
    return 0;
}
