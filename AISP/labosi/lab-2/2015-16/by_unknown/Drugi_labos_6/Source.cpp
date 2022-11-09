#include <stdio.h>

#include <malloc.h>

#include <string.h>



void InsertionSort(char **A, int n) {

	int i, j;
	char *tmp;
	for (i = 1; i < n; ++i) {
		tmp = A[i];
		for (j = i ; j >= 1 && (strcmp(A[j - 1], tmp) > 0); --j) {
			
			A[j] = A[j - 1];
		}
		A[j] = tmp;
	}
	

}
int main(void) {

	char **A;

	int n, i;

	printf("Unesite broj elemenata: ");

	scanf("%d", &n);

	A = malloc(n*sizeof(*A));

	for (i = 0; i < n; i++) {

		A[i] = malloc(50 * sizeof(char));

	}

	for (i = 0; i < n; i++) {

		printf("Unesite element:");

		scanf("%s", A[i]);

	}

	InsertionSort(A, n);



	for (i = 0; i < n; i++) {

		printf("%s\n", A[i]);

	}

	return 0;

}