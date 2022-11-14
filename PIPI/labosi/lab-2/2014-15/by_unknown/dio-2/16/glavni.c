#include<stdio.h>
#include"funkcije.h"
int main (void) {
	int red, stup, i, j, min, max;
	do {
		scanf("%d %d", &red, &stup);
	} while (!dobreDimenzije (red, stup, 20, 20));
	int polje[red][stup];
	for (i=0; i<red; ++i) {
		for (j=0; j<stup; ++j) {
			scanf("%d", &polje[i][j]);
		}
	}
	minMax (polje[0], red, stup, &min, &max);
	for (i=0; i<red; ++i) {
		for (j=0; j<stup; ++j) {
			printf("%4d", polje[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", min, max);
	return 0;
}