//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#define sz 10			//sz kao size stoga.
#define am 10			//am kao amount.

//Kako ovaj zadatak ukljucuje ispisivanje stoga, vjerojatno zele od nas da iskljucivo
//pushamo i popamo vrijednosti. Moj protekli pristup prcka po stogu, ali nije dio zadatka,
//no sada smijemo koristiti samo funkcije koje pisu i brisu iz stoga, pa se tog treba pridrzavati.
//Kada bi se zadatak mogao rijesiti prckanjem, rjesenje bi doslovno bila for petlja od 0 do 10.

//Mali note, iako pise da se smije koristiti pomocni stog, mi to necemo tako raditi - prvo
//to je neefikasno, a i veoma esteticki degenerativno. Srecom, ucili smo rekurzije pa se mozemo
//malo pozabaviti njima, a zauzvrat kod ce nam biti kraci, brzi i elegantniji. Sve cu ionako objasniti, nema trikova.

using namespace std;

struct stack
{
	int loc[sz];		//loc kao location.
	char SP;			//SP kao Stack Pointer.
};

void spc(int x)
{
     while(x--)
     printf("\n");
}

void init_stack(stack *stog)	//Inicijaliziramo stog tako da mu SP stavimo na -1.
{
	stog->SP = -1;
}

int push(int value, stack *stog)	//Funkcija za stavljanje vrijednosti na stog
{
	if(stog->SP >= sz - 1)			//Ako nam je SP veci ili jednak 9, to znaci da je pun, pa onda vracamo 0.
	return 0;
	else							//U suprotnom, pisemo na stog:
	{
		stog->loc[++(stog->SP)] = value;	//Prvo povecavamo vrijednost SP za 1, a onda upisujeme na loc tog indeksa vrijednost value (tj. broj koji zelimo upisati).
		return 1;							//Na kraju vracamo 1 ako je sve dobro proslo.
	}
	
	return -1;						//Ovo je objasnjeno u prethodnim primjerima, nije previse bitno.
}

int pop(int *value, stack *stog)	//Funkcija za skidanje vrijednosti sa stoga.
{
	if(stog->SP < 0)				//Ako je SP < 0, to znaci da je u rangu [-2^(31), -1],
	return 0;						//tj. stog je prazan ili tesko koruptiran, pa ne skidamo nista s njega
	else							//Ako ipak ima nesto na stogu, onda cemo skinuti vrijednost na vrhu.
	{
		*value = stog->loc[(stog->SP)--];	//Prvo cemo u vrijednost pointera value upisati ono sto je na loc indeksu vrha stoga,
		return 1;							//a onda cemo vrh stoga smanjiti za 1, te vratiti 1 da signaliziramo da je sve u redu.
	}
	
	return -1;						//Isti slucaj kao iznad.
}

void pstack(stack stog)				//Custom rekurzija za ispisivanje sadrzaja stoga od dna do vrha.
{
	int toPrint = 0;				//toPrint je neka vrijednost koju cemo printf-ati.
	
	if(stog.SP >= 0)				//Ako na stogu necega ima,
	{
		pop(&toPrint, &stog);		//popamo vrijednost i pohranjujemo je u toPrint,
		pstack(stog);				//te rekurzivno pozivamo funkciju sa izmijenjenim stogom.
	}
	else
	return;							//Ako je stog prazan, to je osnovni slucaj, pa se tu vracamo natrag.
	
	printf("  [%2d]   %2d\n", sz - (stog.SP + 1), toPrint);	//Prilikom povratka, ispisujemo vrijednost u toPrint. razlog za stog.SP + 1 je jednostavan;
}															//vec smo pop-ali vrijednost, pa je onda indeks - 1. Zato + 1, a oduzimamo od sz jer je prvi ispis dno, a 1 ce biti vrh.
													
int main()
{
	printf("\n  Z7 - Napisati fju za dodavanje i skidanje sa stoga za stog realiziran\n");
	printf("       poljem od 10 elemenata. U stog upisati 10 pseudoslucajnih cijelih\n");
	printf("       brojeva iz [1, 10], te ih ispisati od dna do vrha.\n\n");
	
    srand((unsigned int)time(NULL));
    
    stack stog;
    init_stack(&stog);
    
    int toLoad = 0;
    char exception = 0;
    
    for(int i = 0; i < am; i++)						//am je definan pretprocesorski
    {
    	toLoad = rand()%10 + 1;						//%10 jer je rang 10 brojeva, +1 jer pocetni mora biti 1.
    	exception = push(toLoad, &stog);
    	
    	if(!exception)
    	printf("  Dodavanje %2d u stog nije uspjelo jer je stog pun!\n", toLoad);	//Ovo se nikad bez modifikacije ne bi trebalo dogoditi, ali je lijepo vidjeti.
    }
    
    printf("\n\n  Stog:\n");
    pstack(stog);									//Kad ucitamo samo stog (ne &stog), mi ga zapravo ne mijenjamo globalno.
													//Zbog toga je rekurzija zgodna :^)	

    spc(4);
    system("pause");
    return 0;
}
