#include <stdio.h>
#include <math.h>
#define MAX 30
int main() {
	int polje[MAX];
	int i, n;
	do{
		printf("Ucitati velicinu cjelobrojnog polja:\n");
		scanf("%d", &n);
	} while(n<1 || n>30);
	printf("Unesite %d vrijednosti clanova cjelobrojnog polja:\n", n);
	for(i=0; i<n; i++){
		printf("%d. clan = ", i+1);
		scanf("%d", &polje[i]);
	}
	printf("\n\n");
	for(i=0; i<n; i++){
		if(polje[i]>=-1 && polje[i]<=22)
			polje[i]=0;
		printf("%d. clan = %d\n", i+1, polje[i]);
	}
	return 0;
}