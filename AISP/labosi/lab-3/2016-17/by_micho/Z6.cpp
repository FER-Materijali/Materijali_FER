//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

//Zadatak je isti kao i Z1, pa sam maknuo komentare. Jedina promjena je int
//umjesto floata u tip podatka u koji ucitavamo vrijednost.

using namespace std;

struct cvor
{
	int val;
	cvor *rt;
};

void spc(int x)
{
     while(x--)
     printf("\n");
}

int upis(cvor **glava, cvor **rep, int *broj)
{
	cvor *neo = (cvor*)malloc(sizeof(cvor));
	
	if(neo)
	{
		neo->val = *broj;
		neo->rt = 0;
		
		if(!(*glava))
		*glava = *rep = neo;
		
		else
		*rep = (*rep)->rt = neo;
		
		return 1;
	}
	else
	return 0;
	
	//return -1;					//Ovaj dio je opcionalan, ali moguce je da dodje do nekog hazarda. Teoretski, onda bismo dojavili neki treci kod (npr. -1), ali to se ne trazi u zadatku pa je komentirano.
}

void ispis(cvor *glava)
{
	for(cvor *p; glava;)
	{
		printf("%d ", (glava)->val);	//Element na koji glava pokazuje ispisujemo kao cijelobrojnu vrijednost.
		
		p = glava;
		glava = (glava)->rt;
		free(p);
	}
}

void errormsg()						//Kratka void funkcija za nevaljane unose, nista posebno, mozete i ignorirati.
{
	system("CLS");
	printf("Upis nije valjan!");
}

int main()
{
	printf("\n  Z6 - Ucitati cijeli broj [1, 10]. Potom ucitati kolicinu\n");
	printf("       cijelih brojeva koja je ucitana. Elementi se dodaju na kraj\n");
	printf("       liste. Na kraju, lista je ispisana i obrisana.\n\n");
	
	cvor *glava, *rep;
	glava = rep = 0;
	
	int n = 0, toLoad = 0;
	char cond1 = 0, cond2 = 0;
	
	do
	{
		if(cond1)
		errormsg();
		
		printf("\n  Ucitajte cijeli broj [1,10]: ");
		cin >> n;
		
		cond1 = (n < 1) || (n > 10);
		
	}while(cond1);
	
	spc(1);
	
	for(int i = 0; i < n; i++)
	{
		printf("\n  Upisite %d. cijeli broj: ", i + 1);
		cin >> toLoad;
		
		cond2 = (int)toLoad != toLoad;
		
		if(cond2)
		{
			errormsg();
			i--;
			continue;
		}
		else
		upis(&glava, &rep, &toLoad);
	}
	
	spc(2);
	
	printf("  Lista: ");
	ispis(glava);

    spc(4);
    system("pause");
    return 0;
}
