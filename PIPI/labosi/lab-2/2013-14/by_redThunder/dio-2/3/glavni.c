#include <stdio.h>
#include "funkcije.h"
#define MAX 20

int main( void ){
	int s1[MAX], s2[MAX],s3[MAX];
	int brs1, brs2;
	brs1 = ucitaj(s1);
	brs2 = ucitaj(s2);
	
	unija(brs1,s1,brs2,s2,0,s3);

	printf("Skup 1 %s podskup skupa 2\n", je_podskup(brs1, s1, brs2, s2) ? "JE" : "NIJE" );
	printf("Skup 2 %s podskup skupa 1\n", je_podskup(brs2, s2, brs1, s1) ? "JE" : "NIJE" );
	
	return 0;
}