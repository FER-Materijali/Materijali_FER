#include<malloc.h>
#include<string.h>
#include<math.h>

#include "PomocneFunkcije.h"

const int n = 7;
const int k = 4;
const int r = 3;

/* matrice */
typedef struct matrica_
{
	char *sadrzaj;
	int duljina;	// broj stupaca
	int visina;		// broj redova
} matrica;

void InicijalizirajMatricu(matrica *ulazna_matrica, const int duljina, const int visina)
{
	ulazna_matrica->duljina = duljina;
	ulazna_matrica->visina = visina;

	ulazna_matrica->sadrzaj = (char*)malloc( sizeof(char)*(duljina*visina+1) );

	{
		int element_matrice;
		for(element_matrice = 0; element_matrice <= duljina * visina; element_matrice++)
		{
			ulazna_matrica->sadrzaj[element_matrice] = '\0';
		}
	}
}

void StaviStupacUMatricu(matrica *ulazna_matrica, const char stupac[], const int lokacija)
{
	unsigned int rbr_retka;

	for(rbr_retka = 0; rbr_retka < strlen(stupac); rbr_retka++)
	{
		ulazna_matrica->sadrzaj[rbr_retka*ulazna_matrica->duljina + lokacija] = stupac[rbr_retka];
	}
}

void ZamijeniStupceUMatrici(matrica *ulazna_matrica, const int rbr_stupca1, const int rbr_stupca2)
{
	int rbr_bita;
	for(rbr_bita = 0; rbr_bita < ulazna_matrica->visina; rbr_bita++)
	{
		/* bit je znamenka koja je u stupcu na lokaciji rbr_bita */
		char bit = ulazna_matrica->sadrzaj[rbr_bita*ulazna_matrica->duljina + rbr_stupca1]; 
		ulazna_matrica->sadrzaj[rbr_bita*ulazna_matrica->duljina + rbr_stupca1] = ulazna_matrica->sadrzaj[rbr_bita*ulazna_matrica->duljina + rbr_stupca2];
		ulazna_matrica->sadrzaj[rbr_bita*ulazna_matrica->duljina + rbr_stupca2] = bit;
	}

	return;
}

int KopirajNStupcaMatrica(const matrica *izvorna_matrica, const int pocetni_stupac_izvorne_matrice, const int zavrsni_stupac_izvorne_matrice, matrica *odredisna_matrica, const int pocetni_stupac_odredisne_matrice)
{
	if(izvorna_matrica->visina == odredisna_matrica->visina)
	{
		int rbr_stupca;
		for(rbr_stupca = 0; rbr_stupca < zavrsni_stupac_izvorne_matrice - pocetni_stupac_izvorne_matrice + 1; rbr_stupca++) 
		{
			int rbr_reda;
			for(rbr_reda = 0; rbr_reda < odredisna_matrica->visina; rbr_reda++)
			{
				int rbr_bita_ulazne_matrice = pocetni_stupac_izvorne_matrice + rbr_stupca + rbr_reda * izvorna_matrica->duljina;
				int rbr_bita_izlazne_matrice = pocetni_stupac_odredisne_matrice + rbr_stupca + rbr_reda * odredisna_matrica->duljina;

				odredisna_matrica->sadrzaj[rbr_bita_izlazne_matrice] = izvorna_matrica->sadrzaj[rbr_bita_ulazne_matrice];
			}
		}
		return 0;
	}
	else
	{
		return 1; //matrice imaju razlièiti broj redova
	}
}

matrica *TransponirajMatricu(matrica *ulazna_matrica)
{
	matrica *transponirana_matrica = (matrica*)malloc( sizeof(matrica) );
	InicijalizirajMatricu(transponirana_matrica, ulazna_matrica->visina, ulazna_matrica->duljina);

	{
		int stupac;	//stupac transponirane matrice, a redak ulazne matrice
		for(stupac = 0; stupac < transponirana_matrica->duljina; stupac++)
		{
			int redak;	//redak transponirane matrice, a stupac ulazne matrice
			for(redak = 0; redak < transponirana_matrica->visina; redak++)
			{
				transponirana_matrica->sadrzaj[ stupac + redak * transponirana_matrica->duljina] =
					ulazna_matrica->sadrzaj[redak + stupac * ulazna_matrica->duljina];
			}
		}
	}

	return transponirana_matrica;
}

int pomnoziRedakSaStupcem(const matrica *ulazna_matrica_redak, const int redak, const matrica *ulazna_matrica_stupac, const int stupac)
{
	if(ulazna_matrica_redak->duljina == ulazna_matrica_stupac->visina)
	{
		int i;
		int zbroj = 0;
		
		for(i = 0; i < ulazna_matrica_redak->duljina; i++)
		{
			const int element_1 = redak * ulazna_matrica_redak->duljina + i; /* element ulazne matrice redak */
			const int element_2 = stupac + ulazna_matrica_stupac->duljina * i; /* element ulazne matrice stupac */
			zbroj += ( ulazna_matrica_redak->sadrzaj[element_1] - '0' ) * ( ulazna_matrica_stupac->sadrzaj[element_2] - '0' );
		}

		return zbroj;
	}
	else
	{
		return -1;
	}
}

matrica *PomnoziMatrice(const matrica *ulazna_matrica_1, const matrica *ulazna_matrica_2)
{
	matrica *matrica_umnoska = (matrica*) malloc ( sizeof(matrica) );
	InicijalizirajMatricu(matrica_umnoska, ulazna_matrica_2->duljina, ulazna_matrica_1->visina);

	{
		int red_matrice_umnoska;
		for(red_matrice_umnoska = 0; red_matrice_umnoska < matrica_umnoska->visina; red_matrice_umnoska++)
		{
			int stupac_matrice_umnoska; /* ujedno i red ulazne matrice 2 */
			for(stupac_matrice_umnoska = 0; stupac_matrice_umnoska < matrica_umnoska->duljina; stupac_matrice_umnoska++)
			{
				const int rbr_elementa_umnoska_matrica = red_matrice_umnoska * matrica_umnoska->duljina + stupac_matrice_umnoska;
				matrica_umnoska->sadrzaj[rbr_elementa_umnoska_matrica] = 
					pomnoziRedakSaStupcem(ulazna_matrica_1, red_matrice_umnoska, ulazna_matrica_2, stupac_matrice_umnoska) % 2 + '0';
			}
		}
	}

	matrica_umnoska->sadrzaj[matrica_umnoska->duljina * matrica_umnoska->visina] = '\0';

	return matrica_umnoska;
}

/* Koder kanala */
matrica *GenerirajMatricuH()
{
	int rbr_stupca;
	char *stupac;
	matrica *H;

	H = (matrica*)malloc( sizeof(matrica) );
	InicijalizirajMatricu(H, n, r);

	stupac = (char*)malloc( sizeof(char)*(r+1) );

	for (rbr_stupca = 0; rbr_stupca < n; rbr_stupca++)
	{
		int broj = rbr_stupca + 1;	// cjelobrojni broj koji æe se pretvarati u binarni
		int rbr_bita;
		for(rbr_bita = 0; rbr_bita < r; rbr_bita++)
		{
			stupac[r - rbr_bita - 1] = (int)( broj / pow(2, r - rbr_bita - 1) ) % 2 + '0';
		}
		stupac[rbr_bita] = '\0';
		StaviStupacUMatricu(H, stupac, rbr_stupca);
	}
	
	return H;
}

void PretvoriUJedinicnuMatricu(matrica *ulazna_matrica)
{

	int rbr_stupca;

	for(rbr_stupca = 0; rbr_stupca < ulazna_matrica->duljina; rbr_stupca++)
	{
		int rbr_bita;
		int broj_bita_1 = 0;
		int lokacija_bita_1;

		for(rbr_bita = 0; rbr_bita < r; rbr_bita++)
		{
			if(ulazna_matrica->sadrzaj[ rbr_stupca + ulazna_matrica->duljina * rbr_bita ] == '1') //provjeravamo bitove
			{
				broj_bita_1++;
				lokacija_bita_1 = rbr_bita;	//redni broj bita (reda) je ujedno i redni broj stupca jediniène matrice

				if(broj_bita_1 == 2)	//ako je broj bitova 1 veæi od 1, onda znaèi da to nije stupac koji stvara jediniènu matricu
				{
					break;
				}
			}
		}

		if( (broj_bita_1 == 1) && (lokacija_bita_1 != rbr_stupca) )
		{
			 ZamijeniStupceUMatrici(ulazna_matrica, lokacija_bita_1, rbr_stupca);
		}

	}
}

matrica *NapraviGenerirajucuMatricuOdMatrice(const matrica *ulazna_matrica)
{
	matrica *izlazna_matrica = (matrica*)malloc( sizeof(matrica) );
	InicijalizirajMatricu(izlazna_matrica, ulazna_matrica->duljina + ulazna_matrica->visina, ulazna_matrica->visina);

	{
		int stupac;
		int broj_jedinicnog_stupca = 0;
		int broj_stupca_ulazne_matrice = 0;
		for(stupac = 0; stupac < izlazna_matrica->duljina; stupac++)
		{
			if ( JeLiPotencijaBroja2(stupac+1) ) //ako je redni broj stupca potencija broja 2, kopiramo stupac ulazne matrice
			{
				KopirajNStupcaMatrica(ulazna_matrica, broj_stupca_ulazne_matrice, broj_stupca_ulazne_matrice, izlazna_matrica, stupac);
				broj_stupca_ulazne_matrice++;
			}
			else	// ako redni broj stupca nije potencija broja 2, stavljamo jedinièni stupac
			{
				int redak;
				for(redak = 0; redak < izlazna_matrica->visina; redak++)
				{
					int rbr_elementa = stupac + redak * izlazna_matrica->duljina;
					
					if(redak != broj_jedinicnog_stupca)
					{						
						izlazna_matrica->sadrzaj[rbr_elementa] = '0';
					}
					else
					{
						izlazna_matrica->sadrzaj[rbr_elementa] = '1';
					}
				}
				broj_jedinicnog_stupca++;
			}
		}
	}

	return izlazna_matrica;
}

matrica *PripremiMatricuG()
{
	matrica *G;
	{
		matrica *A_T;
		{
			matrica *A;
			A = (matrica*)malloc( sizeof(matrica) );
			
			{
				matrica *H;
				H = GenerirajMatricuH();
				PretvoriUJedinicnuMatricu(H);
				
				InicijalizirajMatricu(A, H->duljina - r, H->visina);
				KopirajNStupcaMatrica(H, r, H->duljina - 1, A, 0); //duljina nije indeks, pa se umanjuje za 1
			}
			A_T = TransponirajMatricu(A);
		}
		G = NapraviGenerirajucuMatricuOdMatrice(A_T);
	}
		
	return G;
}