#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

void printer(char **polje, int n) {
	int i;
	printf("kontrolni ispis\n");
	for (i = 0; i < n; i++)
		printf("%s\n", polje[i]);
	return;
}
char* upisi(char* pom) {
	int f = 0;
	char c;
	do {
		c = fgetc(stdin);
		if (c != '\n' && c != EOF) {
			pom[f] = c;
			f++;
			pom = realloc(pom, sizeof(char)*(f + 1));
		}
	} while (c != '\n' && c != EOF);
	pom[f] = 0;
	return pom;
}

void Zamijeni(char **prvi, char **drugi) {
	char *pom;
	pom = *prvi;
	*prvi = *drugi;
	*drugi = pom;
	return;
}

void SelectionSort(char **A, int N, int smjer) {
	int i, j, min, max;
	for (i = 0; i < N; i++) {
		min = i;
		max = i;
		for (j = i + 1; j < N; j++) {
			if (strcmp(A[j], A[min]) < 0) min = j;
			else if (strcmp(A[j], A[max]) > 0) max = j;
		}
		if (smjer)
			Zamijeni(&A[i], &A[min]);
		else
			Zamijeni(&A[i], &A[max]);
	}
	return;
}

int main(void) {
	char *polje[10], *pom, c;
	int i, j, n = 0, f;
	do {
		printf("Unesi niz (ENTER za kraj): ");
		f = 0;
		pom = malloc(sizeof(char));
		pom=upisi(pom);
		if (*pom == 0) {
			free(pom);
			break;
		}
		polje[n] = pom;
		n++;
	} while (n < 10);
	printf("Uzlazno [1], silazno [0]: ");
	scanf("%d", &f);
	SelectionSort(polje, n, f);
	printer(polje, n);
	return 0;
}