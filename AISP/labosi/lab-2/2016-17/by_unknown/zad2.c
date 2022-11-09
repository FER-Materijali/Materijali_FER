#include <stdio.h>

void zamijeni(int* A, int* prvi, int *drugi, int n) {
	int p, r;
	p = *A;
	r = *(A + n - 1);
	if (drugi == A) {
		*A = *prvi;
		*prvi = r;
		*(A + n - 1) = p;
	}
	else if (prvi == (A + n - 1)) {
		*(A + n - 1) = *drugi;
		*drugi = *A;
		*A = r;
	}
	else {
		*A = *prvi;
		*(A + n - 1) = *drugi;
		*prvi = p;
		*drugi = r;
	}

	return;
}

void selection2Sort(int *A, int n, char smjer) {
	int j, min, max;
	if (n == 0 || n == 1) return;
	min = 0;
	max = n - 1;
	for (j = 0; j<n; j++) {
		if (A[j]<A[min]) { min = j; }
		else if (A[j]>A[max]) { max = j; }
	}

	if (smjer) {
		zamijeni(A, A + max, A + min, n);
	}
	else {
		zamijeni(A, A + min, A + max, n);
	}
	selection2Sort(A + 1, n - 2, smjer);
	return;
}


int main(void) {
	int polje[10], i, n = 0, f;
	do {
		printf("Broj (-1 za kraj): ");
		scanf("%d", polje + n);
		if (polje[n] == -1)	break;
		n++;
	} while (n < 10);

	printf("Uzazno [0], silazno [1]: ");
	scanf("%d", &f);
	selection2Sort(polje, n, f);
	for (i = 0; i < n; i++)
		printf("%d\n", polje[i]);
	return 0;
}