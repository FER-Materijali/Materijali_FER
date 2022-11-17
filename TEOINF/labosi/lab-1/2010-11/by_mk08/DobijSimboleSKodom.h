/* Huffmanov m, može se mijenjati :D */

const int m = 2;

siv *KopirajSimbole(const siv *osnovni_simboli)
{
	siv *kopije_simbola = NULL;

	int rbr_simbola;
	for(rbr_simbola = 0; osnovni_simboli[rbr_simbola].simbol[0] != '\0'; rbr_simbola++)
	{
		kopije_simbola = (siv*) realloc (kopije_simbola, sizeof(siv) * (rbr_simbola + 1) );
		
		{
			int duljina_simbola = strlen(osnovni_simboli[rbr_simbola].simbol);
			kopije_simbola[rbr_simbola].simbol = (char*) malloc ( sizeof(char) * (duljina_simbola+1) );
		}

		strcpy(kopije_simbola[rbr_simbola].simbol, osnovni_simboli[rbr_simbola].simbol);
		kopije_simbola[rbr_simbola].vjerojatnost = osnovni_simboli[rbr_simbola].vjerojatnost;
	}
	
	/* granièni simbol - prazni simbol */
	kopije_simbola = (siv*) realloc (kopije_simbola, sizeof(siv) * (rbr_simbola + 1) );
	kopije_simbola[rbr_simbola].simbol = (char*) malloc (sizeof(char));
	kopije_simbola[rbr_simbola].simbol[0] = '\0';
	kopije_simbola[rbr_simbola].vjerojatnost = 1;

	return kopije_simbola;
}

siv *Grupiraj(const siv *osnovni_simboli, siv *grupirani_simboli)
{
	siv *novi_grupirani_simboli = NULL;

	int rbr_novi_grupiran_simboli = 0;
		
	int rbr_osnovnog_simbola;
	for(rbr_osnovnog_simbola = 0; osnovni_simboli[rbr_osnovnog_simbola].simbol[0] != '\0'; rbr_osnovnog_simbola++)
	{
		int rbr_grupiranog_simbola;
		for(rbr_grupiranog_simbola = 0; grupirani_simboli[rbr_grupiranog_simbola].simbol[0] != '\0'; rbr_grupiranog_simbola++)
		{
			novi_grupirani_simboli = (siv*) realloc (novi_grupirani_simboli, sizeof(siv) * (rbr_novi_grupiran_simboli + 1) );

			{
				const int duljina_simbola = strlen(osnovni_simboli[rbr_osnovnog_simbola].simbol) + strlen(grupirani_simboli[rbr_grupiranog_simbola].simbol);
				novi_grupirani_simboli[rbr_novi_grupiran_simboli].simbol = (char*) malloc ( sizeof(char) * (duljina_simbola + 1) );
			}
			strcpy(novi_grupirani_simboli[rbr_novi_grupiran_simboli].simbol, osnovni_simboli[rbr_osnovnog_simbola].simbol);
			strcat(novi_grupirani_simboli[rbr_novi_grupiran_simboli].simbol, grupirani_simboli[rbr_grupiranog_simbola].simbol);

			novi_grupirani_simboli[rbr_novi_grupiran_simboli].vjerojatnost = osnovni_simboli[rbr_osnovnog_simbola].vjerojatnost * grupirani_simboli[rbr_grupiranog_simbola].vjerojatnost;
				
			rbr_novi_grupiran_simboli++;
		}
	}

	/* graniènik - oznaèava kraj niza grupiranih simbola - prazni simbol */
	novi_grupirani_simboli = (siv*) realloc (novi_grupirani_simboli, sizeof(siv) * (rbr_novi_grupiran_simboli + 1) );
	novi_grupirani_simboli[rbr_novi_grupiran_simboli].simbol = (char*)realloc(NULL, sizeof(char));
	novi_grupirani_simboli[rbr_novi_grupiran_simboli].simbol[0] = '\0'; 
	novi_grupirani_simboli[rbr_novi_grupiran_simboli].vjerojatnost = 1;

	return novi_grupirani_simboli;
}

sik *InicijalizirajSimboleSKodom(const siv *grupirani_simboli)
{
	int rbr_simbola;

	sik *simboli_s_kodom = NULL;
	
	for(rbr_simbola = 0; grupirani_simboli[rbr_simbola].simbol[0] != '\0'; rbr_simbola++)
	{
		simboli_s_kodom = (sik *) realloc (simboli_s_kodom, sizeof(sik) * (rbr_simbola + 1) );
		
		{
			const int duljina_simbola = strlen(grupirani_simboli[rbr_simbola].simbol);
			simboli_s_kodom[rbr_simbola].simbol = (char*) malloc ( sizeof(char) * (duljina_simbola + 1) );
		}
		strcpy(simboli_s_kodom[rbr_simbola].simbol, grupirani_simboli[rbr_simbola].simbol);
				
		simboli_s_kodom[rbr_simbola].kod = (char*)realloc(NULL,sizeof(char));
		simboli_s_kodom[rbr_simbola].kod[0] = '\0';
	}
	
	/* graniènik - oznaèava kraj niza simbola s kodom */
	simboli_s_kodom = (sik *) realloc (simboli_s_kodom, sizeof(sik) * (rbr_simbola + 1) );

	simboli_s_kodom[rbr_simbola].simbol = (char*)realloc(NULL, sizeof(char));
	simboli_s_kodom[rbr_simbola].simbol[0] = '\0'; 
	
	simboli_s_kodom[rbr_simbola].kod = (char*)realloc(NULL,sizeof(char));
	simboli_s_kodom[rbr_simbola].kod[0] = '\0';

	return simboli_s_kodom;
}

/* Dodijeli kod prima kod koji treba dati svim simbolima nadsimbola */
void DodijeliKod(const int kod, const char *nadsimbol, sik *simboli_s_kodom)
{
	int trenutni_znak = 0;

	while(nadsimbol[trenutni_znak] != '\0')
	{
		char *simbol = (char*) malloc ( sizeof(char)*(m+1) );
			
		{
			int rbr_simbola;
			for(rbr_simbola = 0; rbr_simbola < m; rbr_simbola++)
			{
				simbol[rbr_simbola] = nadsimbol[rbr_simbola+trenutni_znak];
			}	
			simbol[m] = '\0';
		}

		trenutni_znak += m;

		{
			int rbr_simbola_s_kodom;
			for(rbr_simbola_s_kodom = 0; simboli_s_kodom[rbr_simbola_s_kodom].simbol[0] != '\0'; rbr_simbola_s_kodom++)
			{
				int ISTI_SU = !strcmp(simbol, simboli_s_kodom[rbr_simbola_s_kodom].simbol);
			
				if(ISTI_SU)
				{
					int stara_duljina_koda = strlen(simboli_s_kodom[rbr_simbola_s_kodom].kod);
					char *novi_kod = malloc ( sizeof(char)*(stara_duljina_koda+2) );	//+1 za novi bit koda, +1 za \0

					novi_kod[0] = kod + '0';
					novi_kod[1] = '\0';
					strcat(novi_kod, simboli_s_kodom[rbr_simbola_s_kodom].kod);

					simboli_s_kodom[rbr_simbola_s_kodom].kod = novi_kod;
					break;
				}
			}
		}
	}
}

void ZamijeniSimbole(siv *simboli_s_kodom_i, siv *simboli_s_kodom_j)
{
	siv privemeno_skladiste;
	privemeno_skladiste = *simboli_s_kodom_i;
	*simboli_s_kodom_i = *simboli_s_kodom_j;
	*simboli_s_kodom_j = privemeno_skladiste;
}

void SortirajPoVjerojatnosti(siv *grupirani_simboli)
{
	int i, j;
	for(i = 0; grupirani_simboli[i].simbol[0] != '\0'; i++)
	{
		for(j = i + 1; grupirani_simboli[j].simbol[0] != '\0'; j++)
		{
			if(grupirani_simboli[i].vjerojatnost < grupirani_simboli[j].vjerojatnost)
			{
				ZamijeniSimbole(&grupirani_simboli[i], &grupirani_simboli[j]);
			}
		}
	}
}

void SortirajPoAbecedi(siv *grupirani_simboli)
{
	int i, j;
	for(i = 0; grupirani_simboli[i].simbol[0] != '\0'; i++)
	{
		for(j = i+1; grupirani_simboli[j].simbol[0] != '\0'; j++)
		{
			const int ISTA_VJEROJATNOST = (grupirani_simboli[i].vjerojatnost == grupirani_simboli[j].vjerojatnost);
			const int PRVI_ABECEDNO_VECI = ( strcmp(grupirani_simboli[i].simbol, grupirani_simboli[j].simbol) > 0 );

			if(ISTA_VJEROJATNOST && PRVI_ABECEDNO_VECI)
			{
				ZamijeniSimbole(&grupirani_simboli[i], &grupirani_simboli[j]);
			}
		}
	}
}

void SagradiStablo(siv *grupirani_simboli, sik *simboli_s_kodom)
{
	const int BROJ_KANALA = 2; /* Broj kanala, tj. baza brojevnog sustava */
	int broj_simbola = 0;

	while(grupirani_simboli[broj_simbola].simbol[0] != '\0')
	{
		broj_simbola++;
	}

	if(broj_simbola == 1)
	{
		return;
	}
	
	SortirajPoVjerojatnosti(grupirani_simboli);

	SortirajPoAbecedi(grupirani_simboli);

	/* Dodjeljivanje koda najmanjevjerojatnim simbolima*/
	{
		int kod;
		for(kod = 0; kod < BROJ_KANALA; kod++)
		{
			DodijeliKod(kod, grupirani_simboli[broj_simbola-1-kod].simbol, simboli_s_kodom);
		}
	}

	//pretvaranje najmanjevjerojatih simbola u nadsimbol
	{
		
		int duljina_nadsimbola = 0;

		char *simbol = NULL;
		float vjerojatnost = 0;
		
		int i;

		for(i = 0; i < BROJ_KANALA; i++)
		{
			int duljina_simbola = strlen(grupirani_simboli[broj_simbola-BROJ_KANALA+i].simbol);
			duljina_nadsimbola += duljina_simbola;

			simbol = (char*) realloc (simbol, sizeof(char)*(duljina_nadsimbola+1) );

			if(i == 0)
			{
				strcpy(simbol, grupirani_simboli[broj_simbola-BROJ_KANALA+i].simbol);
				vjerojatnost = grupirani_simboli[broj_simbola-BROJ_KANALA+i].vjerojatnost;
			}
			else
			{
				strcat(simbol, grupirani_simboli[broj_simbola-BROJ_KANALA+i].simbol);
				vjerojatnost += grupirani_simboli[broj_simbola-BROJ_KANALA+i].vjerojatnost;
			}
		}
		
		free(grupirani_simboli[broj_simbola-BROJ_KANALA].simbol);
		grupirani_simboli[broj_simbola-BROJ_KANALA].simbol = simbol;

		grupirani_simboli[broj_simbola-BROJ_KANALA].vjerojatnost = vjerojatnost;

		/* Kopiramo zaštitni simbol */
		for(i = 0; i < BROJ_KANALA - 1; i++)
		{
			grupirani_simboli[broj_simbola-i-1] = grupirani_simboli[broj_simbola];
		}
	}

	SagradiStablo(grupirani_simboli, simboli_s_kodom);
}

char *KodirajSimbol(const char *ulazni_simboli, const sik *simboli_s_kodom)
{
	int i;
	int duljina_poruke = 0;
	char *kodirana_poruka;

	kodirana_poruka = (char*)malloc(sizeof(char));
	kodirana_poruka[0] = '\0';

	for(i=0; ulazni_simboli[i] != '\0'; i+=m)
	{
		char *zdruzeni_simbol = (char*) malloc ( sizeof(char)*(m+1) );
		int j;
		int rbr_simbola = 0;

		for(j=0; j<m; j++)
		{
			/* Ako broj simbola nije dijeljiv sa m, zadnje simbole odbacujemo */
			if(ulazni_simboli[i+j] != '\0')
				zdruzeni_simbol[j] = ulazni_simboli[i+j];
			else
				return kodirana_poruka;
		}

		zdruzeni_simbol[m] = '\0';

		do
		{
			const int ISTI_SU = !strcmp(zdruzeni_simbol, simboli_s_kodom[rbr_simbola].simbol);
			if(ISTI_SU)
			{
				duljina_poruke += strlen(simboli_s_kodom[rbr_simbola].kod);
				kodirana_poruka = (char*)realloc(kodirana_poruka, sizeof(char)*(duljina_poruke+1));
				strcat(kodirana_poruka, simboli_s_kodom[rbr_simbola].kod);
				break;
			}
			rbr_simbola++;
		}while(1);

	}

	return kodirana_poruka;
}

siv *GrupirajSimbole(const siv *osnovni_simboli)
{
	siv *grupirani_simboli = KopirajSimbole(osnovni_simboli);

	int iteracija_grupiranja;
	for(iteracija_grupiranja = 0; iteracija_grupiranja < m - 1; iteracija_grupiranja++) /* -1 zato jer kopiranje vec daje Huffmana sa m = 1 */
	{
		siv *novi_grupirani_simboli;
		novi_grupirani_simboli = Grupiraj(osnovni_simboli, grupirani_simboli);
		UnistiSimboleSaVjerojatnostima(grupirani_simboli);
		grupirani_simboli = novi_grupirani_simboli;
	}

	return grupirani_simboli;
}

sik *PripremiSimboleSKodom()
{
	sik *simboli_s_kodom;
		
	{
		siv *grupirani_simboli;
		{
			siv *osnovni_simboli = InicijalizirajOsnovneSimbole();
			grupirani_simboli= GrupirajSimbole(osnovni_simboli);
			UnistiSimboleSaVjerojatnostima(osnovni_simboli);
		}
			
		/* Sortiram grupirane simbole po vjerojatnosti kako bi simboli s kodom bili sortirani po vjerojatnostima */
		SortirajPoVjerojatnosti(grupirani_simboli);

		simboli_s_kodom = InicijalizirajSimboleSKodom(grupirani_simboli);
			
		SagradiStablo(grupirani_simboli, simboli_s_kodom);

		UnistiSimboleSaVjerojatnostima(grupirani_simboli);
	}

	return simboli_s_kodom;
}