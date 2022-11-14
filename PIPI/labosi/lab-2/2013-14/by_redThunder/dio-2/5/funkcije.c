#include "funkcije.h"
#include <stdlib.h>
#include <stdio.h>

char *prviZnak( char *niz1, char *niz2 ){
	int i=0,j;
	int len=0;
	while( *( niz1 + len++ ) );

	while( *( niz2 + i ) ){
		for(j=0; j<len; j++){
			if ( *(niz2+i) == *(niz1+j) ) return (niz2+i);
		}
		i++;
	}
	return NULL;
}

int brojRecenica( char *str ){
	char *x;
	x=str;
	if (x!=NULL) return brojRecenica( prviZnak(".!?",x+1) )+1; else return -1;
}