#include <stdio.h>
#include "funkcije.h"

int main(void) {
	int kljuc;
	char ulaz[100 + 1], izlaz[100 + 1];
	
	do {
		printf("Upisite niz: ");
		gets(ulaz);
	} while (brojneslova(ulaz));
	
	printf("Kljuc: ");
	scanf("%d", &kljuc);
	
	caesarEncrypt(ulaz, izlaz, kljuc);
	
	printf("Kriptirani: %s\nIzvorni: %s", izlaz, ulaz);
	return 0;
}