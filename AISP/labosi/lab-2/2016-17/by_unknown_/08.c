#include <stdio.h>
#include <malloc.h>
#include <string.h>

void InsertionSort(char **A, int N, int smjer);

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
	
	InsertionSort(nniz, n, smjer);
	
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%s", *(nniz + i));
		free(*(nniz + i));
	}
	free(nniz);
	
	return 0;
}

void InsertionSort(char **A, int N, int smjer) {
	int i, j;
	char *pom;
	
	if (smjer == 1) {
		for (i = 1; i < N; i++) {
			pom = A[i];
			for (j = i-1; (j >= 0) && (strcmp(pom, A[j]) < 0); j--) {
				A[j+1] = A[j];
			}
			A[j+1] = pom;
		}
	} else if (smjer == 0) {
		for (i = 1; i < N; i++) {
			pom = A[i];
			for (j = i-1;j >= 0 && (strcmp(pom, A[j]) > 0); j--) {
				A[j+1] = A[j];
			}
			A[j+1] = pom;
		}
	}
}