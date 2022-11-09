#include <stdio.h>
#include <malloc.h>
int zbrojiParne(int *polje, int n) {
	if (n > 1) {
		if (*(polje + n - 1) % 2 == 0) return zbrojiParne(polje, n - 1) + *(polje + n - 1);
		else return zbrojiParne(polje, n - 1);
	}
	else {
		if (*(polje + n - 1) % 2 == 0) return *(polje + n - 1);
		else return 0;
	}
	}
int main(void) {
	int n, i, zbroj;
	int *A;
	printf("Unesite broj clanova polja:\n");
	scanf("%d", &n);
	A = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) *(A + i) = i;
	zbroj = zbrojiParne(A, n);
	printf("Zbroj polja %d clanova je %d\n", n, zbroj);
	free (A);
	return 0;
}