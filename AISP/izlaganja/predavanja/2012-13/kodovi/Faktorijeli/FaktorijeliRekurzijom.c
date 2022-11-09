// FaktorijeliRekurzijom.c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
long fakt (int n) {
	long nfakt;
	if (n <= 1) {	// 0! = 1! = 1
		nfakt = 1;
	} else {			// n! = n* (n-1)!
		nfakt = n * fakt(n-1);
		if (nfakt < 0 ) {
			printf ("\nNe moze se izracunati %d! kao long (nfakt=%ld)\n", n, nfakt);
			(void) getch();
			exit (1);
		}
	}
	return nfakt;
}

int main (void) {
	int n;
	while (1) {
		printf ("\nUpisite n>"); // primjeri: n=15,16,17...
		scanf ("%d", &n);
		printf ("%d! = %ld",n, fakt (n));
	}
	return 0;
}