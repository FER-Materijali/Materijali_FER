#include<stdio.h>
#include"funkcije.h"
int main (void) {
	char niz[21], noviniz[21];
	int n;
	do {
		gets(niz);
	} while (!dobarNiz(niz));
	do {
		scanf("%d", &n);
	} while (n<1 || n>100);
	generirajNiz(niz, n, noviniz);
	printf("\n%s\n%s\n", niz, noviniz);
	return 0;
}