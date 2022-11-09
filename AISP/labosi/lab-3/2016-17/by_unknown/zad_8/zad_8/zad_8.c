#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable:4996)
#define MAX 10

typedef struct atom
{
	double element;			//struktura za listu
	struct atom* next;
}atom;

typedef struct
{
	atom* ulaz;				//struktura za red
	atom* izlaz;
}Red;

void init_red(Red* red)
{							//inicializacija reda
	red->ulaz = NULL;
	red->izlaz = NULL;
}

int dodajURed(double broj, Red *red)
{										//dodavanje elemenata u red
	atom* novi;
	if (novi = malloc(sizeof(atom)))
	{
		novi->element = broj;
		novi->next = NULL;
		if (red->izlaz == NULL)
		{
			red->izlaz = novi;
		}
		else
		{
			(red->ulaz)->next = novi;
		}
		red->ulaz = novi;
		return 1;
	}
	return 0;
}

int poljeURed(int polje[], int n, Red *red)			//rekruzivna funkcija koja preko polja se upisuju elementi u red
{
	if (n < 0)
	{
		return 0;
	}
	
	dodajURed(polje[n+1], red);
	printf("Upravo je dodan broj: %d\n", polje[n]);			//ispis elemenata u red
	return (poljeURed(polje, n - 1, red));
	
}

int main(void)
{
	int i, n;
	Red red;
	int polje[MAX];

	srand((unsigned)time(NULL));
	init_red(&red);
	printf("Unesite koliko clanova zelite:\n");
	scanf("%d", &n);
	printf("\n");
	for (i = 0; i<n; i++)		//upisivanje elemenata u red
	{
		polje[i] = (int)((float)rand() / (RAND_MAX + 1) * 10 + 1);
		printf("%d\n", polje[i]);
	}
	printf("\n");
	poljeURed(polje,n-1,&red);     //pozivanje funkcije za polje 
	getchar();
	getchar();
	return 0;
}