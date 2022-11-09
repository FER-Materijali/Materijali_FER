#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#pragma warning(disable:4996)
#define MAX 10

typedef struct
{								//struktura za stog
	int vrh, polje[MAX];
}Stog;

void init_stog(Stog* stog)		//inicalizacija stoga
{
	stog->vrh = -1;
}



int dodaj(int element, Stog* stog)			//upisivanje elemenata na stog
{
	if (stog->vrh >= MAX - 1) return 0;
	stog->vrh++;
	stog->polje[stog->vrh] = element;
	return 1;
}

int skini(int *element, Stog *stog)		//skidanje elemenata sa stoga
{

	if (stog->vrh < 0) return 0;
	*element = stog->polje[stog->vrh];
	stog->vrh--;
	return 1;
}

void ispis_stoga(Stog *stog,Stog* pomstog)
{
	
	int neki_element_sa_stoga;

	
	
		printf("Stog:\n");
		while(1)											//skidamo elemente sa stoga
		{													//tako da mozemo ubaciti na pomocni stog
			if (!skini(&neki_element_sa_stoga,stog))
			{
				break;
			}
			dodaj(neki_element_sa_stoga, pomstog);

		} 

		while(1)
		{
			if(!skini(&neki_element_sa_stoga, pomstog))		//skidamo elemente sa  pomocnog stoga
			{												//da ih mozemo ispisati 
				break;
			}
			printf("%d \n", neki_element_sa_stoga);
			dodaj(neki_element_sa_stoga, stog);				//vracamo elemente na prvi stog
															//ponovno vracanje na prvi stog nije potrebno
		}													//radi se samo da bi ostao isti stog



			
}
		
		




int main(void)
{
	int i, broj;
	Stog stog;
	Stog pomstog;
	
	init_stog(&stog);					//inicalizacija stoga

	srand((unsigned)time(NULL));
	for (i = 0;i < MAX;i++)				//ubacivanje na stog
	{
		broj = (int)((float)rand() / (RAND_MAX + 1) * 10 + 1);
		if (dodaj(broj, &stog))
		{
			printf("%d\n",broj);
		}
		else
		{
			printf("Overflow!");
			break;
		}
	}
	
	printf("Ispis:\n");      
	init_stog(&pomstog);	//inicalizacija stoga
	
	ispis_stoga(&stog,&pomstog);  //ispis 
	getchar();
	getchar();
	return 0;

}