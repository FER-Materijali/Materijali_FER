#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAX_DULJINA 100
void BubbleSortPoboljsani(char **A, int N);
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
	BubbleSortPoboljsani(ulaznoPolje, N);
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
void BubbleSortPoboljsani(char **A, int N) {
	int i, j, bila_zamjena;
	for (i = 0, bila_zamjena = 1; bila_zamjena; i++) {
		bila_zamjena = 0;
		for (j = 0; j < N - i - 1; j++) {
			if (strcmp(A[j + 1], A[j]) < 0) {
				swap(A + j + 1, A + j);
				bila_zamjena = 1;
			}
		}	
	}
}