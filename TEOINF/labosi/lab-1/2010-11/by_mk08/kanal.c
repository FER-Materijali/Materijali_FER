#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

char *ProcitajStringIzDatoteke(char izvorna_datoteka[])
{	
	char *ulazni_simboli = (char*) malloc ( sizeof(char) );
	int rbr_simbola = 0;
	
	FILE *fp_izvor = fopen(izvorna_datoteka, "r");
	
	if(fp_izvor == NULL)
	{
		printf("Izvorna datoteka ne postoji!");
		exit(1);
	}
	while(fscanf(fp_izvor, "%c", &ulazni_simboli[rbr_simbola]) != EOF)
	{
		rbr_simbola++;

		/* Poveæavamo polje kako bi prihvatio i sljedeæi simbol */
		ulazni_simboli = (char*) realloc (ulazni_simboli, sizeof(char) * (rbr_simbola + 1) ); 
	}
	ulazni_simboli[rbr_simbola] = '\0';

	fclose(fp_izvor);

	return ulazni_simboli;
}

void ZapisiStringUDatoteku(char *kod_sa_zastitom, char odredisna_datoteka[])
{
	FILE *fp_odrediste = fopen(odredisna_datoteka, "w");
	int rbr_simbola = 0;
	
	while(kod_sa_zastitom[rbr_simbola] != '\0')
	{
		fprintf(fp_odrediste, "%c", kod_sa_zastitom[rbr_simbola]);
		rbr_simbola++;
	}

	fclose(fp_odrediste);
}

unsigned long int MojStrlen(char *string, int pomak)
{
	unsigned long int brojilo = 0;

	while(string[pomak+brojilo] != '\0')
	{
		brojilo++;
	}

	return brojilo;
}

int main(int argc, char *argv[])
{
	if (argc == 3 || argc == 4)
	{
		char *ulazni_kod = ProcitajStringIzDatoteke(argv[1]);
		char *smetnje;

		if(argc == 3)
		{
			smetnje = ProcitajStringIzDatoteke("err_vec.txt");
		}
		else if(argc == 4)
		{
			smetnje = ProcitajStringIzDatoteke(argv[3]);
		}

		if( MojStrlen(ulazni_kod, 0) == MojStrlen(smetnje, 0) )
		{
			char *pokvareni_kod = (char*) malloc ( sizeof(char) * (MojStrlen(ulazni_kod, 0)+1) );
		
			int rbr_bita;
			for(rbr_bita = 0; rbr_bita < MojStrlen(ulazni_kod, 0); rbr_bita++)
			{
				/* Pretvaramo char u int, zbrojimo, napravimo mod2 i pretvorimo int u char */
				pokvareni_kod[rbr_bita] = ( ( (ulazni_kod[rbr_bita] -'0') + (smetnje[rbr_bita] -'0') ) %2 ) + '0';
			}

			pokvareni_kod[MojStrlen(ulazni_kod, 0)] = '\0';

			ZapisiStringUDatoteku(pokvareni_kod, argv[2]);

			return 0;
		}
		else
		{
			printf("Ulazni kod i smetnje nisu iste duljine!");
			return 1;
		}
	}
	else
	{
		printf("Nisi upisao dva imena. Jedno za ulaznu, drugo za izlaznu datoteku (a možeš i teæu za vektor greške :) ).");
	}
}