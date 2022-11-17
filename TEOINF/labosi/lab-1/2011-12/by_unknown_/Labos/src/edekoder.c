#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simboli {  //struktura za pohranu simbola 
	char 	simbol;
	int  	kod[100];
	int		vrh;
}s[256];

typedef struct simboli struktura;

/**
 * Ulaz u program
 */
int main(int argc, char *argv[])
{
  	FILE	*in_file, *out_file;  // ulazna datoteka
	
	int ch, i,j,k,n,z,y,trenutno;	// brojaci
	char buffer[100];

	/* PROVJERI ISPRAVNOST PARAMETARA */
	
    if ( argc != 4 ) // provjeri broj parametara
    {
        // argv[0] je ime programa
        printf( "Naputak: %s putanja_do_ulaza/zdekoderOut.txt putanja_do_koda/ekoderCode.txt putanja_do_odredista/odrediste_1.txt\n", argv[0] );
		exit(1);
    }

  	/* UČITAJ KAKO SU ZNAKOVI KODIRANI */

  	in_file = fopen(argv[2], "r");
  	if (in_file == NULL) {
      	printf("Ne mogu otvoriti datoteku %s.\n", argv[2]);
      	exit(8);
	}

	char line [102]; // max duljina linije
	n = 0;
	while (fgets (line,sizeof line, in_file) != NULL ) {
		j = strlen(line);

		s[n].simbol = line[0];
		s[n].vrh = 0;
		for (k=2; k < (j-1); k++) {
			s[n].kod[(s[n].vrh)++] = (int) line[k] - 48;			
		}
		n++;
	}
	fclose (in_file);

	/* ISPIŠI KODOVE */

/*
	printf("\nTablica kodova učitana iz datoteke:\n");
	printf("====================================\n\n");

	printf("Simbol | Kod\n");
	printf("-----------------------------\n");
	for (i = 0; i < n; i++) {
		printf("     %c | ", s[i].simbol);
		for (j = 0; j < s[i].vrh; j++) {
	        printf("%d",s[i].kod[j]);
		}
		printf("\n");
	}	
*/

	/* DEKODIRAJ ULAZ */
		
  	in_file = fopen(argv[1], "r"); // datoteka sa kodiranim podacima
  	if (in_file == NULL) {
      	printf("Ne mogu otvoriti datoteku %s.\n", argv[1]);
      	exit(8);
	}

  	out_file = fopen(argv[3], "w"); // datoteka u koju upisujemo dekodirane podatke
  	if (out_file == NULL) {
      	printf("Ne mogu otvoriti datoteku %s.\n", argv[3]);
      	exit(8);
	}

	k = 0; trenutno = 0;
	while (1) {
      	ch = fgetc(in_file);
      	if (ch == EOF) {
          	break;
		}
		buffer[trenutno++] = ch - 48; // spremi trenutni znak u buffer dok ne prepoznamo cijeli simbol
//		printf("Učitavam znak %c trenutno: %d\n", ch, trenutno);
		for (i=0; i<n; i++) { // za sve simbole
			if (s[i].vrh == trenutno) { // ukoliko je broj znakova u bufferu jedank dužini kodne riječi
				z = 1;
				for (j = 0; j < s[i].vrh; j++) {
					if (buffer[j] != s[i].kod[j]) { // provjeri je li buffer jedank kodu trenutnog simbola
//						printf("buffer od %d != %d\n", buffer[j], s[i].kod[j]);
						z = 0; // ako je barem jedan znak različi nisu jednaki
						break; // izađi iz petlje
					}
				} 
				if (z == 1) { // ako su jednaki
					fprintf(out_file, "%c",s[i].simbol); // zapiši simbol u izlaznu datoteku
					trenutno = 0; // resetiraj buffer
				}
			}
		}
  	}
	fclose(in_file);
	
	return 0;
}


