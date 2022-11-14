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
	for( i=strlen(x)-1; i>-1; i-- ){
		if ( isupper( x[i] ) || isdigit( x[i] ) ) printf("%c\n",x[i]);
	}
	return 0;
}