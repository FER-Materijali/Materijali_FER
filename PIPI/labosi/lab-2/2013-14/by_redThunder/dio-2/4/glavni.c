#include <stdio.h>
#include <string.h>
#include "funkcije.h"
#define MAX 20

int main( void ){
	int n;
	char s1[MAX+1],s2[MAX*5+1];
	do{
		scanf("%s",s1);
	}while( !dobarNiz(s1) );
	do{
		scanf("%d",&n);
	}while( n<1 || n>100 );

	generirajNiz( s1, n, s2 );
	printf("%s\n",s2);
	return 0;
}