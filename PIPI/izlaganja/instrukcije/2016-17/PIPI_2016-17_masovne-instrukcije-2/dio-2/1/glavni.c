#include "funkcije.h"
#include <stdio.h>

int main(void) {
	int c, i, j;
	int pbr[100];
	double lat[100];
	double lng[100];
	double d;
	
	do {
		printf("Upisite broj gradova [3, 100]: ");
		scanf("%d", &c);
	} while(c < 3 || c > 100);
	
	for (i = 0; i < c; i++) {
		printf("Upisite postanski broj i koordinate %d. grada:", i + 1);
		scanf("%d %lf %lf", &pbr[i], &lat[i], &lng[i]);
	}
	
	puts("Udaljenosti gradova: ");
	
	for (i = 0; i < c; i++) {
		for(j = i + 1; j < c; j++) {
			d = izracunajudaljenost(stupnjeviuradijane(lat[i]), stupnjeviuradijane(lat[j]),
									stupnjeviuradijane(lng[i]), stupnjeviuradijane(lng[j]));
			printf("%d - %d: %.3lf km\n", pbr[i], pbr[j], d);
		}
	}
	

	return 0;
}
