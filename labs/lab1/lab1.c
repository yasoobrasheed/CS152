/*  Yasoob Rasheed, yasoobr
 *  CS152, Winter 2018
 *  Lab 1 
 */

#include <stdio.h>
#include "lab1.h"

/* expt : linear time recursive exponentiation */
long int expt(int a, unsigned int n) 
{
	if (n == 0) {
		return 1;
	} else {
		return a * expt(a, n - 1);
	}
}

/* ss : exponentiation by successive squaring */
long int ss(int a, unsigned int n)
{
	if (n > 0 && n % 2 == 0) {
		return ss(a * a, n / 2);
	} else if (n > 0 && n % 2 == 1) {
		return a * ss(a, n - 1); 
	} else {
		return 1;
	}
}

/* show_binary: present the bit representation of an unsigned long integer */
void show_binary(unsigned long int n)
{	
	if (n == 0) {
		putchar('0');
	} else if (n == 1) {
		putchar('1');
	} else {
		show_binary(n / 2);
		
		if (n % 2 == 0) {
			putchar('0');
		} else {
			putchar('1');
		}
	}
}
