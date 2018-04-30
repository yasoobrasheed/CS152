#include <stdio.h>
#include "hw1.h"


void is_valid_room(room) {
	if (valid_room(room)) {
		printf("%d is a valid room\n", room);
	} else {
		printf("%d is not a valid room\n", room);
	}
}

void rotary_r() {
	printf("Recursive pulses for 7737021234: ");
	printf("%d\n", rotary_pulses_r(7737021234));

	printf("Recursive pulses for 1111111111: ");
	printf("%d\n", rotary_pulses_r(1111111111));

	printf("Recursive pulses for 1000000000: ");
	printf("%d\n", rotary_pulses_r(1000000000));
}

void rotary_i() {
	printf("Iterative pulses for 7737021234: ");
	printf("%d\n", rotary_pulses_i(7737021234));

	printf("Iterative pulses for 1111111111: ");
	printf("%d\n", rotary_pulses_i(1111111111));

	printf("Iterative pulses for 1000000000: ");
	printf("%d\n", rotary_pulses_i(1000000000));
}

void call_harmonic() {
	printf("0th harmonic is: %f\n", nth_harmonic(0));
	printf("2th harmonic is: %f\n", nth_harmonic(2));
	printf("5th harmonic is: %f\n", nth_harmonic(5));
}

void call_least_harmonic() {
	printf("Least harmonic >= 1: %d\n", least_ge_harmonic(1));
	printf("Least harmonic >= 2: %d\n", least_ge_harmonic(2));
	printf("Least harmonic >= 2.1: %d\n", least_ge_harmonic(2.1));
}

void print_checkerboards() {
	printf("\n");
	checkerboard(3, 4, 'X', '-');
	printf("\n");

	printf("\n");
	checkerboard(2, 2, '-', 'X');
	printf("\n");

	printf("\n");
	checkerboard(10, 8, 'O', 'I');
	printf("\n");
}

int main() {
	is_valid_room(2000);
	is_valid_room(103);
	is_valid_room(158);
	rotary_r();
	rotary_i();
	least_ge_harmonic(2);
	call_harmonic();
	call_least_harmonic();
	print_checkerboards();
	return 0;
}
