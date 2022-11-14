#include "funkcije.h"
#include <stdio.h>

void brLijevihiDesnihGranicnika ( char *znNiz, char lijevi, char desni, int *brLijevih, int *brDesnih ){
	int a=0, b=0;
	while( *znNiz ){
		if ( *znNiz == lijevi ) a++;
		if ( *znNiz == desni ) b++;
		znNiz++;
	}
	*brLijevih = a;
	*brDesnih = b;
}

int izrazJeIspravan( char *niz, char lijevi, char desni ){
	int x=0, y=0;
	brLijevihiDesnihGranicnika ( niz, lijevi, desni, &x, &y );
	return x==y;
}