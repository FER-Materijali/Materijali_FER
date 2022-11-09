#include <stdio.h>
#include <malloc.h>
#include <string.h>

void SelectionSort(char **A, int N, int smjer);
void Zamijeni(char *prvi, char *drugi);

int main (void) {
	int smjer, n, i;
	char c, **nniz;
	
	printf("N smjer:\n");
	scanf("%d %d%c", &n, &smjer, &c);
	
	nniz = (char **)malloc(sizeof(char *) * n);
	if (!nniz) {
		printf("Nema dovoljno memorije!\n");
		return 1;
	}
	
	for (i = 0; i < n; i++) {
		*(nniz + i) = (char *)malloc(sizeof(char) * 10);
		if (!*nniz) {
			printf("Nema dovoljno memorije!\n");
			return 2;
		}
		fgets(*(nniz+i), 10, stdin);
	}
	
	SelectionSort(nniz, n, smjer);
	
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%s", *(nniz + i));
		free(*(nniz + i));
	}
	free(nniz);
	
	return 0;
}

void SelectionSort(char **A, int N, int smjer) {
	int i, j, naj;
	
	if (smjer == 0) {
		for (i = 0; i < N-1; i++) {
			for (j = i, naj = i; j < N; j++) {
				if (strcmp(A[naj], A[j]) < 0) {
					naj = j;
				}
			}
			Zamijeni(A[i], A[naj]);
		}
	} else if (smjer == 1) {
		for (i = 0; i < N-1; i++) {
			for (j = i+1, naj = i; j < N; j++) {
				if (strcmp(A[naj], A[j]) > 0) {
					naj = j;
				}
			}
			Zamijeni(A[i], A[naj]);
		}
	}
}

void Zamijeni(char *prvi, char *drugi) {
	char pom[10];
	
	strcpy(pom, prvi);
	strcpy(prvi, drugi);
	strcpy(drugi, pom);
}