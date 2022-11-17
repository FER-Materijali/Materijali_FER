
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 512
#define PRINT 0

typedef struct SPrijelaz {
	char glava, ispis;
	int stanje;
} prijelaz;


prijelaz *tab;
int brstanja;
char *prihv;

char *znak;
int brznak=0;

int UcitajTablicu(char *ime)
{
	FILE *ft;
	if((ft=fopen(ime, "r"))==NULL)
		return 0;
	
	fread(&brznak, sizeof(int), 1, ft);
	printf("\n------------------------------");
	printf("\nBroj znakova: %d", brznak);
	znak = (char*) malloc(brznak+1);
	fread(znak, 1, brznak, ft);
	znak[brznak]=0;
	printf("\nZnakovi trake: %s", znak);

	fread(&brstanja, sizeof(int), 1, ft);
	printf("\nBroj stanja: %d", brstanja);

	prihv = (char*) malloc(brstanja);
	fread(prihv, 1, brstanja, ft);
	tab = (prijelaz*) malloc(brstanja*brznak*sizeof(prijelaz));
	fread(tab, sizeof(prijelaz), brstanja*brznak, ft);

	printf("\n------------------------------\n");
	fclose(ft);
	return 1;
}

int IspisiTraku(char *traka, int glava)
{
	int i=0;

	printf("\nStanje trake: ");
	for(i=0; i<strlen(traka); i++)
	{
		if(i==glava)	printf("[%c]", traka[i]);
		else	printf("%c", traka[i]);
	}
	
	return 0;
}

int NapraviPrijelaz(char *traka, int *glava, int *stanje)
{
	char c;
	int novo, i, n;

	if(*glava<0 || *glava>=MAX)	return 1;
	if(*stanje>=brstanja || *stanje<0) return 1;

	c=traka[*glava];

	for(i=0; i<brznak; i++)
	{
		if(c==znak[i]) break;
	}

	if(i>=brznak)	return 1;
	n=(*stanje)*brznak+i;

	novo = tab[n].stanje;
	if(novo==-1)	return 1;

	traka[*glava] = tab[n].ispis;

	switch(tab[n].glava)
	{
	case 'L':
		(*glava)--;
		break;
	case 'R':
		(*glava)++;
		break;
	default:
		return 1;
	}

	if(PRINT) printf("\nFunkcija prijelaza: d(q%d, %c) -> (q%d, %c, %c)", *stanje, c, novo, tab[n].ispis, tab[n].glava);
	*stanje=novo;

	return 0;
}



int Automat(char *traka)
{
	int i=0;
	int stanje=0;
	int glava=0;

	while(1)
	{
		IspisiTraku(traka, glava);
		if(PRINT) printf("\nStanje automata: q%d", stanje);
		if(NapraviPrijelaz(traka, &glava, &stanje))
			break;
		if(PRINT)
		{
			printf("\nNovo stanje: q%d", stanje);
			if(prihv[stanje])
				printf("\nStanje je prihvatljivo.\n");
			else
				printf("\nStanje nije prihvatljivo.\n");
		}
	}

	printf("\nSTOP");
	if(prihv[stanje])
		printf("\nNiz je prihvacen.\n");
	else
		printf("\nNiz nije prihvacen.\n");
	
	return 0;
}


int main ()
{
	FILE *fu;
	char traka[MAX]={0};

	printf("\nUcitavam automat...");
	if(UcitajTablicu("tablica.tab")==NULL)
	{
		printf("\nGreska pri ucitavanju tablice");
		getch();
		return 0;
	}

	if((fu=fopen("ulaz.txt", "r"))==NULL)
	{
		printf("\nUlazna datoteka ne postoji!");
		getch();
		return 0;
	}

	while(fscanf(fu, "%s", traka)!=EOF)
	{
		getch();
		strcat(traka, "BB");
		printf("\n\n------------------------------");
		printf("\nNovi ulaz\nTraka: %s", traka);
		printf("\n------------------------------\n");
		
		Automat(traka);
		memset(traka, 0, MAX);
	}

	printf("\n----------------------");
	printf("\nKraj izvrsavanja!");
	fclose(fu);
	getch();
	return 0;
}
