#include <stdio.h>
#include "funkcije.h"
#define L 32

int main(void) {
	int ns, nb, ni;
	char lozinka[L+1] = {0};
	
	printf("Upisite broj slova, brojeva i interpunkcijskih znakova: ");
	scanf(" %d %d %d", &ns, &nb, &ni);
	
	generirajLozinku(ns, nb, ni, lozinka);
	
	printf("%s\n", lozinka);
	
	return 0;
}