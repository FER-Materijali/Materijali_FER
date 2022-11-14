#include <stdio.h>
#include <math.h>
#define MAX 1000
int main() {
	double niz[MAX], suma=0; double polovina, apPogreske;
	int i, j, n;
	do{
		printf("Unesite broj clanova niza:\n");
		scanf("%d", &n);
	}while(n<1 || n>1000);
	for(i=0, j=1; i<n; i++, j++){
		niz[i]=1./((2*j-1)*(2*j+1));
		suma+=niz[i];
	}
	polovina=suma;
	printf("jedna polovina = %7.6f\n", polovina);
	apPogreske=polovina-0.5;
	printf("Apsolutna vrijednost pogreske = %7.6f\n", apPogreske);
	return 0;
}
