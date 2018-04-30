/* Yasoob Rasheed, yasoobr
 * CS152, Winter 2018
 * Homework 1 
 */

#include <stdio.h>
#include "hw1.h"

/*
 * Checks if room exists in the building
 *
 * Inputs
 * num: (unsigned int) room number
 *
 * Variables
 * valid: (int) pseudo-boolean checking if the room exists in the building
 * floor: (int) gets the first one/two digits of the room number
 * room: (int) gets the last two digits of the room number
 *
 * Returns
 * Pseudo-boolean (int) if the room exists in the building
 */

int valid_room(unsigned int num) {
	
	int valid = 0;
	int floor = num / 100;
	int room = num % 100;
	
	if (floor < 49) {
		if (0 < room && room < 49) {
			valid = 1;
		}
	} else if (floor > 48) {
		if (11 < room && room < 25) {
			valid = 1;
		}
	}
	
	return valid;
}

/*
 * Checks how many pulses are in a give phone number (recursively)
 *
 * Inputs
 * phone_num: (unsigned long long int) integer representation of a phone number
 *
 * Variables
 * pulses: (int) number of pulses (10 if 0 in phone_num)
 *
 * Returns
 * Integer sum of all the pulses
 */

unsigned int rotary_pulses_r(unsigned long long int phone_num) {
	
	int pulses = phone_num % 10;

	if (phone_num == 0) {
		return pulses;
	}

	if (pulses == 0) {
		pulses = 10;
	}

	return pulses += rotary_pulses_r(phone_num / 10);
}

/*
 * Checks how many pulses are in a give phone number (iteratively)
 *
 * Inputs
 * phone_num: (unsigned long long int) integer representation of a phone number
 *
 * Variables
 * sum: (int) sum of all the pulses in phone_num
 * pulses: number of pulses (10 if 0 in phone_num)
 *
 * Returns
 * Integer sum of all the pulses
 */


unsigned int rotary_pulses_i(unsigned long long int phone_num) {
	
	int sum = 0;

	while (phone_num != 0) {
		int pulses = phone_num % 10;
		if (pulses == 0) {
			pulses = 10;
		}	
		sum += pulses;
		phone_num /= 10;
	}

	return sum;
}

/*
 * Gives the nth harmonic number
 *
 * Inputs
 * n: (unsigned int) upper bound of nth harmonic
 *
 * Variables
 * n_harm: (double) sum of each 1/n
 *
 * Returns
 * Integer sum of all harmonics
 */

double nth_harmonic(unsigned int n) {
	double n_harm = 0;

	if (n == 0) {
		return n_harm;
	}

	for (int i = 0; i < n; i++) {
		n_harm += (1.0 / (i + 1));
	} 

	return n_harm;
}

/*
 * Gives the number of harmonics greater than or equal to x
 * 
 * Inputs
 * x: (double) any number below a given threshold
 *
 * Variables
 * n: (unsigned int) holding the number of harmonics
 * n_harm: (double) holding the sum of the harmonics
 *
 * Returns
 * Integer number of harmonics
 */

unsigned int least_ge_harmonic(double x) {
	unsigned int n = 1;
	double n_harm = 0;

	while (n_harm < x) {
		n_harm += 1.0 / n;
		n++;
	}

	//must decrement 1 to remove the extra n++ in the last
	//call to the while loop
	n = n - 1;

	return n;
}

/*
 * Draws a sqxsq checkerboard with light and dark squares
 *
 * Inputs
 * side: (unsigned int) the dimensions of each square
 * sq: (unsigned int) the dimensions of the checkerboard
 * light: (char) contents of each light square
 * dark: (char) contents of each dark square
 *
 * Variables
 * curr_char: (int) the upper-left corner color
 * side_counter: (int) iterator for length of each square
 * counter: (int) iterator for width of each square
 *
 * Returns
 * Void: prints out the checkerboard to the console
 */

void checkerboard(unsigned int side, unsigned int sq, char light, char dark) {
	
	int curr_char = light;
	int side_counter = 0;
	int counter = 0;

	for (int i = 0; i < side * sq; i++) {
		for (int j = 0; j < side * sq; j++) {
			putchar(curr_char);
			counter++;	
			if (counter == side && curr_char == light) {
				curr_char = dark;
				counter = 0;
			} else if (counter == side && curr_char == dark) {
				curr_char = light;
				counter = 0;
			}			
		}
		printf("\n");
		side_counter++;
		if (side_counter == side && curr_char == light) {
				curr_char = dark;
				side_counter = 0;
			} else if (side_counter == side && curr_char == dark) {
				curr_char = light;
				side_counter = 0;
			}		
	}			
}
