#include <stdio.h>
#include <stdlib.h>

struct simboli {  //struktura za pohranu simbola 
	char 	simbol;
	float   vjerojatnost;
	int  	kod[100];
	int     br;
	int		vrh;
}s[256];

typedef struct simboli struktura;

/**
 * Rekurzivna funkcija koja kodira simbole
 */
void shannon(int pocetak, int kraj, struktura s[])
{
	int i,j,k;
	float zbroj1 = 0, zbroj2 = 0, razlika1 = 0, razlika2 = 0;

	if ( (pocetak == kraj) || (pocetak > kraj) ) { // završi rekurziju
		return;
	}

	if ( (kraj - pocetak) == 1) { // samo dva elementa
		s[pocetak].kod[(s[pocetak].vrh)++] = 1;
		s[kraj].kod[(s[kraj].vrh)++] = 0;
		return; // završi rekurziju
	}
	
	zbroj1 = s[pocetak].vjerojatnost; // vjerojatnost 1. simbola
   	for (i=pocetak + 1; i<=kraj; i++) {
		zbroj2 = zbroj2 + s[i].vjerojatnost; // vjerojatnost ostalih simbola
	}

	if (zbroj1 > zbroj2) {
		s[pocetak].kod[(s[pocetak].vrh)++] = 1; // dodaj prvom simbolu 1
		for (i = pocetak + 1; i <= kraj; i++) {
			s[i].kod[(s[i].vrh)++] = 0; // a svim ostlalima 0
		}
		shannon(pocetak +1, kraj, s); // pokrenu funkciju za preostale simbole (kojima je dodana "0")
		return; // završi
	}

	razlika1 = zbroj1 - zbroj2;
	if (razlika1 < 0) {
		razlika1 = razlika1 * -1;
	}

	k = pocetak + 1; //za slucaj da je samo jedan znak
    j=2;
    while(j < kraj - pocetak) { // pokušaj naći bolju raspodjelu
    	k = pocetak + j;

        zbroj1 = zbroj2 = 0;
        for (i=pocetak; i<k; i++) {
			zbroj1 = zbroj1 + s[i].vjerojatnost;
		}

        for (i=k; i<=kraj; i++) {
			zbroj2 = zbroj2 + s[i].vjerojatnost;
		}

        razlika2 = zbroj1 - zbroj2;
        if (razlika2 < 0) {
			razlika2 = razlika2 * -1; 
		}
            
        if (razlika2 >= razlika1) { // ukoliko je nova raspodjela "bolja" koristi nju (niti jedan nakon ove ne može biti bolja jer su simboli sortirani po vjerojatnosti silazno)
			k--;
        	break; // završi petlju
		}
    
        razlika1 = razlika2;
        j++;
    }

    for (i=pocetak; i<k; i++) { // prvom dijelu simbolu dodaj "1"
		s[i].kod[(s[i].vrh)++]=1;
	}
        
    for(i=k;i<=kraj;i++) { // a drugom "0"
		s[i].kod[(s[i].vrh)++]=0;
	}


/*
	printf("Pročitani znak | Kod:\n");
	printf("--------------------------------------\n");
	for (i = 0; i < 8; i++) {
		printf("             %c | ", s[i].simbol);
		for (j = 0; j < s[i].vrh; j++) {
	        printf("%d",s[i].kod[j]);
		}
		printf("\n");
	}
	printf("\n");

*/
        shannon(pocetak, k-1, s); // ponovo pokrenu funkciju za prvi dio simbola
        shannon(k, kraj, s); // i za drugi
}


/**
 * Ulaz u program
 */
int main(int argc, char *argv[])
{
  	int		ukupno_znakova = 0; // ukupan broj znakova 
  	FILE  *in_file, *out_file;  // ulazna datoteka
  	int   ch;			    	// ulazni znak ili oznaka kraja datoteke
	int modulo;					// pomoćna varijabla za dodavanja 0 na kraju kodiranja
	
	int i,j,k,n;				// brojaci
	int upisan;					// pomocna varijabla

	struktura temp;				// pomocna varijabla za soritranje simbola po vjerojatnosti

	int  razlicitih_znakova = 0;

	/* PROVJERI ISPRAVNOST PARAMETARA */
	
    if ( argc != 4 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "Naputak: %s ulaznaDatoteka izlaznaDatoteka datotekaZaPohranuKoda\n", argv[0] );
		exit(1);
    }


  	/* UČITAJ ZNAKOVE IZ DATOTEKE */

  	in_file = fopen(argv[1], "r");
  	if (in_file == NULL) {
      	printf("Ne mogu otvoriti datoteku %s.\n", argv[1]);
      	exit(8);
	}

	while (1) {
      	ch = fgetc(in_file);
      	if (ch == EOF) {
          	break;
		}

		upisan = 0;
		for (i = 0; i < razlicitih_znakova; i++) {
			if (s[i].simbol == ch) { // provjeri da li učitani znak već postoji u polju simbola
				upisan = 1;
				s[i].br++; // ako postoji povećaj mu brojač
				break;
			}
		}

		if (upisan == 0) { // ako znak još uvijek ne postoji u polju simbola
			s[razlicitih_znakova].simbol = ch; 
			s[razlicitih_znakova].br = 1;
			razlicitih_znakova++; // uvecaj brojac razlicitih znakova
		} 

      	++ukupno_znakova; // prati ukupan broj učitanih znakova
  	}
	fclose(in_file);

	/* SORTIRAJ PO BROJU POJAVLJIVANJA */

	n = razlicitih_znakova;
    for(j=1; j<=n-1; j++) {
        for(i=0;i< n-1;i++) {
            if((s[i].br) < (s[i+1].br)) {
                temp.br = s[i].br;
				temp.simbol = s[i].simbol;
                s[i].br = s[i+1].br;
				s[i].simbol = s[i+1].simbol;
                s[i+1].br = temp.br;
				s[i+1].simbol = temp.simbol;
            }
        }
    }	
	
	/* ISPIŠI SIMBOLE I NJIHOV BROJ POJAVLJIVANJA */
/*
	printf("\nSortirani prema broju pojavljivanja:\n");
	printf("====================================\n\n");

	printf("Simbol | Br pojavljivanja\n");
	printf("-------------------------\n");
	for (i = 0; i < n; i++) {
		printf("     %c | %d\n", s[i].simbol, s[i].br);
	}
*/

	/* RAČUNANJE VJEROJATNOSTI */
	
	for (i = 0; i < n; i++) {
		s[i].vjerojatnost = s[i].br / (float) ukupno_znakova;
	}

	for (i = 0; i < n; i++) { // inicijaliziraj vrh (koristi se za zapis koda)
		s[i].vrh = 0;
	}

	/* IZRAČUNAJ KODOVE KORISTEĆI REKURZIVNU FUNKCIJU */

	shannon(0, n-1, s);

	/* ISPIŠI REZULTAT */
/*	
	printf("\nTablica kodova:\n");
	printf("===============\n\n");

	printf("Simbol | Vjerojatnost | Kod\n");
	printf("-----------------------------\n");
	for (i = 0; i < n; i++) {
		printf("     %c | %f     | ", s[i].simbol, s[i].vjerojatnost);
		for (j = 0; j < s[i].vrh; j++) {
	        printf("%d",s[i].kod[j]);
		}
		printf("\n");
	}
*/	
	/* DODAJ 0 DKAKO BI SVI KODOVI IMALI BROJ ZNAKOVA DJELJIV S 4 */
/*
	for (i = 0; i < n; i++) {
		modulo = s[i].vrh % 4;
		switch (modulo) {
		  case 1:
			s[i].kod[(s[i].vrh)++] = 0;
			s[i].kod[(s[i].vrh)++] = 0;
			s[i].kod[(s[i].vrh)++] = 0;
		    break;
		  case 2:
		    s[i].kod[(s[i].vrh)++] = 0;
			s[i].kod[(s[i].vrh)++] = 0;
			break;
		  case 3:
			s[i].kod[(s[i].vrh)++] = 0;
			break;
		} 
	}
*/	
	/* ISPIŠI FINALNI REZULTAT */
/*
	printf("\nTablica kodova nakon dodavanja 0:\n");
	printf("=================================\n\n");

	printf("Simbol | Vjerojatnost | Kod\n");
	printf("-----------------------------\n");
	for (i = 0; i < n; i++) {
		printf("     %c | %f     | ", s[i].simbol, s[i].vjerojatnost);
		for (j = 0; j < s[i].vrh; j++) {
	        printf("%d",s[i].kod[j]);
		}
		printf("\n");
	}	
*/	

	/* ZAPIŠI SIMBOLE U ekoderCode.txt */

  	out_file = fopen(argv[2], "w");
  	if (out_file == NULL) {
      	printf("Ne mogu otvoriti datoteku %s.\n", argv[2]);
      	exit(8);
	}

	for (i=0; i < n; i++) {
		fprintf(out_file, "%c=", s[i].simbol);
		for (j = 0; j < s[i].vrh; j++) {
	        fprintf(out_file, "%d",s[i].kod[j]);
		}
		fprintf(out_file, "\n");
	}
	fclose(out_file);

	/* KODIRAJ ULAZNU DATOTETKU U ekoderOut.txt */

  	in_file = fopen(argv[1], "r");
  	if (in_file == NULL) {
      	printf("Ne mogu otvoriti datoteku %s.\n", argv[1]);
      	exit(8);
	}

  	out_file = fopen(argv[3], "w");
  	if (out_file == NULL) {
      	printf("Ne mogu otvoriti datoteku %s.\n", argv[3]);
      	exit(8);
	}

	k = 0;
	while (1) {
      	ch = fgetc(in_file);
      	if (ch == EOF) {
          	break;
		}

		for (i=0; i<n; i++) {
			if (s[i].simbol == ch) {
				for (j = 0; j < s[i].vrh; j++) {
			        fprintf(out_file, "%d",s[i].kod[j]);
					++k;
				} 
			}
		}
  	}
	// Dodaj 0 na kraj kako bi ukupna duljina koda bila djeljiva sa 4
	if (k != 0) {
		for (i=k; i < 4; i++) {
			fprintf(out_file, "%d", 0);			
		}
	}

	fclose(in_file);


  	return (0);
}


