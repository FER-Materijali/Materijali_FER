#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "RadSDatotekama.h"
#include "PomocneFunkcije.h"
#include "Matrice.h"

char *ZastitiKod(char kod[], matrica *G)
{
	int velicina_koda_sa_zastitom = n;
	int broj_procitanih_bitova = 0;

	char *kod_sa_zastitom = (char*) malloc (sizeof(char) * (velicina_koda_sa_zastitom + 1) );
	kod_sa_zastitom[0] = '\0';
	
	while( MojStrlen(kod, broj_procitanih_bitova ) >= (unsigned)(n-r) ) /* strlen ima ogranièenja na duljinu */
	{	
		matrica *matrica_koda = (matrica*) malloc ( sizeof(matrica) );
		InicijalizirajMatricu(matrica_koda, n-r, 1);
		strncpy(matrica_koda->sadrzaj, kod + broj_procitanih_bitova, n-r);
		{
			matrica *matrica_umnoska = PomnoziMatrice(matrica_koda, G);
			strcat(kod_sa_zastitom, matrica_umnoska->sadrzaj);
			broj_procitanih_bitova = broj_procitanih_bitova + n - r;

			velicina_koda_sa_zastitom += n;
			kod_sa_zastitom = (char*) realloc (kod_sa_zastitom, sizeof(char) * (velicina_koda_sa_zastitom +1) );		
		}
	}
	
	return kod_sa_zastitom;
}

char *NapraviSmetnju(int duljina_koda)
{
	const float VJEROJATNOST_SMETNJE = (float)1/(float)5;
	char *smetnja = (char*) malloc ( sizeof(char) * (duljina_koda + 1) );

	srand ( (unsigned int) time(NULL) );

	{
		int rbr_bita;
		for(rbr_bita = 0; rbr_bita < duljina_koda; rbr_bita++)
		{
			float rezultat = (float)rand();
			rezultat = rezultat / 100;
			rezultat = rezultat - (int)rezultat;
			
			if(rezultat <= VJEROJATNOST_SMETNJE)
				smetnja[rbr_bita] = '1';
			else
				smetnja[rbr_bita] = '0';
		}
	}

	smetnja[duljina_koda] = '\0';

	return smetnja;
}

int main(int argc, char *argv[])
{
	if(argc == 3)
	{
		matrica *G = PripremiMatricuG();

		char *kod = NULL;
		int greska = ProcitajStringIzDatoteke(&kod, argv[1]);
			
		if( !greska)
		{
			char *kod_sa_zastitom = ZastitiKod(kod, G);

			ZapisiStringUDatoteku(kod_sa_zastitom, argv[2]);
			{
				char *smetnja = NapraviSmetnju( MojStrlen(kod_sa_zastitom, 0) );
				ZapisiStringUDatoteku(smetnja, "err_vec.txt");
			}
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