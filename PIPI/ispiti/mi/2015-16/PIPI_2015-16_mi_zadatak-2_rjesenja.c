#include <stdio.h>
#define D_GR 10000
#define G_GR 11000
#define MAX_UPLATA_PO_RACUNU 3
int main (void) {
	int brojUplataNaRacun[G_GR - D_GR + 1] = {0};
	float sumaUplataNaRacunu[G_GR - D_GR + 1] = {0.f};
	int brRac;
	float iznos, najvecaSuma;
	printf("Upisujte uplate (br.racuna i iznos):\n");
	/* ucitavati dok broj uplata na nekom racunu ne dosegne maksimum */
	do {
		scanf("%d %f", &brRac, &iznos);
		++brojUplataNaRacun[brRac - D_GR];
		sumaUplataNaRacunu[brRac - D_GR] += iznos;
	} while (brojUplataNaRacun[brRac - D_GR] < MAX_UPLATA_PO_RACUNU);
	/* odrediti najvecu sumu na racunima */
	najvecaSuma = sumaUplataNaRacunu[0];
	for (brRac = D_GR+1; brRac <= G_GR; ++brRac) {
		if (najvecaSuma < sumaUplataNaRacunu[brRac - D_GR]) {
			najvecaSuma = sumaUplataNaRacunu[brRac - D_GR];
		}
	}
 /* ispisati sve racune kojima je suma jednaka najvecoj sumi */
	printf("Najveca suma uplata je %8.2f\n", najvecaSuma);
	printf("Brojevi racuna s tim iznosom su:\n");
	for (brRac = D_GR; brRac <= G_GR; ++brRac) {
		if (sumaUplataNaRacunu[brRac - D_GR] == najvecaSuma) {
			printf(" %5d\n", brRac);
		}
	}
	return 0;
}