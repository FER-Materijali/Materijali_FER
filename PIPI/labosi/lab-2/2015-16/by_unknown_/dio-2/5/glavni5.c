#include <stdio.h>
#include "funkcije5.h"
#define MAXNIZ 200

int main(void)
{
	char niz[MAXNIZ + 1];
	int broj;
	gets(niz);
	broj = brojRecenica(niz);
	if (broj) {
		printf("Broj recenica u tekstu:\n'%s'\n je %d.\n", niz, broj);
	}
	else
		printf("Tekst\n'%s'\nne sadri niti jednu potpunu recenicu.\n", niz);
	return 0;
}