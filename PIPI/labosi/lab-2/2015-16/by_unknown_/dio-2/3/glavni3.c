#include <stdio.h>
#include "funkcije3.h"
#define MAXSKUP 20

int main(void)
{
	int skup1[MAXSKUP], skup2[MAXSKUP], rez[MAXSKUP];
	int n1, n2, nrez = 0;

	printf("Skup 1: ");
	n1 = unos(skup1);
	printf("Skup 2: ");
	n2 = unos(skup2);

	unija(n1, skup1, n2, skup2, &nrez, rez);
	printf("Skup 1: ");
	ispis(skup1, n1);
	printf("\n");
	printf("Skup 2: ");
	ispis(skup2, n2);
	printf("\n");
	printf("Unija: ");
	ispis(rez, nrez);
	printf("\n");
	return 0;	
}