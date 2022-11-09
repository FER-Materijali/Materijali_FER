//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

void spc(int x)
{
     while(x--)
     printf("\n");
}

typedef struct at						//Struktura sada ima znakove kao vrijednost, te pokazivac na sljedeci atom.
{
	char znakovi[41];
	struct at* next;
}cvor;

int upis(cvor **glava, char *niz)
{
	cvor *novi;							//Definiramo pokazivac na neki novi cvor
	novi = (cvor*)malloc(sizeof(cvor));	//Alocirati cemo memoriju na heapu za 1 cvor.
	
	if(!novi)
	return 0;							//Izlazimo iz funkcije, javit cemo neku gresku.
	
	else
	{
		strncpy(novi->znakovi, niz, 41);	//Primjedba - kopiramo prvih 41 clanova jer smo toliko memorije osigurali. strcpy nije uvijek tocan, barem ne za nizove staticke velicine.
		
		novi->next = *glava;			//Kako uvijek charove stavljamo na pocetak, sljedeci element novog bit ce ono na sto
		*glava = novi;					//pokazuje glava, a glava ce pokazivati na novi element.
	}
	
	return 1;
}

int main()
{
	cvor *glava = NULL;								//glavap = &glava
	int n = 0, i = 0;
	char niz[41];
	
	do
	{
		system("CLS");								//Ovo samo brise ekran u cmd-u, radi preglednosti.
		
		if(i)
		printf("Velicina ne odgovara uvjetima, ponovite upis.\n");
		
		printf("Unesite broj znakovnih nizova [1, 10]: ");
		scanf("%d", &n);
		i = n < 1 || n > 10;						//i poprima 1 ako je unos nevaljan, a 0 ako je dobar.
		spc(2);
	}
	while(i);
	
	system("CLS");
	
	for(i = 0; i < n; i++)
	{
		printf("Unesite %d. niz znakova (od %d): ", i + 1, n);
		cin >> niz;
		int ret = upis(&glava, niz);				//U neki int ret upisujemo vrijednost koju vraca upis
		
		if(!ret)									//Ako je 0, onda nije uspjelo dodavanje, pa obavjestavamo koristika i izlazimo.
		{
			printf("Dodavanje %d. elementa nije uspjelo!", i + 1);
			exit(-1);
		}
		
		spc(1);
	}
	
	printf("Konacna lista:\n\n");
	for(cvor *p = glava; p; p = p -> next)			//Analogno kao i u Z6, samo sa puts.
    	puts(p->znakovi);
    	
    free(glava);

    spc(2);
    system("pause");
    return 0;
}