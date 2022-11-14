#include <stdio.h>

int main (void) {
	int n, i, suma=0;
	int polje[20];
	do {
		printf("unesi broj vrijednosti polja\n");
		scanf("%d", &n);
	} while ((n<1) || (n>20));

	for (i = 0; i < n; ++i) {
		printf("unesi element: ");
		scanf("%d",  &polje[i]);
		/* sumiraj elemente iz zadanog intervala i odmah ih postavljaj na 0 */
		if ((polje[i] > -10) && (polje[i] <= 10)) {
			suma+=polje[i];
			polje[i] = 0;
		}
	}
	printf("Zbroj vrijednosti promijenjenih elemenata: %d\n", suma);

	return 0;

}
