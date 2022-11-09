//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

void spc(int x)
{
     while(x--)
     printf("\n");
}

void spojiNizove(char *A, char *B, char *Rez)
{
	while(*A != 0 || *B != 0)					//Dok nismo dosli do kraja i A i B, vrti se petlja
	{
		if(*A != 0 && (*B == 0 || *A >= *B))	//Proucite uvjet
		*Rez = *(A++);
		else
		*Rez = *(B++);
												//Na kraju svakog upisa. pomicemo Rez za jedno mjesto udesno, i pisemo 0.
		*(++Rez) = 0;							//Neki bi rekli da je ovo neefikasno, ali na ovaj nacin se string cuva ako program prekine prije
												//nego sto dodje do kraja A i B.
	}
}

int main()
{
	char A[] = "ecaDB";
	char B[] = "dbECA";
	
	int sizeA = (sizeof(A) / sizeof(*A)) - 1;	//Definiramo velicinu elemenata u poljima A i B.
	int sizeB = (sizeof(B) / sizeof(*B)) - 1;
	
	int sizeRez = sizeA + sizeB + 1;			//Velicina sizeA + sizeB, ali +1 jer oba sizeova imaju broj slova, ali ne i /0.
	char *Rez = (char*)malloc(sizeRez * sizeof(char));
	
	spojiNizove(A, B, Rez);
	
	cout << "Prvi niz znakova je: ";
	puts(A);
	
	cout << "Drugi niz znakova je: ";
	puts(B);
	spc(1);
	
	cout << "Rezultantni niz znakova je: ";
	puts(Rez);
	
	free(Rez);
	
    spc(2);
    system("pause");
    return 0;
}