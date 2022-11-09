#include <stdio.h>
#include <malloc.h>
#include <string.h>

void BubbleSortPoboljsani(char **A, int N, int smjer);
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
	
	BubbleSortPoboljsani(nniz, n, smjer);
	
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%s", *(nniz + i));
		free(*(nniz + i));
	}
	free(nniz);
	
	return 0;
}

void BubbleSortPoboljsani(char **A, int N, int smjer) {
	int promjena = 1, i, kraj;
	
	if (smjer == 0) {
		for(kraj = N; promjena && kraj > 1; kraj--) {
			promjena = 0;
			for (i = 0; i < N-1; i++) {
				if (strcmp(A[i], A[i+1]) < 0) {
					promjena = 1;
					Zamijeni(A[i], A[i+1]);
				}
			}
		}
	}else if (smjer == 1) {
		for(kraj = N; promjena && kraj > 1; kraj--) {
			promjena = 0;
			for (i = 0; i < N-1; i++) {
				if (strcmp(A[i], A[i+1]) > 0) {
					promjena = 1;
					Zamijeni(A[i], A[i+1]);
				}
			}
		}
	}
}

void Zamijeni(char *prvi, char *drugi) {
	char pom[10];
	
	strcpy(pom, prvi);
	strcpy(prvi, drugi);
	strcpy(drugi, pom);
}