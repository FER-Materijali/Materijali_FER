#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void zamijeni(int **a, int **b)
{
	int *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void selection2Sort(int *A, int n) {
	int i, j, min, max, k, l;
	for (i = 0, j = n - 1; i<n, j>-1; ++i, --j) {
		if (j < i) {
			break;
		}
		min = i;
		max = j;
		for (k = i + 1, l = j - 1; k < n - 1, l>0; ++k, --l)
		{
			if (A[k] < A[min])
				zamijeni(&A[k], &A[min]);
			if (A[l] > A[max])
				zamijeni(&A[l], &A[max]);
			

		}
	}
}
	int main()
	{
		int i, n, *polje;
		puts("Upisite broj clanova polja N<=10");
		scanf("%d", &n);
		polje = (int*)malloc(n*sizeof(int));
		if (polje == NULL) {
			puts("Nema memorije!");
			exit(1);
		}
		for (i = 0; i < n; ++i)
		{
			printf("Upisite %d clan polja\n", i + 1);
			scanf("%d", &polje[i]);
		}
		puts("Prije sortiranja");
		for (i = 0; i < n; ++i) {
			printf("%3d", polje[i]);
		}
		selection2Sort(&polje[0], n);
		puts("\nNakon sortiranja");
		for (i = 0; i < n; ++i) {
			printf("%3d", polje[i]);
		}
		return 0;


	}
