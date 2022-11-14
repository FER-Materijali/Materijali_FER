#include <stdio.h>
#include "funkcije.h"
#define M 100
#define R 10
#define S 10

int main(void) {
	int d1[M] = {0};
	int d2[R][S] = {0};
	int n, r, s;
	int i, j;
	
	printf("Upisite broj elemenata jednodimenzionalong polja: ");
	scanf(" %d", &n);
	printf("Upisite broj redaka i stupaca dvodimenzionalnog polja: ");
	scanf(" %d %d", &r, &s);
	
	generiraj(d1, n, 20, 80);
	rasporedi(d1, &d2[0][0], S, n, r, s);
	
	for (i=0; i<r; i++) {
		for (j=0; j<s; j++) {
			printf("%3d", d2[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}