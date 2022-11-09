#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
#define MAX_DULJINA 100
void ShellSort_Hibbard(char **A, int N);
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
	ShellSort_Hibbard(ulaznoPolje, N);
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
int Hibbard_k(int N) {
	/*	racunanje prvog 2 ^ k - 1 broja ispod N
		2 ^ k - 1 = N
		k = log_2 (N + 1) */
	return (int) log(N + 1) / log (2);
}
void ShellSort_Hibbard(char **A, int N) {
	int i, j, step, k = Hibbard_k(N);
	char *pom;
	/*	smanjujemo k (--k), tako smanjujemo i step jer step = 2 ^ k - 1
		kada dodemo do step == 0, kraj */
	for (step = pow(2, k) - 1; step > 0; step = pow(2, --k) - 1) {
		printf("step: %d\n", step);
		for (i = step; i < N; i++) {
			pom = A[i];
			for (j = i; j >= step && strcmp(A[j - step], pom) > 0; j -= step) {
				swap(A + j, A + j - step);
			}
			A[j] = pom;
		}
	}
}
