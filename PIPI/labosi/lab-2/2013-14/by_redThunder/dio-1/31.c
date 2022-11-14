#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

int main( void ){
	char s1[MAX+1],s2[MAX+2];
	int i;
	scanf("%s",s1);

	for(i=0; i<strlen(s1); i++){
		if ( !isalnum( s1[i] ) ) {
			printf("Ucitani niz nije ispravno zadan.\n");
			return 0;
		}
	}

	strcpy(s2,s1);
	for(i=0; i<strlen(s2); i++){
		if ( s2[i]=='a' ) s2[i] = '9';
		if ( s2[i]=='b' ) s2[i] = '8';
		if ( s2[i]=='c' ) s2[i] = '7';
	}
	printf("%s\n%s\n",s1,s2);
	return 0;
}