#include <stdio.h>
#define MAX 100
int main() {
	double niz[MAX], suma=0; double pi, apPogreske;
	int i, j, n;
	do{
		printf("Unesite broj clanova niza:\n");
		scanf("%d", &n);
	}while(n<1 || n>100);
	for(i=0, j=1; i<n; i++, j++){
		niz[i]=1./((4*j-1)*(4*j+1));
		suma+=niz[i];
	}
	pi=4-suma*8;
	printf("PI = %7.6f\n", pi);
	apPogreske=pi-3.141593;
	printf("Apsolutna vrijednost pogreske = %7.6f\n", apPogreske);
	return 0;
}