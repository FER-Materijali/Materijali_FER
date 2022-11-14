#include <stdio.h>
#include "funkcije7.h"
#define MAXLEN 100

int main(void)
{
	char ulaz[MAXLEN + 1], izlaz[MAXLEN + 1];
	int kljuc;
	do {
		printf("Upisi niz: ");
		gets(ulaz);
	} while (brojNeSlova(ulaz));
	do {
		printf("Upisi kljuc kriptiranja: ");
		scanf("%d", &kljuc);
	} while (kljuc < 1 || kljuc > 25);

	caesarEncrypt(ulaz, izlaz, kljuc);

	printf("Kriptiran niz: %s\n", izlaz);
	printf("Originalni niz: %s\n", ulaz);
	
	return 0;
}