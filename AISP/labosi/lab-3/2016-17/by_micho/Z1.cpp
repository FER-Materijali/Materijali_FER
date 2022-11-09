//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct cvor				//Definiramo strukturu cvor. Kako radim u C++, ne trebam typedefove i te gluposti.
{
	float val;			//val kao value.
	cvor *rt;			//rt kao right (jer zamišljamo listu zdesna nalijevo.
};

void spc(int x)
{
     while(x--)
     printf("\n");
}

int upis(cvor **glava, cvor **rep, float *broj)
{
	cvor *neo = (cvor*)malloc(sizeof(cvor));	//Definiramo neki novi cvor i nazovemo ga neo
	
	if(neo)										//Ako je neo dodijeljena memorija, razlicit je od 0, pa nastavljamo
	{
		neo->val = *broj;						//Kazemo da je vrijednost neo jednaka vrijednosti pointera broj,
		neo->rt = 0;							//a da je sljedeci nul pointer (jer uvijek dodajemo na kraj reda).
		
		if(!(*glava))							//E sad, ako glava pokazuje na nulu (negacija 0 daje 1),
		*glava = *rep = neo;					//onda je lista prazna, pa novi dodajemo i na glavu i na rep.
		
		else									//U suprotnom, lista ima nesto, pa se vise ne zabavljamo sa glavom,
		*rep = (*rep)->rt = neo;				//vec mijenjamo sljedeci element onog na sto pokazuje rep, te mijenjamo sami rep.
		
		return 1;								//Ako smo dosli do tud, onda sve stima, i vracamo 1.
	}
	else										//Ako nam na pocetku nije alocirana memorija,
	return 0;									//vracamo 0.
	
	//return -1;					//Ovaj dio je opcionalan, ali moguce je da dodje do nekog hazarda. Teoretski, onda bismo dojavili neki treci kod (npr. -1), ali to se ne trazi u zadatku pa je komentirano.
}

void ispis(cvor *glava)						//Kratka funkcijica za ispis liste.
{
	for(cvor *p; glava;)					//Krecemo se po glavi, a p smatramo pomocnim pokazivacem na cvor
	{
		printf("%d ", (int)glava->val);		//Element na koji glava pokazuje ispisujemo kao cijelobrojnu vrijednost.
		
		p = glava;						//Na kraju, kazemo da je p glava, tj. p pokazuje na prvi element.
		glava = glava->rt;				//Pomaknemo glavu na sljedeci clan,
		free(p);						//a p, koji je stara glava, obrisemo.
	}
}

void errormsg()						//Kratka void funkcija za nevaljane unose, nista posebno, mozete i ignorirati.
{
	system("CLS");
	printf("  Upis nije valjan!");
}

int main()
{
	printf("\n  Z1 - Ucitati cijeli broj [1, 10]. Potom ucitati kolicinu\n");
	printf("       cijelih brojeva koja je ucitana. Elementi se dodaju na kraj\n");
	printf("       liste. Na kraju, lista je ispisana i obrisana.\n\n");
	
	cvor *glava, *rep;				//Na pocetku definiramo pokazivace na glavu i rep
	glava = rep = 0;				//te ih inicijaliziramo postavljanjem u 0.
	
	int n = 0;						//n ce nam biti broj elemenata u listi,
	float toLoad = 0.f;				//toLoad je neka varijabla koju upisujemo u listu,
	char cond1 = 0, cond2 = 0;		//a cond1 i cond2 ce biti uvjeti za ispravan unos.
	
	do
	{
		if(cond1)					//cond1 je u 1 ako je uvjet da je n izmedju 1 i 10 neispunjen.
		errormsg();					//i onda se ispisuje greska, te se trazi novi unos.
		
		printf("\n  Ucitajte cijeli broj [1,10]: ");
		cin >> n;					//Koristim cin jer me scanf kostao 2 boda na labosu zbog bugganog zadatka, sve u svemu po meni je elegantniji i bolji usprkos nefleksibilnosti.
		
		cond1 = (n < 1) || (n > 10);	//Postavljamo cond1 u vrijednost uvjeta - ako je n [1, 10], cond1 je 0 i petlja staje, u suprotnom trazi se ispravan upis.
		
	}while(cond1);
	
	spc(1);
	
	for(int i = 0; i < n; i++)		//Klasicna for petlja za upis n elemenata u listu.
	{
		printf("  Upisite %d. cijeli broj: ", i + 1);
		cin >> toLoad;				//Opet, koristim cin, a mozda je bolje da i Vi pocnete.
		
		cond2 = (int)toLoad != toLoad;	//ako je upisani broj float (ironicno, ali u zadatku eksplicitno pise da treba ucitavati cijele brojeve),
										//uvjet je u 1, petlja se ponovo vrti i trazi ispravan upis.
		if(cond2)
		{
			errormsg();
			i--;						//i-- je zbog toga sto bi nakon continue-e petlja isla dalje, neki put i zavrsila, a to ne zelimo, zelimo da ostane na istom mjestu.
			continue;					//continue "dojavljuje" for-u da je dosao do kraja.
		}
		else							//Ako je uvjet upisa zadovoljen, onda se element upisuje u listu.
		upis(&glava, &rep, &toLoad);	//Realno, funkcija vraca neku vrijednost, pa bi mozda bilo dobro zapisati je u neku varijablu,
	}									//no u tekstu zadatka nista ne pise o tome, ni kako postupiti, tako da se time ne bavimo.
	
	spc(2);
	
	printf("  Lista: ");
	ispis(glava);

    spc(4);
    system("pause");
    return 0;
}
