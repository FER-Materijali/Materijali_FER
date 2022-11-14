#include <stdio.h>
#include "funkcije.h"

int main(void) {
	char niz[1024+1] = {0};
	int broj_rijeci = 0;
	scanf(" %1024[^\n]", niz);
	broj_rijeci = brRijeci(niz);
	if (broj_rijeci != -1) {
		printf("Broj rijeci u zadanom tekstu: %d\n\n", broj_rijeci);
		if (izbaciBrojeve(niz)) {
			printf("Promijenjen tekst:\n%s\nBroj rijeci poslije promjene je: %d", niz, brRijeci(niz));
		}
	}
	else printf("Neispravan niz!\n");
	return 0;
}