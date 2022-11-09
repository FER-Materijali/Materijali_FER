#include<stdio.h>
#pragma warning(disable:4996)
#include<malloc.h>

typedef struct node				//stvaranje strukture za listu
{
	float element;
	struct node* next;
}cvor;

int upis(cvor** glava, cvor** rep, float* broj)  //dodavanje elemenata u listu
{
	cvor* novi;
	novi = (cvor*)malloc(sizeof(cvor));
	if (novi == NULL) return 0;
	novi->element = *broj;
	novi->next = NULL;
	if (*glava == NULL)
	{
		*glava = novi;
		*rep = novi;

	}
	else
	{
		(*rep)->next = novi;
		*rep = novi;
	}
	return 1;
}

void ispis(cvor* glava)		//ispis liste
{
	cvor* p;
	for (p = glava;p != NULL;p = p->next)
	{
		printf("%.2f\n",p->element);
	}
}

int brisi(cvor** glavap, int elem,int n)   //brisanje elemenata sa liste
{
	int i;
	cvor *p;
	for (i = 0;i < n;i++)
	{
		for (; *glavap && (*glavap)->element != elem; glavap = &((*glavap)->next));
		if (*glavap) {
			p = *glavap;
			*glavap = (*glavap)->next;
			free(p);
			return 1;
		}
		else return 0;
	}
	
}


int main(void)
{
	int n,i,rez;
	cvor* glava=NULL;
	cvor* rep = NULL;
	float element;

	printf("Unesite broj clanova:\n");
	scanf("%d", &n);

	printf("Unesite elemente\n");
	for (i = 0;i < n;i++)
	{
		scanf("%f", &element);
		rez=upis(&glava, &rep, &element);  // funkcija za upisivanje elemenata u listu za n clanove
		if (!rez)
		{
			break;
		}
		
		
	}

	printf("Ispis:\n");
	ispis(glava);
	
	if (brisi(&glava, element, n))			//provjera za uspjesnost brisanja
	{
		printf("Uspjesno obrisana lista!\n");

	}
	else
	{
		printf("Neuspjesno obrisana lista!\n");
	}
	getchar();
	getchar();
	return 0;
}