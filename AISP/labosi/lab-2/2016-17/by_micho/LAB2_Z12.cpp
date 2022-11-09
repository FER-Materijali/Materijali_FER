//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>				//Za funkciju log
#include<string.h>
#define charSize 10

using namespace std;

void spc(int x)
{
     while(x--)
     printf("\n");
}

//Veoma slican proslom zadatku uz 2 izmjene - razmak vise necemo rjesavati u for-u
//Ideja je napraviti dinamicko polje koje cemo onda preoblikovati u niz intova koji
//sadrzavaju nas pomak. U for-u cemo se zapravo pomicati za elemente u trenutnom elementu niza
void ShellSort_Hibbard(char **A, int N, int smjer)
{
	if(N < 2)					//Nizovi velicine 1 su vec sortirani
	return;
	
	//Uzlazno je u 1, pretvaramo silazno (0) u (-1)
	if(!smjer)
	smjer--;
	
	//Prvo cemo definirati koliko mjesta u memoriji za niz trebamo zauzeti
	double x = N + 1.0;
	int velicina = (int)(log(x) / log(2));			//Treba se sjetiti da log2(x) = log10(x)/log10(2)
	
	int *razmaci = (int*)malloc(velicina * sizeof(int));	//Zauzimamo polje te velicine
	
	for(int i = 0; i < velicina; i++)				//Te ga punimo vrijednostima razmaka
		razmaci[i] = pow(2.0, i+1) - 1;
		
	//Ovaj ogromni for je zapravo cijeli trik - umjesto razmak /= 2, imamo pomicanje po polju, od kraja do pocetka. Samo polako procitajte, i ako nesto nije jasno, PM.
	for(int indeksRazmaka = velicina - 1, razmak = razmaci[indeksRazmaka], j; indeksRazmaka >= 0; razmak = razmaci[--indeksRazmaka])
	{
		for(int i = razmak; i < N; i++)				//Vjerovali ili ne, ovo je potpuno identicno od proslog zadatka.
		{											//Kod ima funkcionalne izmjene na liniji 6, linijama [31, 40] i 53, sve ostalo je isto!
			char *t = A[i];
			
			for(j = i; (j >= razmak) && (strcmp(A[j - razmak], t) * smjer > 0); j -= razmak)
			A[j] = A[j - razmak];
			
			A[j] = t;
		}
	}
	
	free(razmaci);
}

int main()											//Potpuno isti kao i prethodni zadatak, osim promjene naziva funkcije
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
	
	ShellSort_Hibbard(A, n, smjer);
	
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