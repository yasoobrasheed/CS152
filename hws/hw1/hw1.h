/*
 * Problem 1: 
 * Check if a room is exists in a given building
 */

int valid_room(unsigned int num);

/*
 * Problem 2: 
 * Determine the number of pulses needed to dial a rotary phone recursively
 * Determine the number of pulses needed to dial a rotary phone iteratively
 */

unsigned int rotary_pulses_r(unsigned long long int phone_num);
unsigned int rotary_pulses_i(unsigned long long int phone_num);

/*
 * Problem 3:
 * Find the nth harmonic given n (1/1 + 1/2 + ... + 1/n)
 * Find the least number of n harmonics that are geq to x
 */

double nth_harmonic(unsigned int n);
unsigned int least_ge_harmonic(double x);

/*
 * Problem 4:
 * Print a sqxsq checkerboard with sidexside light and dark squares
 */

void checkerboard(unsigned int side, unsigned int sq, char light, char dark);
