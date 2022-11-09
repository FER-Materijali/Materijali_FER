#include <stdio.h>
#include <malloc.h>
#include <string.h>

void ShellSort(char **A, int N, int smjer);

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
	
	ShellSort(nniz, n, smjer);
	
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%s", *(nniz + i));
		free(*(nniz + i));
	}
	free(nniz);
	
	return 0;
}

void ShellSort(char **A, int N, int smjer) {
	int korak, i, j, k;
	char *pom;
	
	if (smjer == 0) {
		for (korak = N/2; korak > 0; korak /= 2) {
			for (i = 0; i < korak; i++) {
				for (j = i; j < N; j+=korak) {
					pom = A[j];
					for (k = j-korak; k >= 0 && strcmp(A[k], pom) < 0; k-=korak) {
						A[k+korak] = A[k];
					}
					A[k+korak] = pom;
				}
			}
		}
	}else if (smjer == 1) {
		for (korak = N/2; korak > 0; korak /= 2) {
			for (i = 0; i < korak; i++) {
				for (j = i; j < N; j+=korak) {
					pom = A[j];
					for (k = j-korak; k >= 0 && strcmp(A[k], pom) > 0; k-=korak) {
						A[k+korak] = A[k];
					}
					A[k+korak] = pom;
				}
			}
		}
	}
}