#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define DULJINA 10
#define BRCLAN 10

void Zamijeni(char *prvi, char *drugi){
	char *pom;
	pom = malloc(DULJINA+1);
	strcpy(pom, prvi);
	strcpy(prvi, drugi);
	strcpy(drugi, pom);
	free(pom);
}

void BubbleSortPoboljsani(char **A, int N, int smjer){
	int i, j;
	if(smjer == 1)
		for(i=0;i<N-1;i++)
			for(j=0;j<N-1-i;j++)
				if(strcmp(A[j], A[j+1])<0) Zamijeni(A[j], A[j+1]);
	else
		for(i=0;i<N-1;i++)
			for(j=0;j<N-1-i;j++)
				if(strcmp(A[j], A[j+1])>0) Zamijeni(A[j], A[j+1]);
}

int main(void){
	char **A;
	int n, i, smjer;
	do{
		printf("Unesite broj clanova (<=%d) > ", BRCLAN);
		scanf("%d", &n);
	}while(n>BRCLAN);
	A = malloc(n*sizeof(*A));
	printf("\nUnesite clanove niza: ");
	getchar();
	for(i=0;i<n;i++){
		A[i] = malloc(DULJINA+1);
		gets(A[i]);
	}
	printf("\nOdaberite nacin sortiranja ( 0 - silazno, 1 - uzlazno): ");
	scanf("%d", &smjer);
	BubbleSortPoboljsani(A, n, smjer);
	for(i=0;i<n;i++)
		printf("\nClan %d: %s", i+1, A[i]);
	free(A);
	return 0;
	
}