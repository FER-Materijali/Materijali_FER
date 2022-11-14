#include <stdio.h>
#include "funkcije.h"
#define MAX 10

int main( void ){
	int polje[MAX][MAX], i, j, r, s;
	int stupac[MAX];
	do{
		scanf("%d%d",&r,&s);
	}while( !( r<=MAX && s<=MAX ) );

	for( i=0; i<r; i++ ){
		for( j=0; j<s; j++ ){
			scanf("%d",&polje[i][j]);
		}
	}

	kvadrat( polje[0], r, s, MAX );
	minStupac( polje[0], r, s, MAX, stupac );

	for( i=0; i<r; i++ ){
		for( j=0; j<s; j++ ){
			printf("%d ",polje[i][j]);
		}
		printf("\n");
	}
	for( i=0; i<s; i++ ){
		printf("%d ", stupac[i] );
	}
	return 0;
}