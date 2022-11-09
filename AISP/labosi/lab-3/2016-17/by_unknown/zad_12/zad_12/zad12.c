#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#define N 10
#pragma warning (disable:4996)

struct cvor {
	int broj;
	struct cvor *lijevo_dijete;				//stvaranje cvora
	struct cvor *desno_dijete;

};

struct cvor* NoviCvor(int elem)
{
	struct cvor* novi = (struct cvor *)malloc(sizeof(struct cvor));  //stvaranje novog cvora u slucaju ako ga nema
	novi->broj = elem;
	novi->lijevo_dijete = NULL;
	novi->desno_dijete = NULL;
	return(novi);
}


struct cvor* dodaj(struct cvor* korijen, int elem)
{

	if (korijen == NULL)
	{ // prazno stablo

		return(NoviCvor(elem));				//u slucaju da nema korijena pozovi stvaranje novog cvora

	}
	if (elem <= korijen->broj)
	{
		korijen->lijevo_dijete = dodaj(korijen->lijevo_dijete, elem);
	}
	else                                                                //dodavanje elemenata u stablo
	{
		korijen->desno_dijete = dodaj(korijen->desno_dijete, elem);
	}
	return(korijen);
}




void ispisinld(struct cvor *korijen)
{
	if (korijen != NULL)
	{
		ispisinld(korijen->desno_dijete);
		printf(" %d ", korijen->broj);					// stablo ispisuje u inorder (desno-lijevo) poretku.
		ispisinld(korijen->lijevo_dijete);
	}
}

int main(void)
{
	struct cvor* korijen;
	int broj, i;
	srand((unsigned)time(NULL));
	korijen = NULL;
	for (i = 0;i < N;i++)
	{
		broj = rand();						//upis elemanta u stablo
		korijen = dodaj(korijen, broj);

	}

	ispisinld(korijen);			//ispis stabla

	getchar();
	getchar();
	return 0;
}
