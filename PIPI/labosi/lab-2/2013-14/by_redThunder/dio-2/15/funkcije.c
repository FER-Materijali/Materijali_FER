#include "funkcije.h"
#include <string.h>

char *napraviRijec( char *ulaz, char *izlaz ){
	int i=0, j=0;
	while(1){
		if( ulaz[i] == '\0' ) { izlaz[j] = '\0'; return NULL; }
		if( ulaz[i] != ' ' ) izlaz[j++] = ulaz[i++]; else break;
	}
	izlaz[j]='\0';
	return &ulaz[i+1];
}

int sazetak( char *ulaz ){
	int sol=0,i=0;
	if ( ulaz == NULL ) return 0;
	while( *(ulaz+i) ) sol += (int)*( ulaz + i++ );
	return sol%128;
}

void dodajZnak( char *ulaz, int broj ){
	int l = strlen(ulaz);
	*(ulaz+l) = (char)broj;
	*(ulaz+l+1) = '\0'; 
}