//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

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

void errormsg()				//Kratka void funkcija za nevaljane unose, nista posebno, mozete i ignorirati.
{
	system("CLS");
	printf("  Upis nije valjan!");
}

int main()
{
	printf("\n  Z3 - Ucitati broj cijeli broj [1, 10] s tipkovnice.\n");
	printf("       Potom ucitati ucitani broj realnih brojeva, koji se\n");
	printf("       dodaju u red realiziran listom. Usput ispisivati\n");
	printf("       dodane clanove u listu nakon upisa pojedinog clana.\n\n");
	
	Red red;
	init_red(&red);
	
	int n = 0;						//n ce nam biti broj elemenata u redu,
	double toLoad = 0.0;			//toLoad je neka varijabla koju upisujemo u red,
	char cond1 = 0;					//a cond1 ce biti uvjet za upis n-a e iz [1, 10]
	
	do
	{
		if(cond1)					//cond1 je u 1 ako je uvjet da je n izmedju 1 i 10 neispunjen.
		errormsg();					//i onda se ispisuje greska, te se trazi novi unos.
		
		printf("\n  Ucitajte cijeli broj [1,10]: ");
		cin >> n;
		
		cond1 = (n < 1) || (n > 10);	//Postavljamo cond1 u vrijednost uvjeta - ako je n [1, 10], cond1 je 0 i petlja staje, u suprotnom trazi se ispravan upis.
		
	}while(cond1);
	
	for(int i = 0; i < n; i++)
	{
		printf("\n\n  Upisite %d. vrijednost: ", i + 1);
		cin >> toLoad;
		
		dodajURed(toLoad, &red);		//Nemojte zaboraviti da zbog toga sto smo red inicijalizirali kao Red, moramo koristiti & jer funkcija prima pointer.
		
		printf("  Vrijednost %.6lf dodana je u red.\n\n", (red.ulaz)->val);	//Mogli smo vracati i toLoad, ali ce asistenti vjerojatno vise voliti ovaj pristup jer garantira da vam red radi.
	}
	
    spc(4);
    system("pause");
    return 0;
}
