#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *kvadrand(int *polje, int n)								//Funkcija ce primati pointer na cjelobrojno polje te njenu velicinu.
{
	int x;
	short i;
	int *npolje = (int*)malloc(n * sizeof(polje));				//Nase novo polje imati ce jednaku velicinu kao i prvotno polje.
	
	for(i = 0; i < n; i++)										//Na svako mjesto novog polja upisat cemo kvadrat elementa starog polja
	*(npolje++) = polje[i] * polje[i];
	
	npolje -= n;												//Pomicali smo pokazivac, pomicemo ga na pocetak.
	
	for(x = n - 1; x > 0; x--)									//x je nas element posljednjeg elementa u polju koje bi trebalo sortirati
	{
		int temp, telement = rand()%(x + 1);					//Biramo element nekog niza od [0, n - 1]
		
		temp = npolje[x];										//Zamijenjujemo elemente na posljednjem i na telement-nom indeksu
		npolje[x] = npolje[telement];
		npolje[telement] = temp;
	}															//Kazemo - OK, sada nam je zadnji indeks za 1 manji, tako da onaj koji smo premjestili vise nikad ne diramo
	
	return npolje;												//Vracamo pointer na novo polje
}																//Za sve ovo stavio sam i sliku koja objasnjava ovaj proces.

void spc(int x)
{
     while(x--)
     printf("\n");
}

int main()
{
	srand(time(NULL));											//Treba nam za rand u kvadrandu.
    int i, n, *polje, *npolje;									//Ovdje cemo odmah deklarirati pokazivac na polje koje trebamo.
    
	printf("Unesite broj clanova koje zelite upisati u niz: ");
	scanf("%d", &n);
	spc(2);
	
	polje = (int*)malloc(n * sizeof(int));
	
	printf("Upisite cjelobrojne clanove polja: ");
	for(i = 0; i < n; i++)
	scanf("%d", &polje[i]);
	spc(2);
	
	npolje = kvadrand(polje, n);
	
	printf("Novo polje je: ");
	
	for(i = 0; i < n; i++)										//Ispisujemo novo polje po clanovima.
	printf("%d ", *(npolje++));

    spc(2);
    system("pause");
    return 0;
}
