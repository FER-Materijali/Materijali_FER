#include <stdio.h>
#include "funkcije6.h"
#define MAXTEXT 1024

int main(void)
{
	char recenica[MAXTEXT];
	int brojRijeci, promjena;
	gets(recenica);
	brojRijeci = brRijeci(recenica);

	if (brojRijeci == -1)
		printf("Zadani tekst je neispravan.\n");
	else
		printf("Broj rijeci u zadanom tekstu: %d\n", brojRijeci);

	promjena = izbaciBrojeve(recenica);

	if (promjena)
		printf("Promijenjen tekst:\n%s\n", recenica);

	return 0;
}