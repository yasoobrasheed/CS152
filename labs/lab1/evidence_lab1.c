
#include <stdio.h>
#include "lab1.h"

/* evidence_expt: test expt */
void evidence_expt()
{
	fprintf(stdout, "*** testing expt\n");
	fprintf(stdout, "- expecting 1: %ld\n", expt(2, 0));
	fprintf(stdout, "- expecting 8: %ld\n", expt(2, 3));
	/* more tests at your discretion */
}

/* evidence_expt: test ss */
void evidence_ss()
{
	fprintf(stdout, "*** testing ss\n");
	fprintf(stdout, "- expecting 1: %ld\n", expt(2, 0));
	fprintf(stdout, "- expecting 8: %ld\n", expt(2, 3));
	fprintf(stdout, "- expecting 64: %ld\n", expt(2, 6));
	fprintf(stdout, "- expecting 256: %ld\n", expt(2, 8));
	/* tests */
}

/* evidence_show_binary: test show_binary */
void evidence_show_binary()
{
	printf("*** testing show_binary\n");
	show_binary(0);
	printf("\n");
	show_binary(1);
	printf("\n");	
	show_binary(2);
	printf("\n");
	show_binary(8);
	printf("\n");
	show_binary(10);
	printf("\n");
	show_binary(111);
	printf("\n");
	/* tests */
}

/* main: run the evidence functions above */
int main()
{
	evidence_expt();
	evidence_ss();
	evidence_show_binary();
	return 0;
}
