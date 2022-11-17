#include <malloc.h>

typedef struct simbol_i_vjerojatnost
{
	char *simbol;
	float vjerojatnost;
}siv;

/* Ako želite druge simbole i vjerojatnosti, ovu fuknciju treba promijeniti */
siv *InicijalizirajOsnovneSimbole()
{
	const int BROJ_OSNOVNIH_SIMBOLA = 4; /* Nema smisla mijenjati */
	
	siv *osnovni_simboli = (siv*) malloc ( sizeof(siv) * (BROJ_OSNOVNIH_SIMBOLA+1) );

	/* Generiranje osnovnih simbola */
	{
		int rbr_osnovnog_simbola;
		for(rbr_osnovnog_simbola=0; rbr_osnovnog_simbola < BROJ_OSNOVNIH_SIMBOLA; rbr_osnovnog_simbola++)
		{
			osnovni_simboli[rbr_osnovnog_simbola].simbol = (char*) malloc ( sizeof(char) * 2);				/* Alociranje memorije za simbol (i '\0') */
			osnovni_simboli[rbr_osnovnog_simbola].simbol[0] = 'a' + rbr_osnovnog_simbola;					/* Generiranje simbola (slova) */
			osnovni_simboli[rbr_osnovnog_simbola].simbol[1] = '\0';
			osnovni_simboli[rbr_osnovnog_simbola].vjerojatnost = (float)0.1 * (float)(rbr_osnovnog_simbola+1);	/* Generiranje vjerojatnosti */
		}
	}

	/* granièni simbol - prazni simbol */
	osnovni_simboli[BROJ_OSNOVNIH_SIMBOLA].simbol = (char*) malloc (sizeof(char));
	osnovni_simboli[BROJ_OSNOVNIH_SIMBOLA].simbol[0] = '\0';
	osnovni_simboli[BROJ_OSNOVNIH_SIMBOLA].vjerojatnost = 1;

	return osnovni_simboli;
}

/* Funkcija koja na pravilan naèin oslobaða memoriju od polja strukture simbola i vjerojatnosti */
void UnistiSimboleSaVjerojatnostima(siv *simboli)
{
	int rbr_simbola;
	
	for(rbr_simbola = 0; simboli[rbr_simbola].simbol[0] != '\0'; rbr_simbola++)
	{
		free(simboli[rbr_simbola].simbol);
	}
	
	/* Èišæenje zaštitnog simbola */
	free(simboli[rbr_simbola].simbol);

	free(simboli);
}