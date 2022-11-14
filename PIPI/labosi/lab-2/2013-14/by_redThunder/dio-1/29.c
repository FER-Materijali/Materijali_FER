#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10

int main( void ){
	char s[MAX+1],sol=0;
	int i,check=0;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if ( !isxdigit(s[i]) ) check = 1;
		if ( s[i]>='0' && s[i]<='7' ) sol++;
	}

	if (check) printf("Ucitani niz nije ispravno zadan.\n");
	else printf("Broj unesnih oktalnih znamenki: %d\n",sol);
	return 0;
}