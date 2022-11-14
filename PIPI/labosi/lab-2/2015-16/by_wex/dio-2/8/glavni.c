#include <stdio.h>
#include "funkcije.h"

int main(void) {
	char niz[200+1] = {0};
	char l_granicni;
	char d_granicni;
	
	printf("Upisite izraz koji zelite provjeriti: ");
	scanf(" %200[^\n]", niz);
	
	do {
		printf("\nUpisite lijevi i desni granicnik: ");
		scanf(" %c", &l_granicni);
		if (l_granicni != '\\') {
			scanf(" %c", &d_granicni);
			printf("Izraz %s %sJE ispravan s obzirom na granicnike %c %c.\n", niz, (ispravan(niz, l_granicni, d_granicni)?"":"NI"), l_granicni, d_granicni);
		}
	} while (l_granicni != '\\' && d_granicni != '\\');
	
	return 0;
}