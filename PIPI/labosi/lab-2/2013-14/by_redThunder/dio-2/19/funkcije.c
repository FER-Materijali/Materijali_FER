#include "funkcije.h"
#include <ctype.h>
#include <string.h>
#define MAXSTUP 21

int search( char *str, char ch, int pos ){
	int i;
	for(i=pos; i<strlen(str); i++){
		if(str[i]==ch) return i-pos;
	}
	return -1;
	/*može biti -1 u slućaju da tražimo po zadnjoj riječi, iza koje nema razmaka*/
}

void rastavi ( char *niz, int brRijeci, int maxRijeci, int duljinaRijeci, char *polje ){
	int i, j, x, indeks=0, umetnuto = 0;
	for( i=0; i<maxRijeci; i++ ){
		for( j=0; j<=duljinaRijeci; j++ ){
			/*ako je na indeksu slovo, onda ga stavimo u polje, inače u polje stavimo \0, u tom slučaju je na indekus ili ' ' ili '\0', tj razmak ili kraj*/
			if ( isalpha( niz[indeks] ) && umetnuto<=brRijeci && j<duljinaRijeci ) {
				*(polje+i*MAXSTUP+j) = niz[indeks++];
				if ( j==duljinaRijeci ) umetnuto++; 
			} else *(polje+i*MAXSTUP+j) = '\0';
		}
		x = search(niz,' ',indeks);
		if (x==-1) umetnuto = brRijeci+1; /*prekidanje upisivanja*/ else indeks += x+1;
	}
}

int brojRijeci ( char *polje, int brRijeci ){
	int i,sol=0;
	for( i=0; i<brRijeci; i++ ) sol += ( *(polje+i*MAXSTUP) != '\0' );
	return sol;
	/* gledamo samo prvi stupac polja, i brojimo tam di nije \0. */
}