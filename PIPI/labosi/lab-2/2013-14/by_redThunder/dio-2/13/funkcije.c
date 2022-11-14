#include "funkcije.h"
#include <string.h>

int intUNiz ( int broj, char *niz ){
	if ( broj < 0 || broj > 59) return 0;
	*niz = broj/10 + '0'; 
	*(niz+1) = broj%10 + '0';
	*(niz+2) = '\0';
	return 1;
}

char *dodajNiz ( char *prvi, char *drugi ){
	int i,l=strlen(prvi);
	for( i=0; i<=strlen(drugi); i++){
		prvi[l+i] = drugi[i];
	}
	return prvi;
}

void hms ( int sekunde, int *h, int *m, int *s ){
	*s = sekunde%60;
	*m = sekunde/60%60;
	*h = sekunde/3600;
}