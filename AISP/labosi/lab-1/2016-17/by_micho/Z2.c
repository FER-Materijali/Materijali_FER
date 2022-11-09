#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int zbrojiKvadrate(int *polje, int n)					//Trebamo naci savrsene kvadrate te ih zbrojiti.
{														//Savrseni kvadrati su brojevi koji su kvadrati pozitivnog cijelog broja.
	double korijen = sqrt(*polje);						//Definiramo neki double koji ce biti jednak korijenu trenutnog elementa u polju.
	int ckorijen = korijen;								//Onda cemo definirati integer i pridruziti mu necastanu vrijednost tog korijena
	
	if(n)												//Kako je n broj elemenata, dok je n veci od nule radimo tu funkciju. Npr. za n = 5, izvrsavamo to 5 puta.
	{
		if(ckorijen == korijen)							//Ako je broj savrseni kvadrat, onda ce cjelobrojni korijen i double korijen biti jednaki.
		return *polje + zbrojiKvadrate(++polje, --n);	//I normalno, zbrojit cemo trenutni clan sa rekurzijom za sljedeci clan i za 1 manji n.
		else
		zbrojiKvadrate(++polje, --n);					//Ako element nije savrseni korijen, samo idemo dalje po polju, bez zbrajanja.
	}
	else
	return 0;											//Za n = 0, kako nemamo uopce element vise (to je n + 1 clan), vracamo 0.
}														//Ako npr. u nizu nema savrsenih korijena, onda je i njihov zbroj 0, za sto je ovaj return zgodan.

void spc(int x)
{
     while(x--)
     printf("\n");
}

int main()
{
    srand(time(NULL));									//Imamo rand u zadatku pa nam ovo treba.
    
    int i, n, *A;
	
	printf("Unesite broj clanova koje zelite upisati u niz: ");
	scanf("%d", &n);
	spc(2);
	
	A = (int*)malloc(n * sizeof(int));
	
	printf("Polje glasi: ");
	
	for(i = 0; i < n; i++)								//Kao sto smo rekli, ispisujemo polje nasumicnih cijelih brojeva [1, 100]
	{
		A[i] = rand()%100 + 1;
		printf("%d ", A[i]);
	}
		
	spc(2);
	printf("Zbroj clanova koji su savrseni kvadrati je %d.", zbrojiKvadrate(A, n));
	
	free(A);
	
    spc(2);
    system("pause");
    return 0;
}
