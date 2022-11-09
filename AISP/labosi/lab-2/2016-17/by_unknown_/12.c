#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

void ShellSort_Hibbard(char **A, int N, int smjer);
int hibbard (int n);

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
	
	ShellSort_Hibbard(nniz, n, smjer);
	
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%s", *(nniz + i));
		free(*(nniz + i));
	}
	free(nniz);
	
	return 0;
}

void ShellSort_Hibbard(char **A, int N, int smjer) {
	int korak, i, j, k, h;
	char *pom;
	
	h = hibbard(N);
	
	if (smjer == 0) {
		for (korak = (pow(2, h) - 1); korak > 0; h--, korak = (pow(2, h) - 1)) {
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
		for (korak = (pow(2, h) - 1); korak > 0; h--, korak = (pow(2, h) - 1)) {
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

int hibbard(int n) {
	int k;
	
	for (k = 0; (pow(2, k) - 1) < n; k++);
	
	return k-1; 
}