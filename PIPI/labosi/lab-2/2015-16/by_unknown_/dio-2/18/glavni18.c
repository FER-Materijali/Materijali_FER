#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "funkcije18.h"
#define MAXNIZ 100 

int main(void)
{
	int m, n, udaljenost[MAXNIZ + 1] = {0}, i, razlika;
	char niz1[MAXNIZ + 1], niz2[MAXNIZ + 1];
	srand(time(NULL));
	do {
		scanf("%d %d", &m, &n);
	} while(m > 1000 || n > 100);
	for (i = 0; i < m; ++i) {
		odrediSlucajniNiz(n, niz1);
		odrediSlucajniNiz(n, niz2);
		razlika = HammingovaUdaljenost(niz1, niz2);
		++udaljenost[razlika];
	}
	printf("Hammingova udaljenost | broj pojavljivanja | postotak pojavljivanja\n");
	printf("======================|====================|===========================\n");
	
	for(i = 0; i <= n; ++i)
		printf("%21d | %18d | %25.2f\n", i, udaljenost[i], (float)udaljenost[i] / m * 100);
	
	return 0;
}