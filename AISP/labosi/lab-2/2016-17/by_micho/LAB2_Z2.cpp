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

void swap2(int *e1, int *e2)	//Zamijenjuje 2 integera.
{
	int t = *e1;
	*e1 = *e2;
	*e2 = t;
}

//Dvostrani selection sort u jednom prolazu trazi najmanji i najveci element odjednom.
//Na ovaj nacin presjekli smo broj izvrsavanja na pola, ali slozenost je jos uvije n^2.
//Ovo radimo na nacin da nadjemo indekse najveceg i najmanjeg, pa nakon prolaska kroz polje
//jednostavno napravimo dvije zamjene; najmanji sa lijevim ispitanikom, najveci sa desnim ispitanikom.
//Cak ni kada je niz neparne velicine se stvar ne komplicira, jer ce srednji clan uvijek biti sortiran.
void selection2Sort(int *A, int n, char smjer)
{
	if(n < 2)					//Nizovi velicine 1 su vec sortirani
	return;
	
	//Pretvorba uzlazno u (1), silazno u (-1)
	smjer = !smjer;
	if(!smjer)
	smjer--;
	
	for(int i = 0; i < n/2; i++)	//Idemo do n/2, dakle ako je n = 4, idemo do 2 (indeksi 0 i 1 samo), a za 5 isto (0, 1, indeks 2 je automatski sortiran)
	{
		int lijevi = i, desni = n - 1 - i;	//Lijevi je na i-tom indeksu slijeva, a desni na i-tom indeksu zdesna.
		int min = lijevi, max = desni;		//Najmanji je lijevi, a najveci je desni. Naravno, ovo ne uzima u obzir smjer, ali to je pokriveno aritmeticki.
		
		if(A[min] * smjer > A[max] * smjer)	//Prvo cemo osigurati da nam je lijevi manji od desnog. Razlog je da se izbjegnu zapetljavanja 
		swap2(&A[min], &A[max]);			//npr. za 4 3 2 bi rekli da je min na 2, a maks na 4, 1. korak daje 2 3 4, a 2. korak 4 3 2. To smo ovime izbjegli.
		
		for(int j = lijevi + 1; j <= desni; j++)	//Prvi koji treba provjeriti je lijevi + 1 (s lijevim). Desni cemo provjeravati uvijek s onim nalijevo trenutnog.
		{											//Moglo se i obrnuto, dakle lijevi sa j + 1, a desni sa j, ali onda j < desni mora biti uvjet.
			if(A[j] * smjer < A[min] * smjer)
			min = j;
			
			if(A[j - 1] * smjer > A[max] * smjer)
			max = j - 1;
		}
		
		swap2(&A[lijevi], &A[min]);			//Nakon sto smo nasli maksimume i minimum, zamijenjujemo im mjesta.
		swap2(&A[desni], &A[max]);
	}
}

int main()
{
	int n, *A, i = 0;								//Definiram i = 0 zbog do-whilea neposredno nakon definicija.
	char smjer = 0;									//Nije potrebno definirati, ali po defaultu sortira uzlazno.
	
	do
	{
		system("CLS");								//funckija koja cisti ekran
		
		if(i)										//Ne pokrece se 1. puta
		printf("Velicina polja ne odgovara uvjetima, ponovite upis.\n");
		
		printf("Unesite velicinu polja [1, 10]: ");
		scanf(" %d", &n);
		i = n < 1 || n > 10;						//Polje ne moze biti manje od 0 ili vece od 10. Ako je ijedno od tog, i je 1, tj. unos nije valjan.
		spc(2);
	}
	while(i);
	
	A = (int*)malloc(n * sizeof(int));
	
	if(!A)
	{
		printf("Neuspjesna alokacija memorije.\nIzlazim...");
		exit(-1);
	}
	
	system("CLS");
	
	for(i = 0; i < n; i++)
	{
		printf("Unesite %d. broj (od %d): ", i + 1, n);
		scanf(" %d", &A[i]);
		spc(2);
	}
	
	i = 0;
	
	if(n > 2)										//Ako je n = 1 ili manje (zapravo nemoguce da je manji od 1 zbog inicijalnih uvjeta), niz je sortiran u oba smjera.
	{
		do
		{
			system("CLS");
		
			if(i)
			printf("Pogresan unos, pokusajte ponovo.\n");
		
			getchar();
			printf("Sortirati uzlazno (0) ili silazno (1)?\n");
			cin >> smjer;							//Scanf tu prouzrokuje korupciju stoga, zbog toga koristim cin koji inace ne koristim.
			smjer -= '0';
			i = (smjer != 0 && smjer != 1);
			spc(2);
		}
		while(i);
	}
	
	system("CLS");
	
	printf("Polje:\n");
	for(i = 0; i < n; i++)
	printf("[%d] %10d\n", i + 1, A[i]);
	
	selection2Sort(A, n, smjer);
	
	if(smjer)
	printf("\nSortiramo silazno:\n");
	else
	printf("\nSortiramo uzlazno:\n");
	
	for(i = 0; i < n; i++)
	printf("[%02d] %10d\n", i + 1, A[i]);
	
	free(A);

    spc(2);
    system("pause");
    return 0;
}