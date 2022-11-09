#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#pragma warning(disable:4996)
#define MAX 100

typedef struct
{										//struktura za stog
	int vrh, polje[MAX];
}Stog;

void init_stog(Stog* stog)			//inicalizacija stoga
{
	stog->vrh = -1;
}

int dodaj(int element, Stog* stog)			//dodavanje elemenata na stog
{
	if (stog->vrh >= MAX - 1) return 0;
	stog->vrh++;
	stog->polje[stog->vrh] = element;
	return 1;
}

int main(void)
{
	int i, broj;
	Stog* stog;
	init_stog(&stog);					//inicalizacija stoga
	srand((unsigned)time(NULL));
	for (i = 0;i <= MAX;i++)				//upisivanje random brojeve na stog
	{
		broj = rand();
		if (dodaj(broj, &stog))				//ispitivanje uspjesnosti dodavanja elemenata na stog
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