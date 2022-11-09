#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void SelectionSort(char **A, int n) {
	int i, j;
	char * min, *temp;
	temp = malloc(50 * sizeof(char));
	for (i = 0; i < n; ++i) {
		min = A[i];
		for (j = i + 1; j < n; ++j) {
			if (strcmp(A[j],min)<0) {
			
				strcpy(temp, min);
				strcpy(min, A[j]);
				strcpy(A[j], temp);
				
				
			}
		}
	}
	free(temp);
}
int main() {
	int n, i;
	char **A;
	puts("Koliko zelite podataka (MAX 10)");
	scanf("%d", &n);
	A = malloc(n*sizeof(*A));
	for (i = 0; i < n; ++i) {
		A[i] = malloc(51 * sizeof(char));
		printf("Upisite %d podatak", i + 1);
		scanf("%s", A[i]);
	}
	puts("Prije izmjene-----------------------------");
	for (i = 0; i < n; ++i) {
		printf("%s\n", A[i]);
	}
	puts("------------------------------------------");
	puts("Nakon izmjene-----------------------------");
	SelectionSort(A, n);
	for (i = 0; i < n; ++i) {
		printf("%s\n", A[i]);
	}
	return 1;
}
