/*
 * Yasoob Rasheed, yasoobr
 * CS152, Winter 2018
 * Homework 2
 */

/*
 * Simulates the exclusive or operation on two integers
 * 
 * Inputs:
 * b1: (int) first integer
 * b2: (int) second integer
 *
 * Returns:
 * (int) pseudo-boolean representing true (1>=) or false (0)
 */
int xor(int b1, int b2);

/*
 * Prints the array to the console
 *
 * Inputs:
 * *a: (int) dereferenced array a
 * len: (unsigned int) length of array a
 *
 * Returns:
 * (void) prints array elements to console
 */
void show_array(int *a, unsigned int len);

/*
 * Adds n to all the elements in an array a
 *
 * Inputs:
 * n: (int) number to be added to each element in a
 * *a: (int) dereferenced array a
 * len: (unsigned int) length of array a
 *
 * Returns:
 * (void) updates the values of a
 */
void add_to_all(int n, int *a, unsigned int len);

/*
 * Counts the occurences of n in a
 *
 * Inputs:
 * n: (int) specific element we want to track
 * *a: (int) dereferenced array a
 * len: (unsigned int) length of array a
 *
 * Returns:
 * (int) number of times n shows up in a
 */
int occurrences_of(int n, int *a, unsigned int len);

/*
 * Checks if there are any odd numbers in a
 *
 * Inputs:
 * *a: (int) dereferenced array a
 * len: (unsigned int) length of array a
 *
 * Returns:
 * (int) pseudo-boolean "true" if one is odd, "false" is all are even
 */
int any_odd(int *a, unsigned int len);

/*
 * Reverse the elements in an array
 *
 * Inputs:
 * *a: (int) dereferenced array a
 * len: (unsigned int) length of array a
 *
 * Returns:
 * (void) switches the elements of array a in place
 */
void reverse(int *a, unsigned int len);

/*
 * Finds the minimum element of array a
 *
 * Inputs:
 * *a: (int) dereferenced array a
 * len: (unsigned int) length of array a
 *
 * Returns:
 * (int) returns minimum number of array a
 */
int min(int *a, unsigned int len);

/*
 * Finds the maximum element of array a
 *
 * Inputs:
 * *a: (int) dereferenced array a
 * len: (unsigned int) length of array a
 *
 * Returns:
 * (int) returns maximum number of array a
 */
int max(int *a, unsigned int len);

/*
 * Checks if array a1 and array a2 are equal
 *
 * Inputs:
 * *a1: (int) dereferenced array a1
 * len1: (unsigned int) length of array a1
 * *a2: (int) dereferenced array a2
 * len2: (unsigned int) length of array a2
 *
 * Returns:
 * (int) returns pseudo-boolean, 0 if they are not equal and 1 if they are
 */
int equal(int *a1, unsigned int len1, int *a2, unsigned int len2);

/*
 * Turns an integer into a binary number
 *
 * Inputs:
 * n: (unsigned in) number
 *
 * Returns:
 * (void) prints binary number to console
 */
void int_binary(unsigned int n);

/*
 * Turns an integer into a quaternary number
 *
 * Inputs:
 * n: (unsigned in) number
 *
 * Returns:
 * (void) prints quaternary number to console
 */
void int_quaternary(unsigned int n);
