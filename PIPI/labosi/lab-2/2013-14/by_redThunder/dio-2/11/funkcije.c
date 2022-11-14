#include "funkcije.h"
#include <stdlib.h>
#include <stdio.h>

char *nadjiPodniz ( char *str, char *find ){
	int i, j, isti, lens=0, lenf=0;
	while( *(str + lens++) );
	while( *(find + lenf++) );
	lens--; lenf--;

	for(i=0; i<=lens-lenf; i++){
		isti = 0;
		for(j=0; j<lenf; j++){
			isti += *(str+i+j)==*(find+j);
		}
		if ( isti == lenf ) return str+i;
	}
	return NULL;
}

int izbaci ( char *ulaz, char *uzorak ){
	char *p = nadjiPodniz( ulaz, uzorak );
	int lenu=0, i;

	if ( p==NULL ) return 0;

	while( *(uzorak + lenu++) );
	--lenu;

	for(i=0; ulaz[i]; i++){
		*(p+i) = *(p+i+lenu);
	}
	return 1;
}