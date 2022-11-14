#include <stdio.h>

int main (void) {
	/*S tipkovnice uzastopno učitavati cijele brojeve iz zatvorenog intervala
	[1, 30] (pojedini broj je potrebno učitavati sve dok se ne unese ispravna
	vrijednost). Učitavanje brojeva završiti kada se učita broj koji je već 
	prije bio učitan.Znači da nam sigurno treba 30 mjesta jer više ne može 
	ni biti učitano. */
	int upis [30], j, i;
	for (i = 0; i < 30; ++i) {
		do {
			printf("unesi član: ");
			scanf("%d", &upis[i]);
		} while ((upis[i] < 1) || (upis[i] > 30));
	/* ovo nije najsretnije rješenje, moglo se isto tako tražiti broj i 
	nakon provjere zadovoljava li on naše kriteriji ubacivati ga u polje.*/
		for (j=0; j<i; j++) {
			/* provjeri sve brojeve koji su prethodili upisanome, možda se
			neki od njih ponovio. */
			if (upis[i] == upis[j]) {
				printf("Broj %d bio je %d. učitani broj.\n", upis[i], j+1);
				printf("Ukupno učitano brojeva: %d\n", i+1);
				return 0;
			}
		}
	}
}
