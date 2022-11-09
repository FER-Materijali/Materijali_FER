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

void SelectionSort(char **A, int N, int smjer)
{
	if(N < 2)					//Nizovi velicine 1 su vec sortirani
	return;
	
	//Uzlazno je u 1, pretvaramo silazno (0) u (-1)
	if(!smjer)
	smjer--;
	
	for(int i = 0; i < N; i++)
	{
		char *ekstrem = A[i];	//Pomocni pokazivac ekstrem pokazuje na A[i]
		
		for(int j = i; j < N; j++)
		{
			if(strcmp(ekstrem, A[j]) * smjer > 0)
			Zamijeni(ekstrem, A[j]);
		}
	}
}

int main()
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
	
	SelectionSort(A, n, smjer);
	
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