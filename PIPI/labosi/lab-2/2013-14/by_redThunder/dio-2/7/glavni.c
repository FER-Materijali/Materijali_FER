#include <stdio.h>
#include "funkcije.h"
#define MAX 2000

int main( void ){
	int i=0, br,bo;
	char tekst[MAX+1];
	do{
		scanf("%c",&tekst[i]);
	}while( tekst[i++] );
	br = br_rijeci( tekst );
	if (br){
		bo = br_odlomaka( tekst );
		printf("Zadani tekst sadrzi rijeci/odlomaka: %d/%d\n",br,bo);
	}
	else printf("Zadani tekst ne sadrzi rijeci!\n");
	return 0;

}