#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 60

int main( void ){
	int i;
	char x[ MAX+1 ];
	scanf("%s",x);
	if ( strlen(x)<10 ){
		printf("Prekratak niz\n");
		return 0;
	}
	for( i=0; i<strlen(x); i+=2 ){
		if ( islower( x[i] ) ) printf("%c\n",x[i]);
	}
	return 0;
}