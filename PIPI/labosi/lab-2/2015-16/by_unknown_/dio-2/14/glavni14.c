#include <stdio.h>
#include "funkcije14.h"
#define MAX 9

int main(void)
{
	char ulaz1[MAX + 1], ulaz2[MAX + 1];
	unsigned int prviBroj, drugiBroj, prekid = 0;

	gets(ulaz1);
	prviBroj = nizUInt(ulaz1);
	gets(ulaz2);
	drugiBroj = nizUInt(ulaz2);

	if (prviBroj == -1) {
		printf("Niz \"%s\" je neispravan.", ulaz1);
		prekid = 1;
	}
	if (drugiBroj == -1) {
		printf("Niz \"%s\" je neispravan.", ulaz2);
		prekid = 1;
	}
	else if (drugiBroj == 0) {
		printf("Nazivnik je nula.");
		prekid = 1;
	}
	if (prekid)
		printf("Prekidam.");

	else
		printf("%d : %d = %f", prviBroj, drugiBroj, dijeljenje(prviBroj, drugiBroj));

	return 0;
}