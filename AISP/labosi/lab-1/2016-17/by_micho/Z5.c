#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int binarnoTrazi(float *polje, int n, float x)
{
	int dgranica = 0, 								//donja granica
		ggranica = n - 1, 							//gornja granica
		indeks = ggranica/2,						//indeksu u "sredini" je na pocetku polovica gornje granica
		povrat = -1;								//Varijabla koju cemo "returnati". Ako nema elementa kojeg trazimo, vracamo -1.
		
	float usporedba = 1.0f;							//Ovo je razlika trazenog broja od trenutnog elementa u polju.
	
	while(dgranica <= ggranica)						//Kad zadnji moguci clan nije onaj kojeg trazimo, ovo nece vrijediti - vidi predavanja.
	{
		if(fabs(polje[indeks] - x) < 10e-6)			//Ovo rjesava neki cudni bug u C-u - ugl. float u polju i samostalni float su RAZLICITI iako su isti brojevi, nemam pojma zasto.
		usporedba = 0;								//Osigurava da ako je ta razlika manja od 10e-6, onda je automatski 0. 3.3 == 3.3 mi nije vracalo 1 iz nekog razloga.
		else
		usporedba = polje[indeks] - x;				//Ako razlika nije mala, onda ju izracunaj normalno.
		  
		if(!(usporedba))							//Negacija 0 je 1. Negacija broja =/= 0 je 0.
		{
			povrat = indeks;						//Na varijablu koju vracamo stavljamo indeks, jer je trazeni broj na tom mjestu.
			break;									//I prekidamo petlju
		}
		
		else if(x < polje[indeks])					//Ako je trazeni x manji od trenutnog elementa
		ggranica = indeks-1;						//Pomicemo gornju granicu na element lijevo od trenutnog
		else
		dgranica = indeks+1;						//U suprotnom donja granica je sada element desno od indeksa.
		
		if(dgranica > ggranica)						//Ako je donja granica veca od gornje, necemo ici dalje sa izvrsavanjem.
		break;
		else										//U suprotnom, nas novi indeks je sljedeci. Ovo je jednako (dg+gg)/2, ali moramo to ovako zapisati zbog cijelobrojnog dijeljenja
		indeks = dgranica + (ggranica-dgranica)/2;
	}
	
	return povrat;
}

void spc(int x)
{
     while(x--)
     printf("\n");
}

int main()
{
	int i, n;
	float *A, x;
	
	printf("Unesite cjelobrojnu velicinu polja: ");
	scanf("%d", &n);
	spc(2);
	
	A = (float*)malloc(n * sizeof(float));
	
	printf("Clanovi polja te velicine su: ");
	for(i = 0; i < n; i++)
	{
		if(i%15 == 0)								//Opet, ispisujemo 15 elemenata u 1. redu
		spc(1);
		
		A[i] = i * 1.1f;							//U zadatku je zadana ova formula.
		printf("%g ", A[i]);
	}
	spc(2);
	
	printf("Unesite realan broj x kojeg zelite naci: ");
	scanf("%f", &x);
	spc(2);
	
	int clan = binarnoTrazi(A, n, x);				//clan ce sadrzavati indeks trazenog elementa
	
	spc(2);
	
	if(clan > -1)
	printf("Trazeni clan nalazi se na %d. indeksu u polju.", clan);
	else
	printf("Broj se ne nalazi u polju.");
	
	free(A);
	
    spc(2);
    system("pause");
    return 0;
}
