#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "SimbolSaVjerojatnosti.h"
#include "RadSDatotekama.h"

/* Odredi kumulatvinu vjerojatnost zbraja vjerojatnosti simbola prije sebe */
/* Radi za sve instance strukture simbol i vjerojatnost koje imaju granièni simbol */
siv *OdrediKumulativnuVjerojatnost(siv *osnovni_simboli)
{
	/* Pravim se da ne znam koliko ima osnovnih simbola */
	/* funkcija tako radi za sve instance strukture simbol_i_vjerojatnost koje imaju granièni simbol */
	siv *simboli_sa_kumulativnim_vjerojatnostima = (siv*) malloc ( sizeof(siv) );

	float kumulativna_vjerojatnost = 0;
	int rbr_simbola;
	for(rbr_simbola = 0; osnovni_simboli[rbr_simbola].simbol[0] != '\0'; rbr_simbola++)
	{
		simboli_sa_kumulativnim_vjerojatnostima = (siv*) realloc (simboli_sa_kumulativnim_vjerojatnostima, sizeof(siv) * (rbr_simbola + 1) ); /* +1 je za pretvaranje indeksa u broj */
		simboli_sa_kumulativnim_vjerojatnostima[rbr_simbola].simbol = (char*) malloc ( sizeof(char) * 2); /* jedan za simbol, jedan za '\0' */
		simboli_sa_kumulativnim_vjerojatnostima[rbr_simbola].simbol[0] = osnovni_simboli[rbr_simbola].simbol[0];
		simboli_sa_kumulativnim_vjerojatnostima[rbr_simbola].simbol[1] = '\0';

		kumulativna_vjerojatnost += osnovni_simboli[rbr_simbola].vjerojatnost;
		simboli_sa_kumulativnim_vjerojatnostima[rbr_simbola].vjerojatnost = kumulativna_vjerojatnost;
	}

	/* granièni simbol */
	simboli_sa_kumulativnim_vjerojatnostima = (siv*) realloc (simboli_sa_kumulativnim_vjerojatnostima, sizeof(siv) * (rbr_simbola + 1) );
	simboli_sa_kumulativnim_vjerojatnostima[rbr_simbola].simbol = (char*) malloc ( sizeof(char) ); /* za '\0' */
	simboli_sa_kumulativnim_vjerojatnostima[rbr_simbola].simbol[0] = '\0';
	simboli_sa_kumulativnim_vjerojatnostima[rbr_simbola].vjerojatnost = 1;

	return simboli_sa_kumulativnim_vjerojatnostima;
}

/* Funkcija radi samo za vjeroatnosti koje su kvantizirane sa razlikom 0.01 */
/* (npr. ne razlikuje 0.001 i 0.002, ali razlikuje 0.01 i 0.02) */
char *GenerirajSimbole(siv *simboli_sa_kumulativnim_vjerojatnostima)
{
	const int BROJ_GENERIRANIH_SIMBOLA = 10000; /* Može se mijenjati i ne mijenja se nigdje drugdje :) */
	
	char *simboli = (char*) malloc ( sizeof(char) * (BROJ_GENERIRANIH_SIMBOLA+1) );
	simboli[BROJ_GENERIRANIH_SIMBOLA] = '\0';
	
	srand ( (unsigned int) time(NULL) );
	
	{
		int rbr_generiranog_simbola;	/* trenutni element polja u koji upisujemo simbol */
		for(rbr_generiranog_simbola = 0; rbr_generiranog_simbola < BROJ_GENERIRANIH_SIMBOLA; rbr_generiranog_simbola++)
		{
			/* rezultat je dvoznamenkasti postotak */
			float rezultat = (float)rand();
			rezultat = rezultat / 100;
			rezultat -= (int)rezultat;

			{
				int rbr_simbola_sa_kumulativnom_vjerojatnosti = 0;
				
				/* usporeðuje se rezultat i kumulativna vjerojatnost simbola */
				/* ako je kumulatvna vjerojatnost manja ili jednaka, onda tražimo sljedeæi simbol */
				while(simboli_sa_kumulativnim_vjerojatnostima[rbr_simbola_sa_kumulativnom_vjerojatnosti].vjerojatnost <= rezultat)
				{
					rbr_simbola_sa_kumulativnom_vjerojatnosti++;
				}

				simboli[rbr_generiranog_simbola] = simboli_sa_kumulativnim_vjerojatnostima[rbr_simbola_sa_kumulativnom_vjerojatnosti].simbol[0];
			}

		}
	}

	return simboli;
}

int main(int argc, char *argv[])
{

	char *simboli;
	siv *osnovni_simboli = InicijalizirajOsnovneSimbole();

	siv *simboli_sa_kumulativnim_vjerojatnostima = OdrediKumulativnuVjerojatnost(osnovni_simboli);
	UnistiSimboleSaVjerojatnostima(osnovni_simboli); /* Osnovni simboli nam više ne trebaju pa oslobaðamo memoriju */

	simboli = GenerirajSimbole(simboli_sa_kumulativnim_vjerojatnostima);
	UnistiSimboleSaVjerojatnostima(simboli_sa_kumulativnim_vjerojatnostima); /* Simboli sa kumulativnim vjerojatnostima nam više ne trebaju pa oslobaðamo memoriju */

	if(argc == 2)
	{
		ZapisiStringUDatoteku(simboli, argv[1]);
		free(simboli);
	}
	else if(argc > 2)
	{
		printf("Prihvaæeno ime datoteke je: %s", argv[1]);
		ZapisiStringUDatoteku(simboli, argv[1]);
		free(simboli);
	}
	else
	{
		printf("Nisi upisao jedno ime izlazne datoteke pa koristim datoteku 12.txt");
		ZapisiStringUDatoteku(simboli, "12.txt");
		free(simboli);
	}

	return 0;
}