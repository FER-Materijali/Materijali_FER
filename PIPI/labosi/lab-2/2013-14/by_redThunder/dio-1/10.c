#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main( void ){
	int niz[MAX],n,i,sol=0;
	do{
		scanf("%d",&n);
	}while(n<1 || n>20);
	for(i=0;i<n;i++) {
		scanf("%d",&niz[i]);
		if (abs(niz[i])<11) { sol += niz[i]; niz[i]=0; }
	}
	printf("Zbroj vrijednosti promijenjenih elemenata: %d\n",sol);
	return 0;
}