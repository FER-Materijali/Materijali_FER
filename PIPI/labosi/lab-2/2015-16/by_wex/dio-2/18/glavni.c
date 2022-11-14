#include <stdio.h>
#include "funkcije.h"

int main(void) {
	int m, n;
	int i;
	int brojac[101] = {0};
	char niz1[101];
	char niz2[101];
	
	do {
		printf("Upisi m i n: ");
		scanf(" %d %d", &m, &n);
	} while (m < 0 || m > 1000 || n < 0 || n > 100);
	
	for (i=0; i<m; i++) {
		slucajni(n, niz1);
		slucajni(n, niz2);
		brojac[udaljenost(niz1, niz2, n)]++;
	}
	
	printf("Hammingova udaljenost | broj pojavljivanja | postotak pojavljivanja\n======================|====================|===========================\n");
	for (i=0; i<=n; i++) {
		printf("%22d|%22d|%24.2f\n", i, brojac[i], (brojac[i]/(float)m)*100);
	}
	
	return 0;
}