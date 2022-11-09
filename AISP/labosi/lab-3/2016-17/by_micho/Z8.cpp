//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#define am 10			//am kao amount

//Ovaj zadatak je dug, ali je zapravo vrlo jednostavan. Vecina zadatka je zapravo Z3,
//a rekurzije su ionako intrigantne pa su zadovoljstvo za pisati i objasniti. Samo jako.

using namespace std;

struct cvor
{
	double val;			//val kao value.
	cvor *rt;			//rt kao right, lista je jednosmjerna.
};

struct Red
{
	cvor *ulaz, *izlaz;
};

void spc(int x)
{
     while(x--)
     printf("\n");
}

void init_red(Red *red)				//Inicijaliziramo red tako da ulaz i izlaz pokazuju na 0.
{
	red->ulaz = red->izlaz = 0;		//Moze i sa (*red).ulaz i (*red).izlaz, efekt je isti.
}

int dodajURed(double broj, Red *red)
{
	cvor *neo = (cvor*)malloc(sizeof(cvor));	//Stvorimo cvor u koju cemo pohraniti nove vrijednosti za red.
	
	if(neo)								//Ako je neo neki broj razlicit od 0, memeorija je uspjesno alocirana, pa
	{
		neo->val = broj;				//a vrijednost neo stavljamo broj,
		neo->rt = 0;					//te ga povezujemo s 0, jer ce on biti zadnji element u redu.
		
		if(!(red->ulaz))				//Ako je ulaz ili izlaz na 0, red je prazan.
		red->izlaz = neo;				//pa s izlazom povezujemo novi cvor, jer ce on biti prvi na izlazu.
		
		red->ulaz = neo;				//U svakom slucaju stavljamo cvor na ulaz, jer dodajemo clan.
		return 1;						//Ako smo dosli do tuda, sve je lijepo proslo, pa vracamo 1.
	}
	else								//Ako je neo == 0, onda memorija nije alocirana,
	return 0;							//pa vracamo 0.
	
	return -1;							//Opet, ako je doslo do neke pogreske nevezane uz memoriju, vracamo -1. Ovo nije nuzno, vec dobra praksa.
}

int poljeURed(int polje[], int n, Red *red)
{
	int isFine = 1;						//isFine je u 1 ako su svi clanovi polja do sad uspjesno upisani, 0 u suprotnom.
	
	if(n > 0)										//Dok god je n > 0, jos imamo elemenata za upisati, pa pozivamo rekurziju
	isFine = poljeURed(polje + 1, n - 1, red);		//na nacin da polje (pointer) uvecamo za 1, a n smanjimo za 1. Efektivno pomicemo pocetni indeks udesno, a smanjujemo broj preostalih clanova do kraja.
	else
	return 1;										//Ako je n <= 0, onda smo dosli do kraja, i vracamo 1 (sve je u redu s kopiranjem za sad, samo se vracamo natrag do pocetka rekurzije).
	
	if(isFine)							//Ako je isFine u 1, sve stima, pa dodajemo vrijednost iz polja u red.
	{
		printf("\n  Dodajem (%2d) u red", polje[0]);			//Ispisujeme element koji se dodaje. On je na polje[0] jer smo u ovu instancu funkcije poslali izmijenjeno polje.
		int exception = dodajURed((int)polje[0], red);
	
		if(!exception)										//Ako je exception == 0, onda nas upis u red nije uspio,
		{													//pa to javljamo korisniku, i returnamo 0 cime smo efektivno onemogucili daljnje pokusaje kopiranja.
			printf("  \nNeuspjelo dodavanje elementa!\nPrekidam...");
			return 0;
		}
		else
		return 1;
	}
	else								//Ako je isFine bio 0, onda to prenosimo dalje u rekurziju,
	return 0;							//tako da u svim prethodnim instancama rekurzije nema pokusaja upisa u red.
}

int main()
{
	printf("\n  Z8 - realizirati red listom, te incijalizirati polje velicine 10\n");
	printf("       u koje se upisuju pseudoslucajni cijeli brojevi iz [1, 10].\n");
	printf("       ispisati kreirano polje, te pomocu rekurzije upisati clanove\n");
	printf("       od kraja polja do pocetka u red. Prilikom upisa ispisivati\n");
	printf("       clanove koji se stavljuaju u red.\n\n");
    srand((unsigned int)time(NULL));
    
    Red red;
    init_red(&red);
    
    char exception = 0;
    int polje[am] = {0};				//am je definiran pretprocesorski
    
    printf("  Polje: [");					//Samo ispis polja, nista bitnog.
    for(int i = 0; i < am; i++)
    {
    	polje[i] = rand()%10 + 1;
    	
    	if(i)
    	printf(", ");
    	printf("%d", polje[i]);
    }
    printf("]\n\n");
    
    poljeURed(polje, am, &red);

    spc(4);
    system("pause");
    return 0;
}
