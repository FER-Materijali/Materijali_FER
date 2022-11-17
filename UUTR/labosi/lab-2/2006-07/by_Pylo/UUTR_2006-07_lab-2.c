#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct PotAutomat
{
	int stanje;
	char *stog;
	struct PotAutomat *next;
} PA;
PA *a=NULL, *b=NULL;

int prihv=0;

int DodajStanje(char *stog, int stanje, char *z)
{
    int n;
    PA *t;
    t=b;
    
    n=strlen(stog)+strlen(z);
    
    b=(PA*) malloc(sizeof(PA));
    b->next=t;
    b->stanje=stanje;
    b->stog=(char*)malloc(n+1);
    strcpy(b->stog, stog);
	strcat(b->stog, z);
	b->stog[n]=0;
    return 0;
}

int NapraviPrijelaz(PA *trenutno, char c)
{
	int n;
	char s[3]={0};

	if(!trenutno) return 0;

	if(n=strlen(trenutno->stog))
	{
		s[0]=trenutno->stog[n-1];
		trenutno->stog[n-1]=0;
	}
	
	switch(trenutno->stanje)
	{
	case 0:
		s[1]=c+17;
		printf("\nTrenutno stanje: q0");
		printf("\nTrenutni stog: %s", trenutno->stog);
		//prvi prijelaz
		printf("\nFunkcija prijelaza: (q0, %c, %c) -> (q0, %c%c)", c, s[0], s[1], s[0]);
		DodajStanje(trenutno->stog, 0, s);
		printf("\nNovo stanje: q0");
		printf("\nNovi stog: %s", b->stog);
		printf("\nStanje nije prihvatljivo.\n");

		//drugi prijelaz
		if(c==s[0]-17)
		{
			printf("\nTrenutno stanje: q0");
			printf("\nTrenutni stog: %s", trenutno->stog);
			printf("\nFunkcija prijelaza: (q0, %c, %c) -> (q1, eps)", c, s[0]);
			DodajStanje(trenutno->stog, 1, "\0");
			printf("\nNovo stanje: q1");
			printf("\nNovi stog: %s", b->stog);
			printf("\nStanje nije prihvatljivo.\n");
		}
		break;
	case 1:
		if(c==s[0]-17)
		{
			printf("\nTrenutno stanje: q1");
			printf("\nTrenutni stog: %s", trenutno->stog);
			printf("\nFunkcija prijelaza: (q1, %c, %c) -> (q1, eps)", c, s[0]);
			DodajStanje(trenutno->stog, 1, "\0");
			printf("\nNovo stanje: q1");
			printf("\nNovi stog: %s", b->stog);
			printf("\nStanje nije prihvatljivo.\n");
		}
		break;
	case 2:
		prihv--;
		break;
	default:
		printf("Greska: stanje %d ne postoji.", trenutno->stanje);
	}

	//dodatni epslion prijelaz

	if(b && b->stanje==1 && strlen(b->stog)==1 && b->stog[0]==\\'K\\')
	{
		printf("\nTrenutno stanje: q1");
		printf("\nTrenutni stog: %s", trenutno->stog);
		printf("\nFunkcija prijelaza: (q1, eps, %c) -> (q2, eps)", s[0]);
		DodajStanje("\0", 2, "\0");
		printf("\nNovo stanje: q2");
		printf("\nNovi stog: ");
		printf("\nStanje je prihvatljivo.\n");
		prihv++;
	}
	return prihv;
}

int Ocisti(PA *old)
{
	PA *t;
	while(old)
	{
		t=old->next;
		free(old);
		old=t;
	}
	return 0;
}


    
int main()
{
	int i=0;
	FILE *fp;
	char ulaz[50]="ulaz.txt", niz[50];
	PA *t;

	fp=fopen(ulaz, "r");
	while(fp==NULL)
	{
		printf("\nDatoteka nije pronadena!");
		printf("\nUpisite ime datoteke: ");
		scanf("%s", ulaz);
		fp=fopen(ulaz, "r");
	}

 
	while(fscanf(fp, "%s", niz)!=EOF)  //uzima novi niz iz datoteke
	{
		Ocisti(a);
		Ocisti(b);
		b=NULL;
		DodajStanje("\0", 0, "K");
		prihv=0;
		i=0;
		printf("\n\n-- Ulazni niz iz datoteke: %s", niz);

		while(niz[i])                          //uzima znak iz ucitanog niza
		{
			a=b;
			b=NULL;
			printf("\n\n* Ucitani znak: %c\n", niz[i]);

			while(a)                       //obilazi sva trenutna stanja (grane)
			{
				t=a->next;
				NapraviPrijelaz(a, niz[i]);
				free(a);
				a=t;
			}
			i++;
		}

		if(prihv)	printf("\n\nNiz \"%s\" je prihvacen!\n\n", niz);
		else	printf("\nNiz \"%s\" nije prihvacen!\n\n", niz);
		printf("\n----------------------------------------------\n");
		system("PAUSE");
	}

	printf("\n\nKRAJ!\n");
	system("PAUSE");

    return 0;
}