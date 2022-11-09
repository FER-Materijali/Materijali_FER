//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

//U uputama kaze stog pokazivacima, sto je smijesno jer stog pokazivacima moze biti i stog poljem,
//s obzirom na to da je polje pokazivac, pa pretpostavljam da su se referirali na liste.

using namespace std;

struct atom
{
	int val;			//val kao value.
	atom *rt;			//rt kao right (jednosmjerna lista).
};

struct stack			//Nas stog se sastoji samo od pokazivaca na glavu liste
{
	atom *SP;
};

void init_stack(stack *stog)	//Stog inicijaliziramo na nacin da vrh usmjerimo na adresu 0.
{
	stog->SP = 0;
}

int push(int value, stack *stog)
{
	atom *neo = (atom*)malloc(sizeof(atom));	//Prvo stvaramo novi clan kao atom liste.
	
	if(neo)						//Ako ima memorije, neo je razlicit od 0 pa
	{
		neo->val = value;		//u neo pohranjujemo vrijednost value
		neo->rt = stog->SP;		//te ga povezujemo s vrhom stoga.
		stog->SP = neo;			//Zatim neo deklariramo kao novi vrh stoga
		return 1;				//te vracamo 1 jer je stavljanje na stog uspjelo.
	}
	else
	return 0;					//Ako nema memorije, neo nije napravljen, pa vracamo 0 sto signalizira da nema memorije
	
	return -1;					//Razlog isti kao i u prethodnim zadacima.
}

void spc(int x)
{
     while(x--)
     printf("\n");
}

void pstack(stack stog)			//Funkcija za ispis stoga izvedenog listom, nije dio zadatka, potpuno opcionalno
{								//Da bi slozenost ispisa ostala n, koristimo rekurziju i zrtvujemo dosta memorije.
	atom *tempSP;				//Definiramo neki pomocni SP, koji nam sluzi da bismo zapamtili staru vrijednost SP-a prije pomaka za jedan naprijed.
	
	if(stog.SP)					//Ako ovo prodje, nalazimo se na nekoj od vrijednosti na stogu
	{
		tempSP = stog.SP;			//Stavimo trenutni vrh stoga u tempSP,
		stog.SP = (stog.SP)->rt;	//pomaknemo vrh stoga na vrijednost ispod,
		pstack(stog);				//te pozovemo funkciju rekurzivno sa novim stogom.
	}
	else							//Ako stog.SP ne prodje, nalazimo se izvan stoga, tj. ovo je osnovni slucaj u rekurziji.
	return;
	
	printf("\n  %5d", tempSP->val);	//I sad, zapravo "unazad" printamo vrijednosti na stogu od vrha prema pocetku.
}

int main()
{
	printf("\n  Z5 - Realizirati stog listom i staviti 101 cjelobrojnih\n");
	printf("       pseudoslucajnih vrijednosti na stog.\n\n");
	
    srand((unsigned int)time(NULL));
    
    stack stog;
    init_stack(&stog);
    
    char exception = 0;						//exception ce biti povratna vrijednost push-a,
    int toLoad = 0, sz = 101;				//toLoad je vrijednost koju ucitavamo, a sz je broj vrijednosti koje upisujemo na stog-
    
    
    for(int i = 0; i < sz; i++)				//Ucitavamo 101 vrijednost.
    {
    	toLoad = rand();					//toLoad je neki pseudoslucajni cijeli broj.
    	exception = push(toLoad, &stog);	//U exception se sprema -1, 0 ili 1, ovisno o ishodu.
    	
    	if(!exception)						//Ako je exception 0, memorija je puna, pa javljamo gresku.
    	printf("\n  Vrijednost %5d nije mogla biti upisana jer je memorija puna!", toLoad);
    }
    
    //Ispod se nalazi ispis koji nije dio zadatka, ali je zgodan za provjeru stoga.
    
    /*
    printf("\n  Stog:\n");					//Printamo stog od vrha prema pocetku rekurzivnom funkcijom
    pstack(stog);							//Kako predajemo stog, a ne pointer na njega, ne diramo pravi SP.
    */
    
    spc(4);
    system("pause");
    return 0;
}
