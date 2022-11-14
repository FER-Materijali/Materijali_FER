#include <stdio.h>
#define MAX 15

int main( void ){
	int niz[MAX],n,i,novo[MAX],t=0;
	do{
		scanf("%d",&n);
	}while(n<1 || n>15);

	for(i=0;i<n;i++) { 
		scanf("%d",&niz[i]);
		if ( niz[i]>-11 && niz[i]<16 ) novo[t++] = niz[i];
	}
	printf("Novo polje: ");
	for(i=0;i<t;i++) printf("%d ",novo[i]);
	printf("\n");
	return 0;
}