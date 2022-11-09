//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<math.h>
#define M 256							//Velicina hash tablice
#define C1 2.002						//1. konstanta
#define C2 2.012						//2. konstanta
										//Konstante su proizvoljne, ne postoji jednoznacan razlog za moje brojeve
using namespace std;

void spc(int x)
{
     while(x--)
     printf("\n");
}

void init_table(int *table)
{
	for(int i = 0; i < M; i++)			//Tablicu inicijaliziramo na nacin da sve elemente postavimo u -1;
    table[i] = -1;						//to je najmanji broj kojeg ne mozemo dobiti normalnom pseudoslucajnom generacijom.
}

unsigned long int adresa(int value)		//Funkcija adrese je unsigned long iz nekoliko razloga;
{										//adresa je uvijek pozitivna vrijednost, veca je od inta s predznakom, a da je u manja, ovako dobivamo preciznije rjesenje
	unsigned long int A = 2654435769;
	int shift = 4;						//Mozda se pitate zasto tu nije 5 kao u prezentacijama; nakon malo testiranja, 4 radi bolje od 5, tj. distribucija hasheva je uniformnija.
	
	return ((A * value) >> shift) % M;	//Metoda množenja, ali nasu vrijednost treba modat sa M jer zelimo a bude u rangu [0, 127]
}

int insert(int *table, int value)
{
	int addr_t = adresa(value);			//addr_t kao address_temporary
	
	for(int i = 0; i < 10*M; i++)		//Stavljam 10*M da smanjim sansu nenalazenja mjesta za broj u tablici. Ovisno o C1 i C2, ovom broju se moze odrediti efektivni maksimum.
	{
		int addr = (int)(addr_t + C1*i + C2*i*i) % M;	//Prilicno jednoznacna formula za kvadratno ispitivanje, castamo u int jer nam onda konstante mogu biti realni brojevi ;)
		
		if(table[addr] >= 0)			//Ako smo nasli nesto sto je >= 0, tj > -1, onda je tu vec upisana vrijednost, idemo dalje.
		continue;
		else							//No, ako je trenutna vrijednost -1 ili manje, tu je prazno mjesto,
		{
			table[addr] = value;		//pa na to mjesto upisujemo nas broj
			return 1;					//i vracamo 1 da signaliziramo da je sve dobro proslo
		}
	}
	
	return 0;							//Ako dodjemo do ovdje, insercija u tablicu zbog nekog razloga nije uspjela, pa vracamo 0.
}

int main()
{
	printf("\n  Z10 - Ucitati 257 brojeva u hash tablicu velicine 256 koristeci\n");
	printf("        metodu mnozenja, izbjegavajuci kolizije metodom kvadratnog\n");
	printf("        ispitivanja. Konstanta A = 2654435769, a C1 i C2 su proizvoljni.\n\n");
	
    srand((unsigned int)time(NULL));
    
    int table[M];						//Sada inijaliziramo samo tablicu, jer koliziju rjesavamo na drugi nacin.
    init_table(table);
    
    int toLoad = 0;						//toLoad je vrijednost koju cemo ucitati.
    
    for(int i = 0; i <= M; i++)			//Ucitavamo 257 (M+1) vrijednosti u hash tablicu.
    {
    	toLoad = rand();
    	insert(table, toLoad);
    }
    
    //Ispod je kod za ispis koji nije u zadatku, sluzi cisto za provjeru.
    
    /*
    for (int i = 0; i < M; i++)
	{
		printf("  [%3d] ", i);
		
		if(table[i] == -1)
		printf("\n");
		else
		printf("  %5d\n", table[i]);

	}
	*/

    spc(4);
    system("pause");
    return 0;
}

