//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define sizeA 5										//velicina polja A i B su 5.
#define sizeB 5

using namespace std;

void spc(int x)
{
     while(x--)
     printf("\n");
}

void prIntArray(int *polje, int n)					//Jednostavna fja za ispisivanje niza intova
{
	for(int i = 0; i < n; i++)
	{
		if(i%15 == 0)								//Radi urednosti stavlja newline svakih 15 brojeva, pocevsi od 1.
		spc(1);
		
		printf("%2d ", polje[i]);
	}
	spc(1);
}

void spojiPolja(int *A, int *B, int *Rez, int n1, int n2)
{
	int j = n1 + n2;								//j je velicina polja Rez
	int begin1 = 0, begin2 = 0;						//pocetni indeksi 1. i 2. podpolja su 0.
	
	for(int i = 0; i < j; i++)						//Dok ne dodje do kraja Rez-a uvrstava brojeve
	{
		if(begin1 < sizeA && (begin2 >= sizeB || A[begin1] >= B[begin2]))	//Treba dobro procitat uvjet
		Rez[i] = A[begin1++];
		else
		Rez[i] = B[begin2++];
	}
}

int main()
{
	int A[] = {9, 7, 5, 3, 1};						//U zadatku ne pise da su A i B dinamicka polja, pa ih mozemo ovako definirati, jednostavno.
	int B[] = {8, 6, 4, 2, 0};
	
	int *Rez = (int*)malloc((sizeA + sizeB) * sizeof(int));	//sizeA i sizeB su konstante za ovaj zadatak, navedene u linijama 6 i 7.
	
	cout << "Prvo polje je: ";
	prIntArray(A, sizeA);
	
	cout << "Drugo polje je: ";
	prIntArray(B, sizeB);
	spc(1);
	
	spojiPolja(A, B, Rez, sizeA, sizeB);
	
	cout << "Rezultantno polje je:";
	prIntArray(Rez, (sizeA + sizeB));

    spc(2);
    system("pause");
    return 0;
}