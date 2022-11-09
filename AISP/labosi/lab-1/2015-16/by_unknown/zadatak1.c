#include <stdio.h>
#include <malloc.h>
void ispis (int *polje, int n) {
	if (n > 1) ispis ((polje+1), n-1);
	printf ("%d ", *polje);
	return;
}
int main (void) {
	int n, i;
	int *A;
	printf("Unesite broj clanova polja:\n");
	scanf("%d", &n);
	A = (int*) malloc (n * sizeof(int));
	if (A == NULL) {
	printf ("Nema dovoljno memorije\n");
	return 0;
	}
	for (i = 0; i < n; i++) *(A + i) = i;
	ispis (A, n);
	free(A);
	return 0;
}