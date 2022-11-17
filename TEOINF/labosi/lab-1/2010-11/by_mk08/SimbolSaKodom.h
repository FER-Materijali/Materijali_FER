#include <malloc.h>

typedef struct simbol_i_kod
{
	char *simbol;
	char *kod;
}sik;

void UnistiSimboleSaKodom (sik *simboli_s_kodom)
{
	int rbr_simbola;
	
	for(rbr_simbola = 0; simboli_s_kodom[rbr_simbola].simbol[0] != '\0'; rbr_simbola++)
	{
		free(simboli_s_kodom[rbr_simbola].simbol);
		free(simboli_s_kodom[rbr_simbola].kod);
	}
	
	/* Èišæenje zaštitnog simbola */
	free(simboli_s_kodom[rbr_simbola].simbol);
	free(simboli_s_kodom[rbr_simbola].kod);

	free(simboli_s_kodom);
}