
#include <stdio.h>
#include "hw2.h"

void test_xor(int first, int second) 
{
    printf("Exclusive-Or with %d and %d:\n", first, second);
    int x_or = xor(first, second);
    if (x_or) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

int a[] = {-1, 0, 1, 1, 1, 2, 3, 5, 8};
int b[] = {-2, 0, 2, 4, 6, 8};
unsigned int len_a = sizeof(a)/sizeof(a[0]);
unsigned int len_b = sizeof(b)/sizeof(b[0]);

void test_any_odd(int *list, int len_list) 
{
    printf("Any odd in this array?\n");
    int any_odds = any_odd(list, len_list);
    if (any_odds) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

int main() 
{    
    test_xor(1, 0);
    test_xor(0, 1);
    test_xor(0, 0);
    test_xor(1, 1);
    printf("\n");
    show_array(a, len_a);
    printf("\n");
    add_to_all(1, a, len_a);
    show_array(a, len_a);
    printf("\n");
    printf("Occurrences of 1: %d\n", occurrences_of(1, a, len_a));
    printf("Occurrences of 5: %d\n", occurrences_of(5, a, len_a));
    printf("Occurrences of 10: %d\n", occurrences_of(10, a, len_a));
    printf("\n");
    test_any_odd(a, len_a);
    test_any_odd(b, len_b);
    printf("\n");
    reverse(a, len_a);
    show_array(a, len_a);
    printf("\n");
    reverse(b, len_b);
    show_array(b, len_b);
    printf("\n");
    printf("Minimum of array a: %d\n", min(a, len_a));
    printf("Maximum of array b: %d\n", max(b, len_b));
    printf("Are arrays a and b equal?: %d\n", equal(a, len_a, b, len_b));
    printf("Are arrays a and a equal?: %d\n", equal(a, len_a, a, len_a));
    printf("Binary for 1,327,805: ");
    int_binary(1327805);
    printf("Quaternary for 23,875,682: ");
    int_quaternary(23875682);
    return 0;
}
