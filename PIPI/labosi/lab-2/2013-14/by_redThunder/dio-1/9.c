#include <stdio.h>
#define MAX 30

int main( void ){
	int niz[MAX],n,i;
	do{
		scanf("%d",&n);
	}while(n<1 || n>30);
	for(i=0;i<n;i++) scanf("%d",&niz[i]);
	for(i=0;i<n;i++) niz[i] = (niz[i]<-1 || niz[i]>22) ? niz[i] : 0 ; 
	printf("Promijenjeno polje: ");
	for(i=0;i<n;i++) printf("%d "niz[i]);
	printf("\n");
	return 0;
}