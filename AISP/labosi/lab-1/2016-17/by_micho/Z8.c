#include<stdio.h>
#include<stdlib.h>

char *cleanup(char *niz, int *n)								//niz je pointer na originalan niz, n je pointer na vrijednost velicine polja, objasnit cu zasto ne samo varijabla
{
	char *povrat = NULL, *nniz;									//povrat ce biti pointer na novi niz.
	int brojac = 0;												//brojac broji broj elemenata novog niza. Znaci ne broji ako je trenutni i sljedeci element = ' '.
	short i;
	
	nniz = (char*)malloc(*n * sizeof(char));					//Prvo cemo napraviti novi niz koji je BAREM jednako velik kao i niz kojeg popravljamo.
	
	for(i = 0; niz[i] != 0; i++)								//Dok stari niz ne dodje do kraja prepisujemo prave vrijednosti u novi niz
	{
		if((niz[i] == ' ') && (niz[i+1] == ' '))
		continue;
		else
		{
			nniz[brojac++] = niz[i];							//Ovaj brojac ide po indeksima novog niza. Na kraju petlje on ce biti na indeksu zadnjeg elementa, /0.
		}
	}
	
	nniz[brojac] = 0;											//Postavljamo zadnji element na 0, tj. zatvaramo string.
	
	*n = brojac + 1;											//Novi broj elemenata upisujemo u onaj n kojeg smo imali za argument. Ovime unistavamo velicinu starog niza.
	nniz = (char*)realloc(nniz, *n * sizeof(char));				//Realociramo novi niz kako bi ustedili na memoriji. Rjesavamo se memorije koje ne koristimo.
	
	povrat = nniz;												//Na kraju pointeru koji vracamo damo vrijednost naseg novog niza.
	return povrat;
}

void spc(int x)
{
     while(x--)
     printf("\n");
}

int main()
{
	int n = 0;
	int *pn = &n;												//Pokazivac na nasu varijablu n.
	short i;
	
	char *nniz, *niz = (char*)malloc(10000 * sizeof(char));	//Ne znamo koliko ce nam biti polje. Ja bih mogao dinamicki alocirati memoriju kako pisem niz,
															//ali to jos nismo radili, pa cu pretpostaviti da najvece polje ima nenul 9999 znakova.
	
	printf("Upisite niz znakova koje zelite ocistiti od redundantnih razmaka: ");
	gets(niz);
	spc(2);
	
	for(i = 0; niz[i] != 0; i++)
	n++;													//Brojimo koliko elementa ima u nizu.
	
	niz = (char*)realloc(niz, (n+1) * sizeof(char));		//Sada cemo onih rezerviranih 10000 mjesta realocirati tako da zauzimaju samo onoliko mjesta koliko je potrebno.								
	
	nniz = cleanup(niz, pn);								//Izvrsavanjem ciscenja ce i nas stari n biti postavljen na velicinu novog niza, vidi liniju ispod - koristimo n.
	niz = (char*)realloc(niz, n * sizeof(char));
	
	printf("Procisceni znakovni niz je: ");
	puts(nniz);
	
	free(niz);
	free(nniz);

    spc(2);
    system("pause");
    return 0;
}
