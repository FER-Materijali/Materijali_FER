#include "funkcije.h"
#include <string.h>

int brojPonavljanja( char niz[], char znak){
	int sol=1,i=0;
	for(i=0;i<strlen(niz);i++){
		if ( niz[i] == znak ){
			if ( niz[i+1] == znak ) sol++; else return sol;
		}
	}
	return 0;
}

void kodiraj( char src[], char dest[] ){
	int i = 0, j = 0, tmp;
	while( i<strlen(src) ){
		tmp = brojPonavljanja( &src[i], src[i] );
		dest[j++] = src[i];
		dest[j++] = tmp + '0';
		i += tmp;
	}
	dest[j]='\0';
}