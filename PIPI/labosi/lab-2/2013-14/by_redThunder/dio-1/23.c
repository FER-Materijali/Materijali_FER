#include <stdio.h>
#include <string.h>
#define MAX 10

int main( void ){
	char s[MAX+1],a='0',b='1';
	int i, check = 0;
	int nule = 0;
	scanf("%s",s);

	for(i=0;i<strlen(s);i++){
		if (s[i] != a && s[i] != b) check = 1; 
	}

	if (check){
		printf("Ucitani niz nije ispravno zadan.\n");
		return 0;
	}

	check = 0;
	for(i=0;i<strlen(s);i++){
		if ( s[i] == a ){
			if ( nule ) check = 1; else nule = 1;
		}
		else nule = 0;
	}
	printf("Ucitani binarni broj %ssadrzi dvije ili vise uzastopne nule.\n",(check ? "" : "ne "));
	return 0;
}