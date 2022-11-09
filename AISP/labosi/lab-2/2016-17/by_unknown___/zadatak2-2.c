#include <stdio.h>
#include <malloc.h>

void zamjeni(int *a, int *b){
	int pom;
	pom = *a;
	*a = *b;
	*b = pom;
}

void selection2Sort(int *A, int n, char smjer){
	int i, j, *min;
	if (smjer == '0') {
		
		for(i=0;i<n-1;i++){
			min = A+i;
			for(j=i+1;j<n;j++)
				if (*(A+j) < *min) min = A+j;
			zamjeni(A+i, min);
		}
	} else {	
		for(i=0;i<n-1;i++){
			min = A+i;
			for(j=i+1;j<n;j++)
				if (*(A+j) > *min) min = A+j;
			zamjeni(A+i, min);
		}
	}
	
}

int main(void){
	int *polje, i, n;
	char smjer;
	printf("Unesite broj clanova n > ");
	do {
		scanf("%d", &n);
	}while(n > 10);
	polje = malloc(n*sizeof(int));
	printf("\nUnesite %d brojeva > ", n);
	for(i=0;i<n;i++)
		scanf("%d", polje+i);
	printf("\nUnesite smjer sortiranja: 0 - uzlazno, 1 - silazno > ");
	scanf(" %c", &smjer);
	selection2Sort(polje, n, smjer);
	printf("\nSortirani niz: \n");
	for(i=0;i<n;i++)
		printf("%d ", *(polje+i));
	free(polje);
	return 0;
}