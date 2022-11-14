#include <stdio.h>
#include <math.h>
#define MAX 10
int main() {
	int polje[MAX];
	int i, n, brojac=0;
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
		if(polje[i]>=-20 && polje[i]<=40){
			polje[i]=-100;
			brojac++;
		}
		printf("%d. clan = %d\n", i+1, polje[i]);
	}
	printf("Broj promijenjenih elemenata: %d\n", brojac);
	return 0;
}