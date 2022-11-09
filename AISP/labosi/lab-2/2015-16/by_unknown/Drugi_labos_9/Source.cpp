#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void ShellSort(char **A, int n);
int main() {
	int i, n;
	char **A;
	puts("Upisite broj znakovnih nizova <=10\n");
	scanf("%d", &n);
	A =(char**) malloc(n*sizeof(char*));
	for (i = 0; i < n; ++i) {
		printf("Upisi %d clan polja", i + 1);
		A[i] = (char*)malloc(50 * sizeof(char));
		scanf("%s", A[i]);
	}
	puts("Prije sortiranja shell");
	for (i = 0; i < n; ++i) {
		printf("%s\n", A[i]);
	}

	puts("Nakon sortiranja");
	ShellSort(A, n);
	for (i = 0; i < n; ++i) {
		printf("%s\n", A[i]);
	}
	return 0;

}
void ShellSort(char **A, int n) {
	int i, j, korak;
	char *pom;
	for (korak = n / 2; korak > 0; korak /= 2) {
		for (i = korak; i < n; ++i) {
			pom = A[i];
			for (j = i; j >= korak && strcmp(A[j - korak], pom) > 0; j -= korak) {
				A[j] = A[j - korak];
			}
			A[j] = pom;
		}
	}
}