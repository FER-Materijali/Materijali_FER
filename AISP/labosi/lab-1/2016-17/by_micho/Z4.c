#include<stdio.h>
#include<stdlib.h>
#include<math.h>
																	//Nazvali su exp po funkciji u math.h, promijenio sam naziv u expo
																	//Mozda je to zato da se potencija racuna u odvojenoj funkciji, ali rekao bih da je ovako bolje. Svejedno, ne break-a cijeli zadatak.
double expo(double x, int n, int *fakt, double *xpot)				//Da bi se program izvrsavao u O(n), faktorijele treba izvan
{																	//funkcije izracunati, xpot mozemo racunati u funkciji.
	if(n)															//Dok je n > 1, imamo konkretne clanove, jer 0. clan u formuli ne postoji.
	{
		xpot[n-1] = pow(x, n-1);									//Nasi indeksi idu od [0, n-1], dok n ide od [1, n]. Zato n - 1 u indeksu i potenciranju
		double clan = xpot[n-1] / fakt[n-1];						//clan je ono sto cemo pribrajati pocetnom stanju, tj. 1. to su npr. x, x^2/2! itd.
		return clan + expo(x, n - 1, fakt, xpot);					//Pribrajamo trenutni clan prethodnom, dok ne doðemo do 1 (koja je na n = 1
	}
	else
	return 0.0;														//Nulti clan ne postoji, pa je jednak 0.0. Razlog zasto ne 0 su moguce komplikacije, kao i u 3. zadatku.
}

int factorial(int n)												//Ovime racunamo faktorijele za polje od n clanova.
{
	if((n == 1) || (n == 0))										//0! i 1! su 1.
	return 1;
	else
	return n * factorial(n-1);										//Za sve ostale rekurzivno mnozimo faktore do 1.
}

void spc(int x)
{
     while(x--)
     printf("\n");
}

int main()
{
	int i, n, *fakt;												//Svi faktorijeli cijelih brojeva su cijeli brojevi.
	double *xpot;													//Zelim da nase potencije budu preciznije od jednostruke preciznosti
	float *A, x;
	
	nijepoz:														//Inace ovaj goto nemojte raditi. U principu ne treba provjera, pa mozete obrisati redove:
	printf("Unesite prirodnu velicinu polja manju od 13: ");		//38, [43, 52], [56,63]. Razlog zasto sam je ostavio je jer za vece brojeve rezultati nisu tocni zbog preljeva. Moze se i sa do while-om, pa bude "legalno"
	scanf("%d", &n);
	spc(2);
	
	if(n <= 0 || n >= 13)
	{
		printf("Unos velicine polja nije ispravan.");
		spc(2);
		system("pause");											//Ceka da nesto upisemo.
		system("CLS");												//Brise sto je upisano u konzoli. Ekvivalenta clc u MATLABu.
		goto nijepoz;
	}
	
	prevelik:
	printf("Unesite realni broj x manji od 88: ");
	scanf("%f", &x);
	
	if(x >= 88)
	{
		printf("Potencija broja e je prevelika da bi stala u 4 bajta!");
		spc(2);
		system("pause");
		system("CLS");
		goto prevelik;
	}
	spc(2);
	
	A = (float*)malloc(n * sizeof(float));							//A je polje izracunatih clanova
	xpot  = (double*)malloc(n * sizeof(double));					//polje potencija
	fakt  = (int*)malloc(n * sizeof(int));							//polje faktorijela - sve su velicine n.
	
	for(i = 0; i < n; i++)											//Tu cemo za sve clanove izracunati faktorijele, ali i zadatak.
	{
		fakt[i] = factorial(i);
		A[i] = expo(x, i+1, fakt, xpot);
		printf("%2d. aproksimacija e^(%g) = %20.6f\n", i+1, x, A[i]);	//Odmah ih sve i ispisujemo
	}
	
	spc(2);
	
	free(A);														//Sve sto smo zauzeli moramo i osloboditi, kao i Jeruzalem od nevjernika :^)
	free(xpot);
	free(fakt);
	
	//-------------------------------------------------------------D E U S   V U L T---------------------------------------------------------------

    spc(2);
    system("pause");
    return 0;
}
