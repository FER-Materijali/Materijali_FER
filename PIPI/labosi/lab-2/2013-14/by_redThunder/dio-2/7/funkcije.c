#include "funkcije.h"
#include <ctype.h>

int br_odlomaka( char *tekst ){
	int sol = 0;
	int i = 0;
	while( tekst[i] ){
		if ( tekst[i+1]=='\n' && ispunct(tekst[i]) ) sol++;
		i++;
	}
	return sol;
}

int br_rijeci( char *tekst ){
	int sol = 0;
	int i = 0;
	while( tekst[i] ){
		if ( ( ispunct(tekst[i+1]) || isspace(tekst[i+1]) ) && isalpha(tekst[i]) ) sol++;
		i++;
	}
	return sol;
}