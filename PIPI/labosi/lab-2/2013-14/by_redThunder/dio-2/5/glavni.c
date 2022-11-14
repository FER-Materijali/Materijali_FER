#include <stdio.h>
#include "funkcije.h"
#define MAX 200

int main( void ){
	char s1[MAX+1];
	int n;
	gets(s1);
	n = brojRecenica( s1 );
	if (n) printf("Broj recenica u tekstu:\n\'%s\'\nje %d.\n",s1,n); else printf("Tekst\n\'%s\'\nne sadrzi niti jednu potpunu recenicu.\n",s1);
	return 0;
}