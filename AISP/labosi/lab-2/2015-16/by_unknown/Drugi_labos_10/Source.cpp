#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void ShellHibbard(char **A, int n) {
	int i, j, korak;
	char * pom;
	for (korak = n / 2; korak > 0; korak /= 2) {
		for (i = korak; i < n; ++i) {
			pom = A[i];
			for (j = i; j >= korak && strcmp(A[j - 1], pom) > 0; j-=korak)
			{
				A[j] = A[j - korak];

			}
			A[j] = pom;
		}
	}

}
int main() {
	int i, n, korak = 0;
	char **A;
	puts("Upisite N <=10");
	scanf("%d", &n);
	A = (char**)malloc(n * sizeof(char**));
	for (i = 0; i < n; ++i) {
		A[i] = (char*)malloc(50 * sizeof(char));
		printf("Upisi %d clan : ", i + 1);
		scanf("%s", A[i]);

	}
	puts("Prije sortiranja shell");
	for (i = 0; i < n; ++i) {
		printf("%s\n", A[i]);
	}

	puts("Nakon sortiranja");
	for (i = 1; i < n; ++i) {
		korak += (pow(2, i)-1);
		if (korak > n) {
			korak -= pow(2, i);
			break;
		}
	}
	ShellHibbard(A,korak );
	for (i = 0; i < n; ++i) {
		printf("%s\n", A[i]);
	}
	return 0;
	
}