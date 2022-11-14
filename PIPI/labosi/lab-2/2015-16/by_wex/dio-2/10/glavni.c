#include <stdio.h>
#include "funkcije.h"

int main(void) {
	char niz[101] = {0};
	char kodirani[201] = {0};
	
	printf("Upisite znakovni niz: ");
	scanf(" %100[^\n]", niz);
	kodiraj(niz, kodirani);
	printf("Kodirani niz: %s\n", kodirani);
	
	return 0;
}