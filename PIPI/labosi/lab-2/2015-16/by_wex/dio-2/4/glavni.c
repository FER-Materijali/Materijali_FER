#include <stdio.h>
#include "funkcije.h"

int main(void) {
	char niz[20+1] = {0}, gen_niz[100+1] = {0};
	int n;
	do {
		printf("Upisite znakovni niz: ");
		gets(niz);
	} while (!dobarNiz(niz));
	do {
		printf("Upisite duljinu zeljenog niza: ");
		scanf(" %d", &n);
	} while (n < 1 || n > 100);
	generirajNiz(&niz[0], n, &gen_niz[0]);
	printf("%s\n", gen_niz);
	
	return 0;
}