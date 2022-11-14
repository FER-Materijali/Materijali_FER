#include<stdio.h>
#include"funkcije.h"
int main (void) {
	char niz[101], noviniz[101];
	gets(niz);
	kodiraj(niz, noviniz);
	printf("\n%s\n%s\n", niz, noviniz);
	return 0;
}