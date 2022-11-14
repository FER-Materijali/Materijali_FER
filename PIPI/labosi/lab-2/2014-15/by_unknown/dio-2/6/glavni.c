#include<stdio.h>
#include"funkcije.h"
int main (void) {
	char tekst[1025];
	int rijeci;
	gets(tekst);
	rijeci=brRijeci(tekst);
	if (rijeci>=0) {
		printf("\nBroj rijeci u zadanom tekstu: %d\n", rijeci);
		if (izbaciBrojeve(tekst)) {
			printf("\nPromijenjen tekst:\n%s\n", tekst);
			rijeci=brRijeci(tekst);
			printf("Broj rijeci poslije promjene je: %d\n", rijeci);
		}
	} else {
		printf("Zadani tekst je neispravan.\n");
	}
	return 0;
}