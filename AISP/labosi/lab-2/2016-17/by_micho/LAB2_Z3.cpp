//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct zapis
{
	int kod;
	char naziv[51];
};

void spc(int x)
{
     while(x--)
     printf("\n");
}

void swap2(zapis *e1, zapis *e2)	//Zamijenjuje 2 strukture zapis.
{
	zapis t = *e1;
	*e1 = *e2;
	*e2 = t;
}

void obicanBubbleSort(zapis *A, int n, char smjer)
{
	if(n < 2)					//Nizovi velicine 1 su vec sortirani
	return;
	
	//Pretvorba uzlazno u (1), silazno u (-1)
	smjer = !smjer;
	if(!smjer)
	smjer--;
	
	for(int j = 0; j < n; j++)			//Ovo je obican bubblesort, dakle ovdje n puta moramo proci
	{									//kroz polje da bismo bili sigurni da je sortirano
		for(int i = 0; i < (n-1); i++)	//Idemo do predzadnjeg, jer provjeravamo jedan udesno
		{
			if(smjer * A[i].kod > smjer * A[i + 1].kod)
			swap2(&A[i], &A[i+1]);		//Zamijenjujemo trenutni element i jedan udesno
		}
	}
}

int main()
{
	int n = 0, i = 0;
	char smjer = 0;
	zapis *A;						//A ce nam ovdje biti pokazivac na prvi element niza tipa zapis.
	
	do
	{
		system("CLS");				//Ovo samo brise ekran u cmd-u, radi preglednosti.
		
		if(i)
		printf("Velicina polja ne odgovara uvjetima, ponovite upis.\n");
		
		printf("Unesite velicinu polja [1, 10]: ");
		scanf("%d", &n);
		i = n < 1 || n > 10;		//i poprima 1 ako je unos nevaljan, a 0 ako je dobar.
		spc(2);
	}
	while(i);
	
	A = (zapis*)malloc(n * sizeof(zapis));
	
	if(!A)
	{
		printf("Neuspjesna alokacija memorije.\nIzlazim...");
		exit(-1);
	}
	
	system("CLS");
	
	for(i = 0; i < n; i++)
	{
		printf("Unesite %d. kod i naziv jela (od %d): ", i + 1, n);
		scanf(" %d", &A[i].kod);	//razmak prije %d osigurava da scanf ne procita nekakav ostatak od proslog scanfa.
		getchar();					//Scanf je malo luckast sa input bufferom (vise o tome na netu kog zanima), a getchar ga brise pa gets ne uzme newline.
		gets(A[i].naziv);
		spc(2);
	}
	
	if(n > 2)
	{
		i = 0;
		
		do
		{
			system("CLS");
		
			if(i)					//Ne pokrece se isprva jer smo i stavili na 0
			printf("Pogresan unos, pokusajte ponovo.\n");
		
			printf("Sortirati uzlazno (0) ili silazno (1)?\n");
			
			cin >> smjer;			//Izvodimo ovu vratolomiju jer scanf zna koruptirati stog i uništiti neku vrijednost.
			smjer -= '0';
			i = (smjer != 0 && smjer != 1);	//Pridodajemo i-ju 1 ako unos nije dobar, a 0 ako je dobar.
			spc(2);
		}
		while(i);					//Ako je i = 1, unos nije dobar, ponovno unosimo.

	}
	
	system("CLS");
	
	printf("Polje:\n");
	for(i = 0; i < n; i++)
	printf("[%d] %10d %s\n", i + 1, A[i].kod, A[i].naziv);
	
	obicanBubbleSort(A, n, smjer);
	
	if(smjer)
	printf("\nSortiramo silazno:\n");
	else
	printf("\nSortiramo uzlazno:\n");
	
	for(i = 0; i < n; i++)
	printf("[%02d] %10d %s\n", i + 1, A[i].kod, A[i].naziv);
	
	free(A);

    spc(2);
    system("pause");
    return 0;
}