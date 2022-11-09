//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

#define M 128

using namespace std;

struct atom				//Stvaramo klasicnu strukturu atoma.
{
	int val;
	atom *rt;
};

void spc(int x)
{
     while(x--)
     printf("\n");
}

void init_table(atom **table)
{
	for(int i = 0; i < M; i++)			//Inicijaliziramo tablicu na nacin da na sve pokazivace
	table[i] = 0;						//na indeks stavimo 0 (inace su nasumicni pointeri).
}

unsigned long int adresa(int value)		//funkcije adrese je unsigned long iz nekoliko razloga;
{										//adresa je uvijek pozitivna vrijednost
	unsigned long int A = 2654435769;
	int shift = 4;						//Mozda se pitate zasto tu nije 5 kao u prezentacijama; nakon malo testiranja, 4 radi bolje od 5, tj. distribucija hasheva je uniformnija.
	
	return ((A * value) >> shift) % M;	//Metoda množenja, ali nasu vrijednost treba modat sa M jer zelimo a bude u rangu [0, 127]
}

int insert(atom **table, int value)				//Ucitavamo dupli pokazivac tablice jer cemo je mijenjati po indeksima
{
	int addr;									//addr od address.
	atom *neo = (atom*)malloc(sizeof(atom));	//Stvaramo novi podatak kao atom.
	
	if(neo)										//Ako je neo != 0, onda je stvoren, pa ga dodajemo u tablicu:
	{
		addr = adresa(value);					//Prvo cemo mu naci adresu hash funkcijom,
		
		neo->val = value;				//onda na vrijednost zapisujemo vrijednost koju dodajemo u hash tablicu,
		neo->rt = table[addr];			//pa mu na pokazivac na sljedeceg clana stavimo trenutni clan na koji pokazuje indeks addr.
		
		table[addr] = neo;				//Zavrsno, sada kazemo da nas novododani clan jest prvi na kojeg pokazuje indeks, i vracamo 1.
		return 1;						//Mozda ste uocili da smo ga dodali naopacke, tj. zadnji dodani broj biti ce prvi na kojeg indeks pokazuje.
	}									//To je zbog slozenosti: kad bi ih dodavali na kraj bez repa, onda bi slozenost dodavanja bila O(n), a ne O(1), a poredak nam ionako nije vazan.
	else
	return 0;							//Ako je neo == 0, nema mjesta u memoriji, pa nemamo sto dodati u tablicu.
}

int main()
{
	printf("\n  Z9 - Napuniti hash tablicu velicine 128 s 129 cijelobrojnih vrijednosti.\n");
	printf("       Funckija hashiranja je metoda mnozenja s konstantom 2654435769, a kolizije\n");
	printf("       se rjesavaju metodom ulancavanja.\n\n");
	
    srand((unsigned int)time(NULL));
    
    atom *table[M];						//Nasa tablica je zapravo polje pokazivaca velicine M.
    init_table(table);					//Mozda pomalo far-fetched reprezentacija bi bila parangal s promjenjivim brojem udica na 1 stupcu, gdje imamo 128 stupaca.
    
    int toLoad = 0;						//toLoad je privremena vrijednost koju cemo upisati u hash tablicu
    
    for(int i = 0; i <= M; i++)			//Kako upisujemo 129 vrijednosti, i nam je u rasponu [0, 128], sto je isti raspon kao i [1, 129].
    {
    	toLoad = rand();				//Ucitavamo pseudonasumicni cijeli broj u toLoad,
    	insert(table, toLoad);			//a potom ga umecemo u tablicu
    }
    
    //Ispod je kod koji ispisuje tablicu, iako nije potreban u zadatku, tu je za provjeru.
    
    /*
    for (int i = 0; i < M; i++)
	{
		atom *curr = table[i];			//curr kao current.
		printf("  [%3d] ", i);
		
		while(curr) 
		{
			printf("%5d", curr->val);
			
			if(curr->rt)
			printf(", ");
			
			curr = curr->rt;
		}
		spc(1);
	}
	*/
	
    spc(4);
    system("pause");
    return 0;
}
