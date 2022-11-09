#include<stdio.h>
#pragma warning (disable:4996)
#define MAX 10
typedef struct {			//struktura za red
	double polje[MAX];
	int ulaz, izlaz;
}Red;

void init_red(Red* red)		//inicaliyacija reda
{
	red->ulaz = NULL;
	red->izlaz = NULL;
}

int dodajURed(double broj, Red *red)  //dodavanje elementa u red
{
	if ((red->ulaz + 1) % MAX == red->izlaz) return 0;
	red->ulaz++;
	red->ulaz %= MAX;
	red->polje[red->ulaz] = broj;
	return 1;
		
}

int skiniIzReda(double *broj, Red *red)          //skidanje elementa sa reda
{
	if (red->ulaz == red->izlaz) return 0;
	red->izlaz++;
	red->izlaz %= MAX;
	*broj = red->polje[red->izlaz];
	return 1;

}

int main(void)
{
	int i,n,rez;
	double broj, skini;
	Red* red;
	init_red(&red);

	printf("Unesite broj clanova <=10 :\n");
	scanf("%d", &n);

	for (i = 0;i < n;i++)			// upisivanje vrijednosti elementa i pozivanje funkcije za n clanova
	{
		printf("Unesite %d. broj:\n", i + 1);
		scanf("%lf", &broj);
		if (dodajURed(broj, &red))
		{
			printf("Element je dodan!\n");
		}
		else
		{
			printf("Red je pun!\n");
		}
	}

	printf("Ispis: \n");			//ispis reda
	for (i = 0;i < n;i++)
	{
		if (skiniIzReda(&skini, &red))   //skidanje elemenata sa reda
		{
			printf("Broj: %.2lf je skinut s reda\n", skini);
		}
		else
		{
			printf("Red je prazan\n");
			
		}
	}
	getchar();
	getchar();
	return 0;


}