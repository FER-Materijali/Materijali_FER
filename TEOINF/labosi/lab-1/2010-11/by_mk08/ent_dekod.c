#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "RadSDatotekama.h"
#include "SimbolSaVjerojatnosti.h"
#include "SimbolSaKodom.h"
#include "DobijSimboleSKodom.h"
#include "PomocneFunkcije.h"

/* **Novo** Dekoder */
char * DekodirajSimbole(char kod[], sik *simboli_s_kodom)
{
	int broj_pretvorenih_bitova = 0;
	int popunjenost_simbola = 0;

	char *simboli = (char*) malloc ( sizeof(char) );
	simboli[0] = '\0';

	while( MojStrlen(kod, broj_pretvorenih_bitova) != 0 )
	{
		int rbr_simbola_s_kodom;
		for(rbr_simbola_s_kodom = 0; simboli_s_kodom[rbr_simbola_s_kodom].simbol[0] != '\0'; rbr_simbola_s_kodom++)
		{
			/* Provjeravamo ulazni kod sa kodom simbola (za duljinu odabiremo duljinu koda simbola) */
			if( strncmp(kod + broj_pretvorenih_bitova, simboli_s_kodom[rbr_simbola_s_kodom].kod, strlen(simboli_s_kodom[rbr_simbola_s_kodom].kod) ) == 0 )
			{
				simboli = (char*) realloc (simboli, sizeof(char) * (popunjenost_simbola + strlen(simboli_s_kodom[rbr_simbola_s_kodom].simbol) + 1) );
				strcat(simboli, simboli_s_kodom[rbr_simbola_s_kodom].simbol);
				popunjenost_simbola += strlen(simboli_s_kodom[rbr_simbola_s_kodom].simbol);
				broj_pretvorenih_bitova += strlen(simboli_s_kodom[rbr_simbola_s_kodom].kod);
				break;
			}
		}

		/* Ako kod se ne podudara sa ni jednim kodom u tablici, odbacujemo jedan bit */
		if(simboli_s_kodom[rbr_simbola_s_kodom].simbol[0] == '\0')
		{
			broj_pretvorenih_bitova++;
		}
	}
	return simboli;
}

//Glavni program
int main(int argc, char *argv[])
{
	if(argc == 3)
	{
			char *kod;
			int greska = ProcitajStringIzDatoteke(&kod, argv[1]);

			if (!greska)
			{
				sik *simboli_s_kodom = PripremiSimboleSKodom();
				char *simboli =  DekodirajSimbole(kod, simboli_s_kodom);
		
				UnistiSimboleSaKodom(simboli_s_kodom);

				ZapisiStringUDatoteku(simboli, argv[2]);
			}
			else
			{
				printf("\nIzvorišna datoteka ne postoji!");
			}
	}
	else
	{
		printf("Nisi upisao dva imena. Jedno za ulaznu, drugo za izlaznu datoteku.");
	}
	
	return 0;
}