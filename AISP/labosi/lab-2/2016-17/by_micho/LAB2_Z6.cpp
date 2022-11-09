//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct at						//Klasicna struktura atoma liste
{
	int value;
	struct at* next;
}cvor;

void spc(int x)
{
     while(x--)
     printf("\n");
}

int upis(cvor **glava, int element)
{
	cvor *novi;							//Definiramo pokazivac na neki novi cvor
	novi = (cvor*)malloc(sizeof(cvor));	//Alocirati cemo memoriju na heapu za 1 cvor.
	
	if(!novi)							//Ako novi pokazuje na 0, alociranje memorije nije uspjelo
	return 0;							//Izlazimo iz funkcije, javit cemo neku gresku.
	
	else
	{
		novi->value = element;			//ako je rezervirano mjesto, vrijednost koju zelimo upisati stavljamo na novi atom.
		
		if((*glava == NULL) || (element <= (*glava)->value))	//Provjeravamo trebamo li element upisati na pocetak liste
		{
			novi->next = *glava;
			*glava = novi;
		}
		else
		{	//Detaljan opis sljedeceg mozete naci u Pripremi za MI u ASP repozitoriju.
			for(; (*glava)->next && ((*glava)->next)->value < element; glava = &((*glava)->next));
				
			novi->next = (*glava)->next;
			(*glava)->next = novi;
		}
	}
	
	return 1;
}

int main()
{
	cvor *glava = NULL;								//glavap postoji virtualno kao &glava
	int n = 0, i = 0, x = 0;						//x je neki broj koji cemo upisati
	
	do
	{
		system("CLS");								//Ovo samo brise ekran u cmd-u, radi preglednosti.
		
		if(i)
		printf("Premalo ili previse elemenata, ponovite upis.\n");
		
		printf("Unesite broj elemenata koje mislite upisati [1, 10]: ");
		scanf("%d", &n);
		i = n < 1 || n > 10;						//i poprima 1 ako je unos nevaljan, a 0 ako je dobar.
		spc(2);
	}
	while(i);
	
	system("CLS");
	
	for(i = 0; i < n; i++)
	{
		printf("Unesite %d. vrijednost (od %d): ", i + 1, n);
		cin >> x;
		int ret = upis(&glava, x);					//U neki int ret upisujemo vrijednost koju vraca upis
		
		if(!ret)									//Ako je 0, onda nije uspjelo dodavanje, pa obavjestavamo koristika i izlazimo.
		{
			printf("Dodavanje %d. elementa nije uspjelo!", i + 1);
			exit(-1);
		}
		
		spc(1);
	}
	
	printf("Konacna lista: ");
	for(cvor *p = glava; p; p = p -> next)			//Uzmemo neku pomocnu glavu p, i kazemo da je ona jednaka glavi liste. Dok god ne dodjemo
    	printf("%d ", p -> value);					//do kraja liste, ispisujemo vrijednost na trenutnom atomu, i pomicemo se na sljedeci.
    	
    free(glava);

    spc(2);
    system("pause");
    return 0;
}