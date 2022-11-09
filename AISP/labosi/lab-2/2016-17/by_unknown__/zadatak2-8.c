#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define BRCLANOVA 10
#define DULJINA 10

void InsertionSort(char **A, int N, int smjer){
	int i, j;
	char *pom;
	if (smjer == 1)
		for(i=1;i<N;i++){
			pom = A[i];
			for(j=i; j>=1 && strcmp(A[j-1],pom)>0;j--)
				A[j] = A[j-1];
			A[j] = pom;
		}
	else 
		for(i=1;i<N;i++){
			pom = A[i];
			for(j=i; j>=1 && strcmp(A[j-1],pom)<0;j--)
				A[j] = A[j-1];
			A[j] = pom;
		}
}

int main(void){
	char **A;
	int n, i, smjer;
	do{
		printf("Unesite broj n (<=%d): ", BRCLANOVA);
		scanf("%d", &n);
	}while(n>BRCLANOVA);
	A = malloc(n*sizeof(*A));
	printf("Unesite %d znakovnih nizova: ", n);
	getchar();
	for(i=0;i<n;i++){
		A[i] = malloc(DULJINA+1);
		gets(A[i]);
	}
	printf("\nOdaberite nacin sortiranja ( 0 - silazno, 1 - uzlazno): ");
	scanf("%d", &smjer);
	InsertionSort(A, n, smjer);
	printf("\nSortirani niz: ");
	for(i=0;i<n;i++)
		printf("\n%d: %s", i+1, A[i]);
	free(A);
	return 0;
}