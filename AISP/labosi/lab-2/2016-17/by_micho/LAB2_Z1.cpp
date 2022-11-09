//Autor: Ljac

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct zapis						//Definiramo strukturu zapis
{
	int broj;						//koja ima cijelobrojni postanski broj
	char ime[41];					//te ime mjesta od 40 znakova.
};

void spc(int x)
{
     while(x--)
     printf("\n");
}

void insertionSort(zapis *A, int n, char smjer)	//Nasa funkcija prima pokazivac na strukturu zapisa, broj elemenata, i smjer sortiranja
{
	if(n < 2)						//Ako je velicina polja 1, polje je sortirano
	return;
	
	zapis t;						//Uzmimo neki pomocni zapis, nazvat cemo ga sa t
	
	smjer = !smjer;					//Za uzlazno smjer = 1; za silazno smjer = 0.
	
	if(!smjer)						//Ako je smjer 0 (silazno), smjer stavljamo u -1
	smjer = -1;						//Ovom operacijom ne mijenjamo smjer globalno, ali mozemo aritmeticki izbjeci if
	
	for(int i = 1, j; i < n; i++)	//Prolazi svim elementima pocevsi od 1.
	{
		t = A[i];					//Trenutni element upisemo u pocetno polje
		
		//Dokle god j ne dodje do prvog elementa i dok je element prije trenutnog veci/manji (regulirano smjerom kojeg smo podesili na nove vrijednosti)
		//u trenutni element stavljamo prethodni. Na taj nacin kao da pomicemo sve vece elemente udesno.
		for(j = i; j > 0 && (A[j - 1].broj * smjer) > (t.broj * smjer); j--)
		A[j] = A[j-1];
		
		A[j] = t;					//Element za jedno mjesto ulijevo od trenutnog je manji od naseg pocetnog, i-tog, pa na trenutno mjesto upisujemo i-ti element.
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
		printf("Unesite %d. postanski broj i naziv mjesta (od %d): ", i + 1, n);
		scanf(" %d", &A[i].broj);	//razmak prije %d osigurava da scanf ne procita nekakav ostatak od proslog scanfa.
		getchar();					//Scanf je malo luckast sa input bufferom (vise o tome na netu kog zanima), a getchar ga brise pa gets ne uzme newline.
		gets(A[i].ime);
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
	printf("[%d] %5d %s\n", i + 1, A[i].broj, A[i].ime);
	
	insertionSort(A, n, smjer);
	
	if(smjer)
	printf("\nSortiramo silazno:\n");
	else
	printf("\nSortiramo uzlazno:\n");
	
	for(i = 0; i < n; i++)
	printf("[%02d] %5d %s\n", i + 1, A[i].broj, A[i].ime);
	
	free(A);

    spc(2);
    system("pause");
    return 0;
}