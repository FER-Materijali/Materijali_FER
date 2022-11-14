#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5

int main( void ){
	char s[MAX+1],max=0;
	int i,check=0;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if ( !isxdigit(s[i]) ) check = 1;
		if (toupper(max) < toupper(s[i]) ) max = s[i];
	}

	if (check) printf("Ucitani niz nije ispravno zadan.\n");
	else printf("Najveca heksadekadska znamenka u ucitanom broju je %c.\n",max);
	return 0;
}