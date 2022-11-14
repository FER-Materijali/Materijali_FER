#include <stdio.h>
#include "funkcije.h"
#define MAXSTUP 20
#define MAXRED 100
#define MAXZNAK 200

int main( void ){
	int i;
	char str[MAXZNAK+1];
	char polje[MAXRED][MAXSTUP+1];
	int brRijeci, maxRijeci, duljRijeci;
	gets(str);
	scanf("%d%d%d",&brRijeci,&maxRijeci,&duljRijeci);
	rastavi( str, brRijeci, maxRijeci, duljRijeci, polje[0] );

	printf("\n");
	for( i=0; i<maxRijeci; i++ ) printf("%s\n",polje[i]);
	printf("Broj rijeci je: %d\n", brojRijeci( polje[0], maxRijeci ) );
	return 0;
}