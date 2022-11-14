#include <stdio.h>
#include "funkcije.h"

int main(void) {
	int i, j;
	city gradovi[100];
	int broj;
	do {
		printf("Upisite broj gradova (od 3 do 100): ");
		scanf(" %d", &broj);
	} while (broj < 3|| broj > 100);
	printf("\n");
	for (i=0; i<broj; i++) {
		printf("Upisite postanski broj i koordinate %d. grada: ", (i+1));
		scanf(" %d %lf %lf", &gradovi[i].post, &gradovi[i].latitude, &gradovi[i].longitude);
	}
	printf("\nMedjusobne udaljenosti gradova:\n");
	for (i=0; i<broj-1; i++) {
		for (j=i+1; j<broj; j++) {
			printf("%d - %d: %.3f km\n", gradovi[i].post, gradovi[j].post, izracunajUdaljenost(stupnjeviURadijane(gradovi[i].latitude), stupnjeviURadijane(gradovi[i].longitude), stupnjeviURadijane(gradovi[j].latitude), stupnjeviURadijane(gradovi[j].longitude)));
		}
	}
	return 0;
}