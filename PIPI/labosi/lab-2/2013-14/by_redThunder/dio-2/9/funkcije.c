#include "funkcije.h"

void genPodniz ( char *nizUlaz, char *podNiz, int pocPozicija, int duljPodniza ){
	int i;
	for(i=pocPozicija;i<(duljPodniza+pocPozicija);i++) *(podNiz+i-pocPozicija) = *(nizUlaz+i);
	*(podNiz+duljPodniza) = '\0';
}

int nizoviJednaki ( char *niz1, char *niz2 ){
		while( 1 ){
		if ( *niz1 != *niz2 ) return 0;
		if ( *niz1 == '\0') return 1;
		niz1++;
		niz2++;
	}
}
}