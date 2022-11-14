#include <stdio.h>
#include "funkcije.h"

int main(void) {
	char ulaz[111] = {0};
	char uzorak[11] = {0};
	int promjena;
	
	printf("Upisite ulazni niz: ");
	scanf(" %100[^\n]", ulaz);
	printf("Upisite uzorak: ");
	scanf(" %10[^\n]", uzorak);
	
	do {
		promjena = 0;
		promjena = izbaci(ulaz, uzorak);
	} while (promjena == 1);
	
	printf("Konacan niz: %s", ulaz);
	
	return 0;
}