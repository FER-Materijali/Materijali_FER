#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funkcije19.h"
#define MAXPOLJE 100
#define MAXRED 10
#define MAXSTUP 10

int main(void) {
	int n, r, s, i, j;
	int jednoPolje[MAXPOLJE], dvoPolje[MAXRED][MAXSTUP];
	srand(time(NULL));
	printf("Unesite duljinu polja: ");
	scanf("%d", &n);
	printf("Unesite dimenzije matrice: ");
	scanf("%d %d", &r, &s);
	generiraj(jednoPolje, n, 20, 80);
	rasporedi(jednoPolje, dvoPolje, n, r, s);
	
	for(i = 0; i < n; ++i)
		printf("%d ", jednoPolje[i]);
	printf("\n\n");
	
	for(i = 0; i < r; ++i) {
		for(j = 0; j < s; ++j)
			printf("%4d", dvoPolje[i][j]);
		printf("\n");
	}
		
	return 0;
}