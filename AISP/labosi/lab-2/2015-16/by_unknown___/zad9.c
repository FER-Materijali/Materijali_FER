#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAX_DULJINA 100
void ShellSort(char **A, int N);
int main(void) {
	/* Koristimo buffer za unos stringova */
	char **ulaznoPolje, buff[MAX_DULJINA + 1];
	int i, N;
	scanf("%d", &N);
	/* Alociramo memoriju za pokazivace na stringove */
	ulaznoPolje = (char **) malloc(N * sizeof(char *));
	for (i = 0; i < N; i++) {
		/* Ucitamo neki string */
		scanf("%s", buff);
		/* Alociramo memoriju za novi string i 
			spremamo pokazivac u niz pokazivaca (ulaznoPolje) */
		ulaznoPolje[i] = (char *) malloc((strlen(buff) + 1) * sizeof(char));
		/* Koloniziramo novoalocirani prostor s charovima iz buffera */
		strcpy(ulaznoPolje[i], buff);
	}
	ShellSort(ulaznoPolje, N);
	for (i = 0; i < N; i++)
		printf("%s\n", ulaznoPolje[i]);
	/* Freeanje memorije */
	for (i = 0; i < N; i++)
		free(ulaznoPolje[i]);
	free(ulaznoPolje);
	return 0;
}
/* Zamjena mjesta dva pointera */
void swap(char **a, char **b) {
	char *t = *a;
	*a = *b;	
	*b = t;
}
void ShellSort(char **A, int N) {
	int i, j, step;
	char *pom;
	for (step = N / 2; step > 0; step /= 2) {
		for (i = step; i < N; i++) {
			pom = A[i];
			for (j = i; j >= step && strcmp(A[j - step], pom) > 0; j -= step) {
				swap(A + j, A + j - step);
			}
			A[j] = pom;
		}
	}
}