#include <stdio.h>
#include "funkcije.h"
#define R 20
#define S 20

int main(void) {
	int polje[R][S] = {0};
	int m, n;
	int min = 0, max = 0;
	int i, j;
	
	do {
		printf("Upisi ispravne dimenzije polja: ");
		scanf(" %d %d", &m, &n);
	} while (!dobreDimenzije(m, n, R, S));
	
	printf("Upisi clanove polja: \n");
	
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			scanf(" %d", &polje[i][j]);
		}
	}
	
	minMax(m, n, S, &polje[0][0], &min, &max);
	
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			printf(" %d", polje[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMAX: %d, min: %d\n", max, min);
	
	return 0;
}