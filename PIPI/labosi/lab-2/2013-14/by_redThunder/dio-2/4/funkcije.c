#include "funkcije.h"
#include <string.h>
#define MAX 255

int dobarNiz( char str[] ){
	int freq[MAX]={0},i=0;
	while( str[i] != '\0' ){
		if ( freq[ (int)str[i++] ]++ ) return 0;
	}
	return 1;
}

void generirajNiz ( char *znakovi, int duljinaNiza, char *genNiz ){
	int i,a,b;
	a = strlen(znakovi);
	b = duljinaNiza;

	if ( b <= a ){
		for( i = ( a-b ); i <= a; i++ ){
			*(genNiz+(i-a+b)) = *(znakovi + i);
		}
	}
	else {
		for( i = 0; i < b; i++ ){
			*(genNiz + i) = *(znakovi + i%a);
		}
	}
	*(genNiz + b)='\0';
}
