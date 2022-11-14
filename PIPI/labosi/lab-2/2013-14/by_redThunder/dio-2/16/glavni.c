#include <stdio.h>
#include "funkcije.h"
#define MAX 20

int main( void ){
	int polje[MAX][MAX], r, s, i, j;
	int min = 10000, max =-10000;
	
	do{
		scanf("%d%d",&r,&s);
	}while( !dobreDimenzije(r,s,MAX,MAX) );

	for( i=0; i<r; i++ ){
		for( j=0; j<s; j++ ){
			scanf("%d",&polje[i][j]);
		}
	}

	minMax( polje[0], r, s, MAX, &min, &max );
	
	for( i=0; i<r; i++ ){
		for( j=0; j<s; j++ ){
			printf("%d ", polje[i][j]);
		}
		printf("\n");
	}
	printf("%d %d\n",min,max);
	return 0;
}