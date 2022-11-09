#include<stdio.h>
#include<stdlib.h>

void f(int *polje, int n, int m)						//Racunamo m^(x element iz [1, n])
{
	if(n == 1)											//Na indeksu 0 nalazi se m jer je m^1 = m za svaki cijeli broj, ali naš n onda mora biti 1, jer 0 bi bio -1 indeks.
	*polje = m;
	else												//U suprotnom, zovemo funkciju za 1 umanjeni n, jer zelimo doci do m^1, pa onda
	{													//Svaki sljedeci indeks rijesiti mnozenjem prethodnog i m-a. m^x = m * m^(x-1) drugim rijecima.
		f(polje, n - 1, m);
		*(polje + n - 1) = m * (*(polje + n - 2));		//Svaka instanca funkcije ima ISTI pointer na polje. Da bi došli do indeksa koji nam treba,
	}													//trebamo traziti polje + n - 1 (npr. za n = 1., to je polje + 1 - 1, tj. 0. indeks.
}

void spc(int x)
{
     while(x--)
     printf("\n");
}

int main()
{
	int n, m, *polje;
	short i;
	
	printf("Upisite cjelobrojnu velicinu polja: ");
	scanf("%d", &n);
	printf("\nUpisite neki cijeli broj: ");
	scanf("%d", &m);
	
	polje = (int*)malloc(n * sizeof(int));
	spc(2);
	
	f(polje, n, m);										//Funkcija je tipa void, pa ju trebamo pokrenuti prije ispisa.
	
	printf("Potencije broja %d su redom: ", m);
	for(i = 0; i < n; i++)
	printf("%d ", polje[i]);

	free(polje);
	
    spc(2);
	//system("pause");
    return 0;
}
