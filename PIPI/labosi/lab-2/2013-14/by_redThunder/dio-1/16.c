#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

int main( void ){
	char s[MAX+1], tmp;
	int i;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if ( islower(s[i]) ){
			tmp = s[i];
			s[i] = s[ strlen(s)-1 ];
			s[ strlen(s)-1 ] = tmp;
			break;
		}
	}
	printf("%s\n",s);
	return 0;
}