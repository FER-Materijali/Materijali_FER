//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define sz 11			//Definiramo maks velicinu polja u redu, sz kao size.

using namespace std;

struct Red
{
	double loc[sz];		//loc od location. 11 jer za 10 clanova mora postojati jos 1 koji je uvijek prazan, pogledajte prezentacije za detaljnije objasnjenje.
	int	ulaz, izlaz;	//indeksi ulaza i izlaza.
};

void spc(int x)
{
     while(x--)
     printf("\n");
}

void init_red(Red *red)		//Inicijalizacija se svodi na doslovno postavljanja indekse ulaza i izlaza u 0.
{
	red->ulaz = red->izlaz = 0;
}

int dodajURed(double broj, Red *red)
{
	if(red->ulaz == (red->izlaz - 1) % sz)	//Ako je red pun,
	return 0;								//vracamo 0 sto ce nam biti kod za puni red kod ove funkcije.
	else
	{									//Ako red nije pun, onda u njega nesto upisujemo:
		++(red->ulaz) %= sz;			//Prvo cemo indeks ulaza povecati za 1, a ga modati sa sz kako bi sigurno bio u rasponu polja.
		red->loc[red->ulaz] = broj;		//Zatim upisujemo broj na trenutno vrijednost. Razlog modanja i povecavanja indeksa PRIJE dodavanja je predug za margine, ima u prezentacijama.
		return 1;						//Posto smo uspjeli upisati broj, vracamo 1, sto nam signalizira uspjeh.
	}
	
	//return -1;						//Isti razlog kao i u prethodnom zadatku, isti razlog zasto je komentirano.
}

int skiniIzReda(double *broj, Red *red)
{
	if(red->ulaz == red->izlaz)			//Ovo ce dati logicko 1 ako je red prazan; onda nemamo sto skinuti sa njega,
	return 0;							//pa ne radimo nikakve operacije, te izlazimo van sa kodom 0, koji signalizira neuspjeh zbog praznog reda.
	else
	{									//U suprotnom, ako u redu ima necega
		++(red->izlaz) %= sz;			//prvo povecevamo indeks izlaza, pa ga modamo. Razlog tome je sto na indeksu izlaz nikad nista ne upisujemo, on je uvijek prazan.
		*broj = red->loc[red->izlaz];	//Nakon toga u dereferencirani pointer broj (dakle, vrijednost pointera broj) upisujemo element koji je sad na izlazu.
		return 1;						//Razlog zašto moramo pomaknuti izlaz za 1 je ocit - kad je red prazan upisujemo na ulaz + 1, sto je i izlaz + 1, a kao zadnji element upisujemo na izlaz - 1. Dakle, izlaz se nikad ne dira do brisanja.
	}									//Vracamo 1 jer je skidanje iz reda uspjelo.
	
	return -1;							//Ovo je opcionalno, ali ako nam se nesto izuzev nedostatka memorije dogodilo, program ce vracati -1.
}

void errormsg()						//Kratka void funkcija za nevaljane unose, nista posebno, mozete i ignorirati.
{
	system("CLS");
	printf("  Upis nije valjan!");
}

int main()
{
	printf("\n  Z2 - Ucitati cijeli broj [1, 10]. Potom ucitati kolicinu\n");
	printf("       realnih brojeva koja je ucitana. Elementi se dodaju u red\n");
	printf("       Na kraju obrisati sve clanove te ih ispisati.\n\n");
	
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
		cin >> n;					//Opet, bolje je koristiti cin ako je tip podataka koji ucitavate isti kao i tip podatka u koji ucitavate.
		
		cond1 = (n < 1) || (n > 10);	//Postavljamo cond1 u vrijednost uvjeta - ako je n [1, 10], cond1 je 0 i petlja staje, u suprotnom trazi se ispravan upis.
		
	}while(cond1);
	
	spc(1);
	
	for(int i = 0; i < n; i++)		//Klasicna for petlja za upis n elemenata u red.
	{
		printf("\n  Upisite %d. realni broj: ", i + 1);
		cin >> toLoad;
		
		dodajURed(toLoad, &red);		//Dodajemo u red. Uocite da ni ne koristimo povratne vrijednosti, ali to niti u zadatku pise, niti bi normalnom
	}									//uporabom korisnik ikada mogao obrisati sa praznog stoga, niti upisati u puni stog. Funkcije su, medjutim, kompatibilne i sa drugim zadacima.
	
	spc(2);
	
	printf("  Red: ");
	for(int i = 0; i < n; i++)			//Sada sve vrijednosti moramo skinuti iz reda.
	{
		skiniIzReda(&toLoad, &red);		//Recikliramo varijablu toLoad; ona nam vise ne treba, pa mozemo u nju ucitavati skinute vrijednosti iz reda.
		printf("%.6lf ", toLoad);		//Ispisujemo vrijednosti skinutih brojeva. Ovih .6 je radi estetike, da ne zauzima previse prostora.
	}

    spc(4);
    system("pause");
    return 0;
}
