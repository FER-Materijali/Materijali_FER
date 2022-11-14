#include <stdio.h>
#include "funkcije.h"

int main(void) {
	char ulaz[101] = {0};
	char izlaz[101] = {0};
	int kljuc;
	do {
		printf("Upisi niz: ");
		gets(ulaz);
	} while (brojNeSlova(ulaz));
	do {
		printf("Upisi kljuc kriptiranja: ");
		scanf(" %d", &kljuc);
	} while (kljuc < 1 || kljuc > 25);
	caesarEncrypt(ulaz, izlaz, kljuc);
	printf("Kriptirani niz: %s\nOriginalni niz: %s\n", izlaz, ulaz);
	
	
	
	
	
	
	
	
	return 0;
}