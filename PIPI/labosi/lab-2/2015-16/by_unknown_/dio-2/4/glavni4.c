#include <stdio.h>
#include "funkcije4.h"
#define MAXNIZ 20

int main(void)
{
	char niz[MAXNIZ + 1];
	char genNiz[MAXNIZ + 1];
	int duljinaNiza;
	do {
		printf("Upisite niz: ");
		gets(niz);
	} while (!dobarNiz(niz));
	do {
		printf("Upisite duljinu niza: ");
		scanf("%d", &duljinaNiza);
	} while (duljinaNiza < 1 || duljinaNiza > 100);
	generirajNiz(niz, duljinaNiza, genNiz);
	printf("Ucitani niz: %s\n", niz);
	printf("Generirani niz: %s\n", genNiz);
	
	return 0;
}