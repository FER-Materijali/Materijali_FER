#include <stdio.h>
#include "funkcije.h"

int main(void) {
	char niz1[10] = {0};
	int n1;
	char niz2[10] = {0};
	int n2;
	int greska = 0;
	
	printf("Upisite dva broja: ");
	scanf(" %s %s", niz1, niz2);
	
	n1 = string_to_int(niz1);
	n2 = string_to_int(niz2);
	
	if (n1 == -1) {
		greska = 1;
		printf("Niz \"%s\" je neispravan. ", niz1);
	}
	
	if (n2 == -1) {
		greska = 1;
		printf("Niz \"%s\" je neispravan. ", niz2);
	} else if (n2 == 0) {
		greska = 1;
		printf("Nazivnik je nula. ");
	}
	
	if (greska == 1) printf("Prekidam.\n");
	else {
		printf("%d : %d = %.6f\n", n1, n2, division(n1, n2));
	}
	
	return 0;
}