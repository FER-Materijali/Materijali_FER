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

void InsertionSort(char **A, int N, int smjer)
{
	if(N < 2)					//Nizovi velicine 1 su vec sortirani
	return;
	
	//Uzlazno je u 1, pretvaramo silazno (0) u (-1)
	if(!smjer)
	smjer--;
	
	for(int i = 1, j; i < N; i++)	//Prolazi svim elementima pocevsi od 1.
	{
		char *t = A[i];			//Trenutni niz charova upisemo u pomocno polje
		
		//strcmp vraca 0 za jednake stringove, 1 ako je prvi veci od drugog, i -1 ako je drugi veci od prvog
		//smjerom reguliramo smjer sortiranja
		for(j = i; j > 0 && (strcmp(A[j-1], t) * smjer) > 0; j--)
		A[j] =  A[j-1];				//Iako bi nekom moglo ponukati da trebamo koristiti strcpy, to je netoèno - mi vladamo pokazivacima, a ne nizovima. Strcpy ce srusiti program bez iznimke.
		
		A[j] = t;
	}
}

int main()
{
	char **A, smjer = 0;
	int i = 0, n = 0;
	
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
		smjer -= '0';
		i = (smjer != 0 && smjer != 1);	//Pridodajemo i-ju 1 ako unos nije dobar, a 0 ako je dobar.
		spc(2);
	}
	while(i);						//Ako je i = 1, unos nije dobar, ponovno unosimo.
	
	system("CLS");
	
	i = 0;
	
	printf("Polje:\n");
	for(i = 0; i < n; i++)
	printf("[%d] %s\n", i + 1, A[i]);
	
	InsertionSort(A, n, smjer);
	
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