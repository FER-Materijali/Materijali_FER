#include<stdio.h>
#include"funkcije.h"
int main (void) {
	int n, r, s, niz[100], polje[10][10], i, j;
	do {
		printf("n: ");
		scanf("%d", &n);
	} while (n<1 || n>100);
	do {
		printf("r: ");
		scanf("%d", &r);
	} while (r<1 || r>10);
	do {
		printf("s: ");
		scanf("%d", &s);
	} while (s<1 || s>10);
	generiraj(niz, n, 20, 80);
	rasporedi (niz, n, polje[0], r, s, 10);
	
	printf("\nniz:");
	for (i=0; i<n; ++i) {
		printf(" %d", niz[i]);
	}
	printf("\npolje:\n");
	for (i=0; i<r; ++i) {
		for (j=0; j<s; ++j) {
			printf("%d ", polje[i][j]);
		}
		printf("\n");
	}
	return 0;
}