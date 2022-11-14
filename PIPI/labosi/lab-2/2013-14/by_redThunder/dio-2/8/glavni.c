#include <stdio.h>
#include "funkcije.h"
#define MAX 200

int main( void ){
	char s[MAX+1];
	char l,g;
	int sol=0,hm=0,check;
	scanf("%s",s);
	do{
		printf("Unesite lijevi i desni granicnik: ");
		scanf(" %c%c",&l,&g);
		check = (l=='\\' || g=='\\');
		if ( !check ) {
			printf("Izraz %s %s ispravan s obzirom na granicnike %c %c.\n",s,(izrazJeIspravan(s,l,g)?"JE":"NIJE"),l,g);
			sol += izrazJeIspravan(s,l,g);
			hm++;
		}
	} while( !check );
	printf("Od testiranih, izraz %s je ispravan za %d granicnika, a neispravan za %d granicnika.\n",s,sol,hm-sol);
	return 0;


}