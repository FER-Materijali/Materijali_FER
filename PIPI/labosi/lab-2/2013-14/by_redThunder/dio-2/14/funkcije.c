#include "funkcije.h"
#include <string.h>
#include <ctype.h>

int nizUInt( char *niz ){
	int potencija = 1, sol = 0, i, len = strlen(niz);
	if ( !isdigit(*niz) ) return -1;
	for( i=len-1; i>-1; i-- ){
		sol += ( *( niz+i ) - '0' ) * potencija;
		potencija *= 10;
	}
	return sol;
}

int matemOp ( int a, int b, char op, int *rez ){
	if (!( op == '+' || op == '*' )) return 0;
	*rez = ( (op=='+') ? a+b : a*b );
	return 1;
}