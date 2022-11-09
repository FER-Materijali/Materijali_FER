//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define charSize 10

using namespace std;

void spc(int x)
{
     while(x--)
     printf("\n");
}

void Zamijeni(char *prvi, char *drugi)
{
	char *t = (char*)malloc(charSize * sizeof(char));	//Definiramo t kao pokazivac koji je iste velicine kao i charovi koje kopiramo
	
	strcpy(t, prvi);									//Imamo pokazivace, a mozemo im samo mijenjati vrijednosti. Dakle, moramo
	strcpy(prvi, drugi);								//Koristiti strcpy. Kad bi pokusali kopirati vrijednosti, zamijenili bi samo znakove
	strcpy(drugi, t);									//na indeksu 0, sto nije zeljeno ponasanje.
	
	free(t);											//Kako nismo divljaci, oslobadjamo i t.
}

void BubbleSortPoboljsani(char **A, int N, int smjer)
{
	if(N < 2)					//Nizovi velicine 1 su vec sortirani
	return;
	
	//Uzlazno je u 1, pretvaramo silazno (0) u (-1)
	if(!smjer)
	smjer--;
	
	int novirgin;										//Varijabla djevicanstva - s njom ispitujemo je li niz dirnut
	
	do
	{
		novirgin = 0;									//Na pocetku je niz nedirnut, pa "isn't not virgin", tj. dupla negacija je tautologija.
		
		for(int i = 0; i < (N - 1); i++)				//Idemo samo do predzadnjeg clana jer uvijek provjeravamo trenutni i jedan ispred.
		{
			if(strcmp(A[i], A[i+1]) * smjer > 0)		//Ako je lijevi veci od desnog za smejr 1 (uzlazno), vraca 1, itd. Fora sa smjer manipulacijom, izbjegavamo dupli if.
			{
				novirgin++;								//Mice novirgin iz nule. Moglo je i novirgin--, važno je samo da apsolutna vrijednost bude drukcija od 0.
				Zamijeni(A[i], A[i + 1]);				//Zamijenjujemo trenutni i niz udesno.
			}
		}
	}while(novirgin);									//Dok god je ovo 1, niz je dirnut. Dakle, prvi put kad niz ne bude dirnut, niz je sortiran.
}

int main()												//Ako jos niste shvatili, sve do ~100tih linija je isto u dosta kodova.
{
	char **A;
	int n = 0, i = 0, smjer = 0;
	
	do
	{
		system("CLS");				//Ovo samo brise ekran u cmd-u, radi preglednosti.
		
		if(i)
		printf("Velicina ne odgovara uvjetima, ponovite upis.\n");
		
		printf("Unesite broj znakovnih nizova [1, 10]: ");
		scanf("%d", &n);
		i = n < 1 || n > 10;		//i poprima 1 ako je unos nevaljan, a 0 ako je dobar.
		spc(2);
	}
	while(i);
	
	A = (char**)malloc(n * sizeof(char*));	//Ovdje deklariramo polje pokazivaca, pa mu velicina treba biti reda char* (velicina pokazivaca na char), a ne samo char
	
	if(!A)
	{
		printf("Neuspjesna alokacija memorije.\nIzlazim...");
		exit(-1);
	}
	
	getchar();								//Problemi sa scanfom, KILL ME
	
	for(int i = 0; i < n; i++)
	{
		A[i] = (char*)malloc(charSize * sizeof(char));	//Prije pisanja polja charova prvo moramo zauzeti dovoljno veliko polje. Po defaultu je to za 9 znakova (9 + 1)
		printf("Upisite %d. rijec (do 9 znakova): ", i + 1);
		gets(A[i]);
	}
	
	i = 0;
	
	do
	{
		system("CLS");
		
		if(i)						//Ne pokrece se isprva jer smo i stavili na 0
		printf("Pogresan unos, pokusajte ponovo.\n");
		
		printf("Sortirati silazno (0) ili uzlazno (1)?\n");
			
		cin >> smjer;				//Izvodimo ovu vratolomiju jer scanf zna koruptirati stog i uništiti neku vrijednost.
		i = (smjer != 0 && smjer != 1);	//Pridodajemo i-ju 1 ako unos nije dobar, a 0 ako je dobar.
		spc(2);
	}
	while(i);						//Ako je i = 1, unos nije dobar, ponovno unosimo.
	
	system("CLS");
	
	i = 0;
	
	printf("Polje:\n");
	for(i = 0; i < n; i++)
	printf("[%d] %s\n", i + 1, A[i]);
	
	BubbleSortPoboljsani(A, n, smjer);
	
	if(!smjer)
	printf("\nSortiramo silazno:\n");
	else
	printf("\nSortiramo uzlazno:\n");
	
	for(i = 0; i < n; i++)
	printf("[%02d] %s\n", i + 1, A[i]);
	
	free(A);

    spc(2);
    system("pause");
    return 0;
}