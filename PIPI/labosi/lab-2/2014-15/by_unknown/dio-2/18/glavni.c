#include"funkcije.h"
#include<stdio.h>
int main (void) {
	int m, n, i, frekv[100]={0};
	char niz1[101], niz2[101];
	do {
		printf("parova: ");
		scanf("%d", &m);
	} while (m<1 || m>1000);
	do {
		printf("duljina: ");
		scanf("%d", &n);
	} while (n<1 || n>100);
	for (i=0; i<m; ++i) {
		odrediSlucajniNiz(n, niz1);
		odrediSlucajniNiz(n, niz2);
		++frekv[HammingovaUdaljenost(niz1, niz2)];
	}
	printf("\nHammingova udaljenost | broj pojavljivanja | postotak pojavljivanja    ");
	printf("\n======================|====================|===========================");
	for (i=0; i<=n; ++i) {
		printf("\n%21d |%19d |%26.2f ", i, frekv[i], (float)frekv[i]/m*100);
	}
	return 0;
}