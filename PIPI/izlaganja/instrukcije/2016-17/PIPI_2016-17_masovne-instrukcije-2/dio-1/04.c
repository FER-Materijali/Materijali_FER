#include <stdio.h>

int main (void) {
	int n, i;
	int polje[20];
	/*S tipkovnice učitati broj članova cjelobrojnog polja 1 ≤ n ≤ 20 
	(broj članova polja potrebno je
	učitavati sve dok se ne unese ispravna vrijednost) */
	do {
		printf("unesi n: \n");
		scanf("%d", &n);
	} while ((n<1) || (n>20));
	/* ŠABLONA */
	/* učitavanje elemenata polja */
	for ( i = 0; i < n; ++i)
	{
		printf("unesi %d. član: ", i+1);
		scanf ("%d", &polje[i]);
	}
	/* još jednom prošetaj po polju i odradi što se od tebe traži */
	for (i = 0; i < n; ++i)
	{
		if ((polje[i] >= 10) && (polje[i] <= 20))
		    printf("%2d. %d\n", i, polje[i] );
	}
	return 0;
}
