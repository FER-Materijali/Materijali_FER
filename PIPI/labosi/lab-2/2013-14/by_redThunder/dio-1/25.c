#include <stdio.h>
#include <string.h>
#define MAX 5

int main( void ){
	char s[MAX+1];
	int i,sol=0,check=0;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if ( s[i]<'0' || s[i]>'7' ) check = 1;
		if ( s[i]=='4') sol++;
	}

	if (check) printf("Ucitani niz nije ispravno zadan.\n");
	else printf("Prva znamenka ucitanog broja je %c.\nPosljednja znamenka ucitanog broja je %c.\n",s[0],s[strlen(s)-1]);
	return 0;
}