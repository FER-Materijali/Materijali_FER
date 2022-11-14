#include <stdio.h>
#include "funkcije.h"
#define MAX 10

int main( void ){
	int i,j,r,s;
	int polje[MAX][MAX];
	double redak[MAX]={0}, stupac[MAX]={0};

	do{
		scanf("%d%d",&r,&s);
	}while( !( r<=MAX && s<=MAX ) );

	for( i=0; i<r; i++ ){
		for( j=0; j<s; j++ ){
			scanf("%d",&polje[i][j]);
		}
	}

	prosjek( polje[0], r, s, MAX, redak, stupac );

	for( i=0; i<r; i++ ){
		printf("%7.2lf",redak[i]);
		for( j=0; j<s; j++ ){
			printf("%8d",polje[i][j]);
		}
		printf("\n");
	}
	printf("        ");

	for( i=0; i<s; i++ ){
		printf("%7.2lf ", stupac[i] );
	}

	return 0;
}