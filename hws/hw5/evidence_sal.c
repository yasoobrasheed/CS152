/*
 * Yasoob Rasheed, yasoobr
 * CS152, Winter 2018
 * Homework 5
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sal.h"

sal* create_al() {
    sal* list = list_new();
    list = add_to_front(list, "FIRST_VAL");
    list = add_to_front(list, "NEXT_VAL");
    list = add_to_front(list, "THIRD_VAL");
    list = add_to_front(list, "NEXT_VAL");
    list = add_to_front(list, "FIFTH_VAL");
    list = add_to_front(list, "NEXT_VAL");
    list = add_to_front(list, "SEVENTH_VAL");
    return list;
}

int starts_with_n(char* value) {
    if (value[0] != 'N') {
        return 1;
    } else {
        return 0;
    }
} 

void change_to_foo(char* value) {
    free(value);
    value = malloc(strlen("FOO") + 1);
    strcpy(value, "FOO");
}

int main() {
    
    sal* list = create_al();
    list_show(stdout, list, '|');
   
    printf("Index of THIRD_VAL: %d\n", find_first(list, "THIRD_VAL"));
    printf("Index of CHEETOS: %d\n", find_first(list, "CHEETOS"));

    printf("First string in list: %s\n", get_first(list));
    printf("Last string in list: %s\n", get_last(list));

    printf("String index 0 in list: %s\n", get_at_index(list, 0));
    printf("String index 3 in list: %s\n", get_at_index(list, 3));

    printf("\n");
    list = insert_after(list, "FIRST_VAL", "AFTER_VAL");
    list_show(stdout, list, '|');
    list = insert_after(list, "EIGHTH_VAL", "AFTER_VAL");
    list_show(stdout, list, '|');
   
    printf("\n");
    list = create_al();
    list = insert_before(list, "FIRST_VAL", "BEFORE_VAL");
    list_show(stdout, list, '|');
    list = insert_before(list, "EIGHTH_VAL", "BEFORE_VAL");
    list_show(stdout, list, '|');

    printf("\n");
    list = create_al();
    list = insert_at_index(list, 0, "AT_VALUE");
    list_show(stdout, list, '|');
    list = insert_at_index(list, 12, "AT_VALUE");
    list_show(stdout, list, '|');

    printf("\n");
    list = create_al();
    list = remove_first(list, "FIFTH_VAL");
    list_show(stdout, list, '|');
    list = remove_first(list, "EIGHTH_VAL");
    list_show(stdout, list, '|');

    printf("\n");   
    list = create_al();
    list = remove_all(list, "NEXT_VAL");
    list_show(stdout, list, '|');
    list = remove_all(list, "POOP");
    list_show(stdout, list, '|');

    printf("\n");
    list = create_al();
    act_on_strings(list, change_to_foo);
    list_show(stdout, list, '|');
    
    printf("\n");
    list = create_al(); 
    list = filter(list, starts_with_n);
    list_show(stdout, list, '|');

    return 0;
}
