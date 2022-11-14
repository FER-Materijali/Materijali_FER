#include <stdio.h>
#define MAX 20

int main( void ){
	int n,i,niz[MAX];
	do {
		scanf("%d",&n);
	} while(n<1 || n>20);
	for( i=0; i<n; i++ ){
		scanf("%d",&niz[i]);
	}
	for( i=0; i<n; i++ ){
		if( niz[i]>9 && niz[i]<21 ) printf("%2d.%3d\n",i,niz[i]);
	}
	return 0;
}