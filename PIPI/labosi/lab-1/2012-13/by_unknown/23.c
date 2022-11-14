#include <stdio.h>
#include <math.h>
#define MAX 15
int main() {
	int polje[MAX], polje2[MAX];
	int i, n, brojac=0, j=0;
	do{
		printf("Ucitati velicinu cjelobrojnog polja:\n");
		scanf("%d", &n);
	} while(n<1 || n>10);
	printf("Unesite %d vrijednosti clanova cjelobrojnog polja:\n", n);
	for(i=0; i<n; i++){
		printf("%d. clan = ", i+1);
		scanf("%d", &polje[i]);
	}
	printf("\n\n");
	for(i=0; i<n; i++){
		if(polje[i]>=-10 && polje[i]<=15){
			polje2[j]=polje[i];
			j++;
		}
		printf("%d. clan = %d\n", i+1, polje[i]);
	}
	printf("\n\n");
	printf("Novo polje: ");
	for(i=0; i<j; i++)
		printf(" %d ", polje2[i]);
	printf("\n");
	return 0;
}
