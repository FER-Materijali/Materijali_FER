#include <stdio.h>
#include "funkcije16.h"
#define MAXRED 20
#define MAXSTUP 20

int main(void)
{
	int matrica[MAXRED][MAXSTUP];
	int red, stup, min, max, i, j;
	do {
		printf("Unesite dimenzije max. velicine %dx%d: ", MAXRED, MAXSTUP);
		scanf("%d %d", &red, &stup);
	} while (!dobreDimenzije(MAXRED, MAXSTUP, red, stup));

	for (i = 0; i < red; ++i)
		for (j = 0; j < stup; ++j)
			scanf("%d", &matrica[i][j]);
	
	minMax(matrica, red, stup, &min, &max);

	for (i = 0; i < red; ++i) {
		for (j = 0; j < stup; ++j)
			printf("%4d", matrica[i][j]);
		printf("\n");
	}

	printf("Najmanji broj u unesenom polju je: %d\n", min);
	printf("Najveci broj u unesenom polju je: %d\n", max);
	return 0;
}