#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "SimbolSaVjerojatnosti.h"
#include "RadSDatotekama.h"
#include "SimbolSaKodom.h"
#include "DobijSimboleSKodom.h"

//Glavni program
int main(int argc, char *argv[])
{
	if(argc == 3)
	{
		char *simboli;
		int greska = ProcitajStringIzDatoteke(&simboli, argv[1]);
			
		if(!greska)
		{
			sik *simboli_s_kodom = PripremiSimboleSKodom();
			char *kod =  KodirajSimbol(simboli, simboli_s_kodom);
		
			UnistiSimboleSaKodom(simboli_s_kodom);
			ZapisiStringUDatoteku(kod, argv[2]);
		}
		else
		{
			printf("\nUlazna datoteka %s ne postoji", argv[2]);
		}
	}
	else
	{
		printf("Nisi upisao dva imena. Jedno za ulaznu, drugo za izlaznu datoteku.");
	}
	
	return 0;
}