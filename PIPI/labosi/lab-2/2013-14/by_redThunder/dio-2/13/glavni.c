#include <stdio.h>
#include "funkcije.h"

int main( void ){
	int sec,h,m,s;
	char hc[100],mc[100],sc[100];
	scanf("%d",&sec);

	hms(sec,&h,&m,&s);

	h = intUNiz( h, hc );
	m = intUNiz( m, mc );
	s = intUNiz( s, sc );

	if (h*m*s == 0) return 0;

	printf("%s", dodajNiz( dodajNiz( dodajNiz(hc,":"), dodajNiz(mc,":") ), sc) );

	return 0;
}