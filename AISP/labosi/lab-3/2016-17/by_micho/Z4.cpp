//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#define sz 100			//sz kao size, ovo ce biti velicina stoga.

using namespace std;

struct stack
{
	int loc[sz];		//loc kao location.
	char SP;			//SP kao Stack Pointer. Char radi uštede memorije (vrijednost je manja od 256).
};

void init_stack(stack *stog)
{
	stog->SP = -1;		//Stog inicijaliziramo na nacin da na SP stavimo -1, jer "trenutna" vrijednost
}						//na kojoj je vrh stoga je na indeksu -1, tj. u C-ovskim jezicima - ta vrijednost ne postoji.

int push(int value, stack *stog)
{
	if(stog-> SP >= sz - 1)		//Ako je stog pun, SP ce biti na 99, tj. postoji loc[99] (sto je kraj),
	return 0;					//pa onda vracamo 0.
	else						//U suprotnom, dodajemo vrijednost na stog tako da
	{
		stog->loc[++(stog->SP)] = value;	//prvo povecamo SP za 1, a onda na taj indeks u loc spremamo vrijednost
		return 1;							//te vracamo 1 kao signal da je sve dobro proslo.
	}
	
	return -1;					//Nije bitno ni obavezno, objasnjenje u prrethodnim zadacima.
}

void spc(int x)
{
     while(x--)
     printf("\n");
}

int main()
{
	printf("\n  Z4 - Realizirati stog poljem od 100 clanova i staviti\n");
	printf("       101 cjelobrojnih pseudoslucajnih vrijednosti na stog.\n\n");
	
    srand((unsigned int)time(NULL));		//Bolje je castati unsigned int da se ne gubi preciznost.
    
    stack stog;
    init_stack(&stog);
    
    char exception = 0;						//exception ce biti povratna vrijednost push-a,
    int toLoad = 0;							//a toLoad privremena vrijednost koju ucitavamo u stog.
    
    for(int i = 0; i <= sz; i++)			//Ucitavamo 101 vrijednost.
    {
    	toLoad = rand();					//toLoad je neki pseudoslucajni cijeli broj.
    	exception = push(toLoad, &stog);	//U exception se sprema -1, 0 ili 1, ovisno o ishodu.
    	
    	if(!exception)						//Ako je exception 0, stog je pun, pa javljamo gresku.
    	printf("\n  Vrijednost %5d nije mogla biti upisana jer je stog pun!", toLoad);
    }
    
    //Sljedeci komentirani dio sluzi samo za provjeru stoga, i nije dio zadatka.
    //Mozete ga odkomentirati da vidite vrijednosti spremljene na stog.
    
    /*
    cout << "\n\n  Stog:\n";
    
    for(int i = sz; i > 0; i--)
    printf("\n  [%03d]   %5d", i, stog.loc[i-1]);
    */

    spc(4);
    system("pause");
    return 0;
}
