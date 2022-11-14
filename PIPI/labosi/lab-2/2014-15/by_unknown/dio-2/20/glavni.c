#include<stdio.h>
#include"funkcije.h"
int main (void) {
	int ns, nb, ni;
	char lozinka[33];
	do {
		printf("\nbroj slova koja lozinka smije sadrzavati: ");
		scanf("%d", &ns);
		printf("broj brojeva koje lozinka smije sadrzavati: ");
		scanf("%d", &nb);
		printf("broj interpunkcijskih znakova koje lozinka smije sadrzavati: ");
		scanf("%d", &ni);
	} while (ns+nb+ni>32);
	generirajLozinku(ns, nb, ni, lozinka);
	printf("\n%s\n", lozinka);
	return 0;
}