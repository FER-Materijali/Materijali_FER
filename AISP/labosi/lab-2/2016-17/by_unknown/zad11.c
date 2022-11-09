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


void ShellSort(char **A, int N, int smjer) {
	int i, j, korak;
	char *pom;
	for (korak = N / 2; korak > 0; korak /= 2) {
		for (i = korak; i < N; i++) {
			pom = A[i];
			for (j = i; j >= korak; j -= korak) {
				if (smjer && strcmp(A[j - korak], pom) <= 0) break;
				else if (!smjer && strcmp(A[j - korak], pom) >= 0) break;
				A[j] = A[j - korak];
			}
			A[j] = pom;
		}
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
		pom = upisi(pom);
		if (*pom == 0) {
			free(pom);
			break;
		}
		polje[n] = pom;
		n++;
	} while (n < 10);
	printf("Uzlazno [1], silazno [0]: ");
	scanf("%d", &f);
	ShellSort(polje, n, f);
	printer(polje, n);
	scanf("%d", &f);
	return 0;
}