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

//Shellsort vam je zapravo ista stvar kao i insertionSort. Ako znate insertion, u principu znate
//i ShellSort. Jedina razlika je u pomaku - klasican ShellSort je InsertionSort sa pomacima N/2,
//N/4, N/8 itd., gdje je N broj clanova niza koji se sortira. ShellSort u principu UVIJEK sadrzava
//InsertionSort (jos nisam vidio ShellSort varijantu koja nije imala pomak = 1). U kodu cu naglasiti
//koje stvari se mijenjaju sa Shellom. Za sljedeci zadatak cemo kompleksnije odrediti razmake.
void ShellSort(char **A, int N, int smjer)			//Pazite, ovdje je smjer int, a ne char.
{
	if(N < 2)					//Nizovi velicine 1 su vec sortirani
	return;
	
	//Uzlazno je u 1, pretvaramo silazno (0) u (-1)
	if(!smjer)
	smjer--;
	
	for(int razmak = N/2, j; razmak > 0; razmak/=2)		//Definiramo razmak kao polovica trenutne velicine i neki j (kasnije ce biti indeks)
	{															//Petlja se vrti dok je razmak 1 ili veci (razmak od 0 je isti clan, ne mozemo ga sortirati hahaha)
		for(int i = razmak; i < N; i++)				//Prvi kojeg usporeðujemo je na indeksu razmak, te idemo do kraja. U 1. pokretanju
		{											//To je velicina/2, u 2. velicina/4, a u zadnjem 1.
			char *t = A[i];							//U t pohranjujemo trenutni niz za koji provjeravamo je li manji ili veci od niza koji mu je za razmak mjesta ulijevo.
			
			for(j = i; (j >= razmak) && (strcmp(A[j - razmak], t) * smjer > 0); j -= razmak)	//Uocite sto se promijenilo - j sada mora biti >= razmak (kad je pomak bio 1, morao je biti >0 u insertionu
			A[j] = A[j - razmak];														//usporedjujemo j - razmak umjesto j - 1, i smanjujemo j za razmak, umjesto za 1. Dakle, sve konstante smo zamijenili sa razmakom
			
			A[j] = t;							//Na kraju, na j-ti niz stavljamo t, jer smo izvrtili petlju.
		}
	}
}

int main()											//Potpuno isti kao i prethodni zadatak, osim promjene naziva funkcije na liniji 106.
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
	
	ShellSort(A, n, smjer);
	
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