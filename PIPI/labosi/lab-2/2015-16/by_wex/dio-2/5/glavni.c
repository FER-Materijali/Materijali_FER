#include <stdio.h>
#include "funkcije.h"

int main(void) {
	char niz[200+1] = {0};
	int br;
	printf("Upisite niz znakova: \n");
	scanf(" %200[^\n]", niz);
	br = brojRecenica(niz);
	if (br == 0) {
		printf("Tekst\n'%s'\nne sadrzi niti jednu potpunu recenicu.\n", niz);
	} else {
		printf("Broj recenica u tekstu:\n'%s'\nje %d.", niz, br);
	}
	return 0;
}