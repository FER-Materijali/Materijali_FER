
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SPrijelaz {
	char glava, ispis;
	int stanje;
} prijelaz;

int CreateTable(char *znak, int x, int y)
{
	FILE *fp, *ft, *fd;
	prijelaz *tab;
	int n, q, i, j, k, p;
	char *acc;

	if((fp=fopen("tablica.tab","w"))==NULL)		//binarna datoteka
    return 0;
 	if((ft=fopen("tablica.txt","w"))==NULL)		//tablica prijelaza
    return 0;
	if((fd=fopen("prijelazi.txt","w"))==NULL)	//popis prijelaza
    return 0;

	n=strlen(znak);	//broj znakova trake
	q=x+y+8;		//broj stanja

	acc = (char*) malloc(q);
	tab = (prijelaz*) malloc(n*q*sizeof(prijelaz));

	for(i=0; i<q; i++)
		acc[i]=0;
	acc[x+y+6]=1;

	for(i=0; i<q; i++)
	{
		for(j=0; j<n; j++)
		{
			p=i*n+j;
			if(i==0)				//pocetno, neprihvatljivo
			{	
				switch(j)
				{
				case 0:		//X
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 1:		//Y
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 2:		//Z
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 3:		//I
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 4:		//P
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 5:		//B
					tab[p].glava='R';
					tab[p].ispis='?';
					tab[p].stanje=x+y+7;
					break;
				case 6:		//ime
					tab[p].glava='R';
					tab[p].ispis=znak[0];
					if(x==1)
						tab[p].stanje=x+y+2;
					else
						tab[p].stanje=1;
					break;
				case 7:		//prezime
					tab[p].glava='R';
					tab[p].ispis=znak[1];
					tab[p].stanje=x+y+1;
					break;
				default:
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				}
			}
			else if(i>0 && i<x-1)	//prvi brojac
			{
				switch(j)
				{
				case 0:		//X
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 1:		//Y
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 2:		//Z
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 3:		//I
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 4:		//P
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 5:		//B
					tab[p].glava='L';
					tab[p].ispis='?';
					tab[p].stanje=x+y+5;
					break;
				case 6:		//ime
					tab[p].glava='R';
					tab[p].ispis=znak[3];
					tab[p].stanje=i+1;
					break;
				case 7:		//prezime
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				default:
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				}
			}
			else if(i==x-1)			//prvi brojac pri kraju
			{
				switch(j)
				{
				case 0:		//X
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 1:		//Y
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 2:		//Z
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 3:		//I
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 4:		//P
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 5:		//B
					tab[p].glava='L';
					tab[p].ispis='?';
					tab[p].stanje=x+y+5;
					break;
				case 6:		//ime
					tab[p].glava='L';
					tab[p].ispis=znak[3];
					tab[p].stanje=x+y+2;
					break;
				case 7:		//prezime
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				default:
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				}
			}
			else if(i>=x && i<x+y-1)//drugi brojac
			{
				switch(j)
				{
				case 0:		//X
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 1:		//Y
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 2:		//Z
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 3:		//I
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 4:		//P
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 5:		//B
					tab[p].glava='L';
					tab[p].ispis='?';
					tab[p].stanje=x+y+5;
					break;
				case 6:		//ime
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 7:		//prezime
					tab[p].glava='R';
					tab[p].ispis=znak[4];
					tab[p].stanje=i+1;
					break;
				default:
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				}
			}
			else if(i==x+y-1)		//drugi brojac pri kraju
			{
				switch(j)
				{
				case 0:		//X
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 1:		//Y
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 2:		//Z
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 3:		//I
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 4:		//P
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 5:		//B
					tab[p].glava='L';
					tab[p].ispis='?';
					tab[p].stanje=x+y+5;
					break;
				case 6:		//ime
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 7:		//prezime
					tab[p].glava='L';
					tab[p].ispis=znak[4];
					tab[p].stanje=x+y+3;
					break;
				default:
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				}
			}
			else if(i==x+y)			//prihvatljiva nula
			{
				switch(j)
				{
				case 0:		//X
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 1:		//Y
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 2:		//Z
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 3:		//I
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 4:		//P
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 5:		//B
					tab[p].glava='L';
					tab[p].ispis='!';
					tab[p].stanje=x+y+4;
					break;
				case 6:		//ime
					tab[p].glava='R';
					tab[p].ispis=znak[3];
					if(x==1)
						tab[p].stanje=x+y+2;
					else
						tab[p].stanje=1;
					break;
				case 7:		//prezime
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=x+y+1;
					break;
				default:
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				}
			}
			else if(i==x+y+1)		//neprihvatljiva nula
			{
				switch(j)
				{
				case 0:		//X
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 1:		//Y
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 2:		//Z
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=-1;
					break;
				case 3:		//I
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 4:		//P
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 5:		//B
					tab[p].glava='L';
					tab[p].ispis='?';
					tab[p].stanje=x+y+5;
					break;
				case 6:		//ime
					tab[p].glava='R';
					tab[p].ispis=znak[3];
					if(x==1)
						tab[p].stanje=x+y+2;
					else
						tab[p].stanje=1;
					break;
				case 7:		//prezime
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=x+y+1;
					break;
				default:
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				}
			}
			else if(i==x+y+2)		//premotavanje prvo
			{
				switch(j)
				{
				case 0:		//X
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=x;
					break;
				case 1:		//Y
					tab[p].glava='R';
					tab[p].ispis=znak[2];
					tab[p].stanje=x+1;
					break;
				case 2:		//Z
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=x;
					break;
				case 3:		//I
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 4:		//P
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=x;
					break;
				case 5:		//B
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 6:		//ime
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 7:		//prezime
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				default:
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				}
			}
			else if(i==x+y+3)		//premotavanje drugo
			{
				switch(j)
				{
				case 0:		//X
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=x+y;
					break;
				case 1:		//Y
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=x+y;
					break;
				case 2:		//Z
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=x+y;
					break;
				case 3:		//I
					tab[p].glava='R';
					tab[p].ispis=znak[j];
					tab[p].stanje=x+y;
					break;
				case 4:		//P
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 5:		//B
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 6:		//ime
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 7:		//prezime
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				default:
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				}
			}
			else if(i==x+y+4)		//zavrsno prihvatljivo premotavanje i obnavljanje trake
			{
				switch(j)
				{
				case 0:		//X
					tab[p].glava='R';
					tab[p].ispis=znak[6];
					tab[p].stanje=x+y+6;
					break;
				case 1:		//Y
					tab[p].glava='R';
					tab[p].ispis=znak[7];
					tab[p].stanje=x+y+6;
					break;
				case 2:		//Z
					tab[p].glava='R';
					tab[p].ispis=znak[7];
					tab[p].stanje=x+y+6;
					break;
				case 3:		//I
					tab[p].glava='L';
					tab[p].ispis=znak[6];
					tab[p].stanje=i;
					break;
				case 4:		//P
					tab[p].glava='L';
					tab[p].ispis=znak[7];
					tab[p].stanje=i;
					break;
				case 5:		//B
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 6:		//ime
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 7:		//prezime
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				default:
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				}
			}
			else if(i==x+y+5)		//zavrsno neprihvatljivo premotavanje i obnavljanje trake
			{
				switch(j)
				{
				case 0:		//X
					tab[p].glava='R';
					tab[p].ispis=znak[6];
					tab[p].stanje=x+y+7;
					break;
				case 1:		//Y
					tab[p].glava='R';
					tab[p].ispis=znak[7];
					tab[p].stanje=x+y+7;
					break;
				case 2:		//Z
					tab[p].glava='R';
					tab[p].ispis=znak[7];
					tab[p].stanje=x+y+7;
					break;
				case 3:		//I
					tab[p].glava='L';
					tab[p].ispis=znak[6];
					tab[p].stanje=i;
					break;
				case 4:		//P
					tab[p].glava='L';
					tab[p].ispis=znak[7];
					tab[p].stanje=i;
					break;
				case 5:		//B
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 6:		//ime
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				case 7:		//prezime
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				default:
					tab[p].glava='L';
					tab[p].ispis=znak[j];
					tab[p].stanje=i;
					break;
				}
			}
			else if(i==x+y+6)		//prihvatljivo stanje, kraj
			{
				tab[p].stanje=-1;
			}
			else if(i==x+y+7)		//neprihvatljivo stanje, kraj
			{
				tab[p].stanje=-1;
			}
		}
	}

//ispis tablice
	for(i=0; i<n; i++)
		fprintf(ft, "\t%c", znak[i]);
	fprintf(ft, "\t[ACC]");

	for(i=0; i<q; i++)
	{
		fprintf(ft,"\nq%d", i);
		for(j=0; j<n; j++)
		{
			p=i*n+j;
			if(tab[p].stanje==-1)
				fprintf(ft, "\t");
			else
				fprintf(ft, "\tq%d, %c, %c", tab[p].stanje, tab[p].ispis, tab[p].glava);
		}
		fprintf(ft, "\t%d", acc[i]);
	}
	fclose(ft);

//popis prijelaza
	k=0;
	for(i=0; i<q; i++)
	{
		for(j=0; j<n; j++)
		{
			p=i*n+j;
			if(tab[p].stanje!=-1)
			{
				fprintf(fd, "\nd(q%d, %c) -> (q%d, %c, %c)", i, znak[j], tab[p].stanje, tab[p].ispis, tab[p].glava);
				k++;
			}
		}
	}
	fclose(fd);

//ispis u binarnu datoteku  
	fwrite(&n, sizeof(int), 1, fp);
	fwrite(znak, 1, n, fp);
	fwrite(&q, sizeof(int), 1, fp);
	fwrite(acc, 1, q, fp);
	fwrite(tab, sizeof(prijelaz), q*n, fp);
	fclose(fp);

	printf("\nBroj znakova: %d", n);
	printf("\nZnakovi: %s", znak);
	printf("\nBroj stanja: %d", q);
	printf("\nBroj prijelaza: %d", k);

	return 0;
}

int main()
{
    CreateTable("XYZIPBipkul", 1, 3);
    getch();
    return 0;
}


