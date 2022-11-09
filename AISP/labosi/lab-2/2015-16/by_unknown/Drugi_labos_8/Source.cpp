#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void BubblePoboljsani(char **A, int n);
void Zamijeni(char *prvi, char *drugi);
int main() {
	int i, n;
	char **A;
	puts("Koliko zelite clanova ?");
	scanf("%d", &n);
	A = malloc(n*sizeof(char*));
	for (i = 0; i < n; ++i) {
		A[i] = malloc(50 * sizeof(char));
		printf("Upisite %d clan: ", i + 1);
		scanf("%s", A[i]);
	}
	puts(" ");
	for (i = 0; i < n; ++i) {
		printf("%s\n", A[i]);
	}
	puts("------------------------");
	BubblePoboljsani(A, n);
	puts(" ");
	for (i = 0; i < n; ++i) {
		printf("%s\n", A[i]);
	}
	puts("------------------------");
	return 0;
}
void Zamijeni(char *prvi, char *drugi) {
	char *temp;
	temp = prvi;
	prvi = drugi;
	drugi = temp;
}

void BubblePoboljsani(char ** A, int n)
{
	int i, j, bila;
	for (i = 0, bila = 1; bila; i++) {
		bila = 0;
		for (j = 0; j < n - 1 - i; ++j) {
			if (A[j + 1] < A[j]) {
				Zamijeni(&A[j + 1], &A[j]);
				bila = 1;
			}
		}
	}
}
