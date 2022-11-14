#include<stdio.h>
#include<ctype.h>
#include"funkcije.h"
int main (void) {
	char niz[101], kriptniz[101];
	int kljuc;
	printf("\n");
	do {
	    printf("Upisi niz: ");
		gets(niz);
	} while (brojNeSlova(niz)>0);
	printf("\n");
	do {
		printf("Upisi kljuc kriptiranja: ");
		scanf("%d", &kljuc);
	} while (kljuc<1 || kljuc>25);
	printf("\n");
	caesarEncrypt(niz, kriptniz, kljuc);
	printf("Kriptiran niz:  %s\n", kriptniz);
	printf("Originalni niz: %s\n", niz);
	return 0;
}