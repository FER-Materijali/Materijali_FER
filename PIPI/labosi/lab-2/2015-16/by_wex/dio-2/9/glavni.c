#include <stdio.h>
#include <string.h>
#include "funkcije.h"

int main(void) {
	char podniz[6] = {0};
	char niz1[301] = {0};
	char niz2[301] = {0};
	int duljina;
	int br_podnizova = 0;
	int br_sadrzanih = 0;
	int i;
	
	printf("Prvi niz: ");
	scanf(" %300[^\n]", niz1);
	printf("Drugi niz: ");
	scanf(" %300[^\n]", niz2);
	printf("\n");
	
	do {
		printf("Duljina podniza za usporedbu nizova: ");
		scanf(" %d", &duljina);
	} while (duljina < 2 || duljina > 5 || duljina > strlen(niz1) || duljina > strlen(niz2));
	
	br_podnizova = strlen(niz1) - duljina + 1;
	
	for (i=0; i<br_podnizova; i++) {
		gen(niz1, podniz, i, duljina);
		if (sadrzi(niz2, podniz)) br_sadrzanih++;
	}
	
	printf("\nSlicnost nizova '%s' i '%s' iznosi %.6f", niz1, niz2, (float)br_sadrzanih/(float)br_podnizova);
	
	return 0;
}