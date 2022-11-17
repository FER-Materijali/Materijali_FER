#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "RadSDatotekama.h"
#include "Matrice.h"
#include "PomocneFunkcije.h"

/* Funkcija tretira prvi bit kao bit najmanje težine, radi samo za prirodne brojeve */
int PretvoriBinarniUDekadski(const char *binarne_znamenke)
{
	int dekadski_broj = 0;
	int rbr_binarne_znamenke;
	for(rbr_binarne_znamenke = 0; binarne_znamenke[rbr_binarne_znamenke] != '\0'; rbr_binarne_znamenke++)
	{
		dekadski_broj += (binarne_znamenke[rbr_binarne_znamenke] - '0') * (int)pow(2, rbr_binarne_znamenke);
	}

	return dekadski_broj;
}

char *DekodirajZastitu(char *kod_sa_zastitom, matrica *H_T)
{
	int broj_procitanih_bitova = 0; /* Broj proèitanih bitova zaštitnog koda */
	int popunjenost_koda = 0;

	char *kod = (char*) malloc ( sizeof(char) );
	kod[0] = '\0';
	
	while( MojStrlen(kod_sa_zastitom, broj_procitanih_bitova ) >= (unsigned)n ) /* strlen ima ogranièenja na duljinu */
	{	
		matrica *matrica_koda = (matrica*) malloc ( sizeof(matrica) );
		InicijalizirajMatricu(matrica_koda, n, 1);
		strncpy(matrica_koda->sadrzaj, kod_sa_zastitom + broj_procitanih_bitova, n);
		{
			matrica *sindrom = PomnoziMatrice(matrica_koda, H_T);
			int greska = PretvoriBinarniUDekadski(sindrom->sadrzaj);
			int broj_koji_nije_potencija_broja_2 = 1;

			/* Provjeravamo grešku, ako ima, ispravljamo je */
			if(greska != 0)
			{
				int indeks_greske = greska - 1;
				int vrijednost_bita_kojeg_ispravljamo = matrica_koda->sadrzaj[indeks_greske] - '0';

				vrijednost_bita_kojeg_ispravljamo = (vrijednost_bita_kojeg_ispravljamo + 1) % 2;

				matrica_koda->sadrzaj[indeks_greske] = vrijednost_bita_kojeg_ispravljamo + '0';
			}

			/* Spremamo kod iz zaštitnog koda */
			while(broj_koji_nije_potencija_broja_2 <= n)
			{
				
				while( JeLiPotencijaBroja2(broj_koji_nije_potencija_broja_2) )
				{
					broj_koji_nije_potencija_broja_2++;
				}
				kod = (char*) realloc (kod, sizeof(char) * (popunjenost_koda + 2) ); // +1 za novi simbol, +1 za '\0'
				kod[popunjenost_koda] = matrica_koda->sadrzaj[broj_koji_nije_potencija_broja_2 - 1]; // -1 zbog pretvaranje iz broja u indeks
				kod[popunjenost_koda+1] = '\0';
				popunjenost_koda = popunjenost_koda + 1;
				broj_koji_nije_potencija_broja_2++;
				
			}


			broj_procitanih_bitova = broj_procitanih_bitova + n;
		}
	}
	
	return kod;
}

int main(int argc, char *argv[])
{
	if(argc == 3)
	{
		matrica *H = GenerirajMatricuH();
		matrica *H_T = TransponirajMatricu(H);

		char *kod_sa_zastitom = NULL;
		int greska = ProcitajStringIzDatoteke(&kod_sa_zastitom, argv[1]);

		if( !greska )
		{
			char *kod = DekodirajZastitu(kod_sa_zastitom, H_T);

			ZapisiStringUDatoteku(kod, argv[2]);
		}
		else
		{
			printf("\nDatoteka %s ne postoji", argv[1]);
		}
				
	}
	else
	{
		printf("Nisi upisao dva imena. Jedno za ulaznu, drugo za izlaznu datoteku.");
	}

	return 0;
}