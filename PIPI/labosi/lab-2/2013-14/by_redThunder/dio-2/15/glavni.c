#include <stdio.h>
#include "funkcije.h"
#define MAX 200

int main( void ){
	char str[MAX+1], word[MAX+1];
	char *x;
	gets(str);
	x = str;
	while( x != NULL ){
		x = napraviRijec(x,word);

		printf("%s %d ",word,sazetak(word));
		dodajZnak( word, sazetak(word) );
		printf("%s\n",word);
	}
	return 0;
}