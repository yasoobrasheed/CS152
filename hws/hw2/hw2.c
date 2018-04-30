
/*
 * Yasoob Rasheed, yasoobr
 * CS152, Winter 2018
 * Homework 2
 */

#include <stdio.h>
#include <stdlib.h>
#include "hw2.h"

int xor(int b1, int b2) 
{
    if (b1 == 0 && b2 == 0) {
        return 0;
    } else if (b1 == 0 || b2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

void show_array(int *a, unsigned int len) 
{
    for (int i = 0; i < len; i++) {
        printf("a[%d] %d\n", i, a[i]);
    }
}

void add_to_all(int n, int *a, unsigned int len) 
{
    for (int i = 0; i < len; i++) {
        a[i] += n;
    }
}

int occurrences_of(int n, int *a, unsigned int len) 
{
    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == n) {
            counter++;
        }
    }
    return counter;
}

int any_odd(int *a, unsigned int len) 
{
    for (int i = 0; i < len; i++) {
        if (a[i] % 2 == 1) {
            return 1;
        }
    }
    return 0;
}

void reverse(int *a, unsigned int len) 
{
    for (int i = 0; i < len / 2; i++) {
        int temp = a[i];
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = temp;
    }
}

int min(int *a, unsigned int len) 
{
    if (len == 0) {
        fprintf(stderr, "min: given 0-length array\n");
        exit(1);
    }
    int min = a[0];
    for (int i = 0; i < len; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int max(int *a, unsigned int len) 
{
    if (len == 0) {
        fprintf(stderr, "max: given 0-length array\n");
        exit(1);
    }
    int max = a[0];
    for (int i = 0; i < len; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int equal(int *a1, unsigned int len1, int *a2, unsigned int len2) 
{
    if (len1 != len2) {
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (a1[i] != a2[i]) {
            return 0;
        }
    }
    return 1;
}

void int_binary(unsigned int n) 
{
    int bin[32] = { 0 };
    int BIN_LENGTH = 32;
    int index = 0;

    while (n > 1) {
        bin[index] = n % 2;
        n /= 2;
        index++;
    }
    bin[index] = n;
    
    reverse(bin, BIN_LENGTH);
    for (int i = 0; i < BIN_LENGTH; i++) {
        if (i != 0 && i % 4 == 0) {
            printf(" ");
        }
        printf("%d", bin[i]);
    } 
    printf("\n");
}

void int_quaternary(unsigned int n) 
{
    int quat[16] = { 0 };
    int QUAT_LENGTH = 16;
    int index = 0;

    while (n > 3) {
        quat[index] = n % 4;
        n /= 4;
        index++;
    }
    quat[index] = n;

    reverse(quat, QUAT_LENGTH);
    for (int i = 0; i < QUAT_LENGTH; i++) {
        if (i != 0 && i % 4 == 0) {
            printf(" ");
        }
        printf("%d", quat[i]);
    } 
    printf("\n");
} 
