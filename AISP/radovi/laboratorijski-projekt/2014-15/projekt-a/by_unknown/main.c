#define _CRT_SECURE_NO_DEPRECATE //treba ako radite u Visual studiju (prigovara da funkcija strcpy nije sigurna i ne zeli kompajlirati)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "algoritam_alt.h"
#include "nadji.h"
#include "dodatno.h"

int main() {
	long blok;
	char test_imeprezime[ 51 ], outbuf[ 1001 ] = { '\0' };
	clock_t tpoc, tkraj;
	int hit = 0, miss = 0;
	float trajanje;
	char *izldat_naziv;
	FILE *fpodaci, *ftest, *fizlaz;

	izldat_naziv = izl_naziv();
	if( !( fpodaci = fopen( DATOTEKA_PODACI, "rb" ) ) ) {
		fprintf( stderr, "Ne mogu otvoriti datoteku %s za citanje\n", DATOTEKA_PODACI );
		exit( -1 );
	}
	if( !( ftest = fopen( DATOTEKA_TEST, "rb" ) ) ) {
		fprintf( stderr, "Ne mogu otvoriti datoteku %s za citanje\n", DATOTEKA_TEST );
		exit( -1 );
	}
	if( !( fizlaz = fopen( izldat_naziv, "w" ) ) ) {
		fprintf( stderr, "ne mogu otvoriti datoteku %s za pisanje\n", izldat_naziv );
		exit( -1 );
	}

	inicijaliziraj( fpodaci );
	tpoc = clock();

	while( fread( test_imeprezime, sizeof( test_imeprezime ), 1, ftest ) ) {
		blok = nadji_blok( test_imeprezime, fpodaci );
		if( nadji( test_imeprezime, fpodaci, blok )  == -1 ) {
			miss++;
		}
		else {
			hit++;
		}
	}

	tkraj = clock();
	trajanje = ( float )( tkraj - tpoc ) / CLOCKS_PER_SEC;

	sprintf( outbuf, "*** Statistika izvodjenja ***\n" );
	sprintf( &outbuf[ strlen( outbuf ) ], "Vrijeme izvodjenja:  %-5.3f s\n", trajanje );
	sprintf( &outbuf[ strlen( outbuf ) ], "Pronadjeno zapisa:   %-3d / %4d\n", hit, hit + miss );
	sprintf( &outbuf[ strlen( outbuf ) ], "Nepostojecih zapisa: %-3d / %4d\n", miss, hit + miss );
	fprintf( fizlaz, outbuf );
	printf( outbuf );

	fclose( fizlaz );
	fclose( ftest );
	fclose( fpodaci );
	return 0;
}
