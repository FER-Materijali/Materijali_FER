#include<stdio.h>
#include<stdlib.h>

void ispis(float *polje, int n) 			//Upisujemo polje floatova i njegovu velicinu
{
	if(*polje < 0)							//Ako smo naisli na negativan element, ispisujemo ga
	printf("%g ", *polje);
	if(n-1)									//Dok je n > 1 idemo dalje. Razlog zasto > 1 a ne > 0 je jednostavan
	ispis(++polje, --n);					//Upisujemo n brojeva, recimo 5 - n treba ici 5 -> 4 -> 3 -> 2 -> 1.
											//Ako je n = 1, ne pozivamo rekurziju jer bi to ispisivalo 6 clanova, koliko ih u polju nema
	return;
}

void spc(int x)								//Ovo je moja funkcija koji prima cijeli broj i radi toliko newlineova.
{
     while(x--)
     printf("\n");
}

int main()
{
	int i, n;								//Posto je ovo prastari C, moramo i sve indekse inicijalizirati.
	float *A;
											//Inace bih ovdje provjeravao je li n dobro unesen, ali nije trazeno u zadatku.
	printf("Unesite broj clanova koje zelite upisati u niz: ");
	scanf("%d", &n);
	spc(2);
	
	A = (float*)malloc(n * sizeof(float));	//Obicna alokacija memorije
	
	if(A)									//Ovo ce biti true ako A nije NULL, dakle ako je A dobro alociran:
	{
		printf("Upisite elemente niza A (realne brojeve): ");
		
		for(i = 0; i < n; i++)
			scanf("%f", &A[i]);
			
		spc(1);
			
		printf("Uspjesan unos. Negativni brojevi u nizu su: ");
		ispis(A, n);						//Nesretno je sto ne mozemo na lijepi nacin, bez destrukcije, ispisati da nema negativnih clanova.
	
		free(A);
		
		spc(2);
    	system("pause");
    	return 0;
	}
	else									//Ako nije dobro alociran, vratiti ce -1. Razlog zasto -1 a ne 0 je zato
	{										//sto ce 0 slucaj biti kad se program normalno izvrši, a -1 kad nema memorije.
		printf("Nema dovoljno memorije.");
		spc(2);
		system("pause");
		return -1;
	}
}


