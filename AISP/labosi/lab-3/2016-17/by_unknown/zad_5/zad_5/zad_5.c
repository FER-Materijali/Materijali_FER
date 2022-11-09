#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
#pragma warning(disable:4996)

typedef struct node
{
	int element;				//struktura za listu
	struct atom* next;
}atom;

typedef struct
{
	atom* vrh;					//struktura za  vrh stoga
}Stog;
void init_stog(Stog* stog)
{
	stog ->vrh = NULL;			//inicalizacija stoga
}

int dodaj_Stog(int broj, Stog *stog) {				//dodavanje elemenata na stog
	atom *novi;
	novi = (atom *)malloc(sizeof(atom));
	if (novi == NULL) return 0;
	novi->element = broj;
	novi->next = stog->vrh;
	stog->vrh = novi;
	return 1;
}

int main(void)
{
	int i, broj;
	Stog* stog;
	init_stog(&stog);				//inicalizacija stoga
	srand((unsigned)time(NULL));
	for (i = 0;i <= MAX;i++)
	{
		broj = rand();						//upisivanje random brojeve na stog
		if (dodaj_Stog(broj, &stog))		//ispitivanje uspjesnosti dodavanja elemenata na stog
		{
			printf("Uspjesno!\n");
		}
		else
		{
			printf("Overflow!");
			break;
		}
	}
	getchar();
	return 0;

}