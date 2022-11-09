#include<stdio.h>
#include<malloc.h>
#pragma warning (disable:4996)

typedef struct atom				//struktura za red
{
	double element;
	struct atom* next;
}atom;

typedef struct       //struktura za listu
{
	atom* ulaz;
	atom* izlaz;
}Red;

void init_red(Red* red)    //inicalizacija reda
{
	red->ulaz = NULL;
	red->izlaz=NULL;
}

int dodajURed(double broj, Red *red)   //dodavanje elemenata u red
{
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

int main(void)
{
	int i, n;
	double broj;
	Red* red;

	init_red(&red);
	printf("Unesite oliko clanova zelite:\n");
	scanf("%d", &n);
	for (i = 0; i<n; i++) {				//pozivanje funkcije za dodavanje elemenata i upisivanje za n clanova
		printf("Unesite %d. clan: \n", i + 1);
		scanf("%lf", &broj);
		if (dodajURed(broj, &red)) printf("Clan uspjesno unesen.");    //provjera za uspjesnost dodavanja elemenata u red
		else {
			printf("Clan nije uspjesno unesen.");
			break;
		}
	}
	
	return 0;
}