#include <stdio.h>
#include <malloc.h>

struct posta {
	int brMjesta;
	char imeMjesta[40+1];
};
typedef struct posta zapis;

void insertionSort(zapis *A, int n, char smjer){
	int i, j;
	zapis pom;
	if (smjer == '0'){
		for(i=1; i<n; i++){
			pom = *(A+i);
			for(j=i;j>=1 && (A+j-1)->brMjesta > pom.brMjesta;j--){
				*(A+j)= *(A+j-1);
			}
			*(A+j)=pom;
		}
	}
	else {
		for(i=1; i<n; i++){
			pom = *(A+i);
			for(j=i;j>=1 && (A+j-1)->brMjesta < pom.brMjesta;j--){
				*(A+j)= *(A+j-1);
			}
			*(A+j)=pom;
		}
	}
}

int main(void){
	zapis *A;
	int n, i;
	char smjer;
	printf("Unesite broj mjesta koja zelite sortirati (najvise 10) > ");
	do {
		scanf("%d", &n);
	}while(n>10);
	A = malloc(n*sizeof(zapis));
	printf("\nUnesite clanove polja u obliku: postanski_broj_mjesta ime_mjesta > ");
	for(i=0;i<n;i++){
		scanf("%d %[^\n]", &(A+i)->brMjesta, (A+i)->imeMjesta);
	}
	printf("\nUnesite smjer sortiranja: 0 - uzlazno, 1 - silazno > ");
	scanf(" %c", &smjer);
	insertionSort(A, n, smjer);
	printf("\nSortirana mjesta: \n");
	for(i=0;i<n;i++){
		printf("%d %s\n", (A+i)->brMjesta, (A+i)->imeMjesta);
	}
	free(A);
	return 0;
}