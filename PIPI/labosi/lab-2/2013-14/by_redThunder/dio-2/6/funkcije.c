#include "funkcije.h"
#include <ctype.h>

int brojNeSlova( char str[] ){
	int ret=0, i=0;
	while( str[i] != '\0' ){
		ret += !isalpha( str[i++] );
	}
	return ret;
}
void caesarEncrypt (char nizUlaz[], char nizIzlaz[], int kljucKriptiranja){
	int i=0;
	char c;
	while( nizUlaz[i]!= '\0' ){
		c = nizUlaz[i] + kljucKriptiranja;
		nizIzlaz[i] = c - 26*!isalpha(c);
		i++;
	}
	nizIzlaz[i]='\0';
}