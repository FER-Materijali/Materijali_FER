#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXSTOG 20

int stavi(int stog[], int *vrh, int zstog)
{	if(*vrh>MAXSTOG-1)
	{	printf ("\nNema dovoljno mjesta na stogu!");
		exit(0);
	}
	(*vrh)++;
	stog[*vrh] = zstog;
	return 1;
}

int skini(int stog[], int *vrh, int *zstog)
{	if(*vrh<0)
	{	printf ("\nStog je prazan!");
		exit(0);
	}
	*zstog=stog[*vrh];
	(*vrh)--;
	return 1;
}

void uznak(int znak)
{	if(znak==-48)printf("\nUcitava se znak: nema vise znakova");
	else printf("\nUcitava se znak za provjeru: %d",znak);
}

void sstog(int zstog)
{	if(zstog==75) printf("\nSKIDA se sa stoga: K");
	else printf("\nSKIDA se sa stoga: %d",zstog);
}

void nstog(int zstog,int n)
{	if(zstog==75) printf("\nSTAVLJA se na stog: K");
	else
	{	if (n==1)printf("\nSTAVLJA se na stog: %d",zstog);
		else printf(", %d",zstog);
	}
}

void ststoga(int stog[], int vrh)
{	int i;
	printf("\nTrenutno stanje na stogu:");
	for(i=0;i<=vrh;i++)
		if(stog[i]==75) printf(" K");
		else printf(" %d",stog[i]);
}

int main()
{	FILE *f;
	char polje[40];
	int stog[MAXSTOG], vrh=-1, stog2[MAXSTOG], vrh2=-1, razdio=0;
	int st, i, j, znak, x, nemsta, zstog, n, niz;
	int automat [89][6]={
{0, 0, \\'K\\', 0,  0, \\'K\\'},
{0, 1, \\'K\\', 3, \\'E\\' },
{0, 2, \\'K\\', 3, \\'E\\' },
{0, 3, \\'K\\', 3, \\'E\\' },
{0, 4, \\'K\\', 3, \\'E\\' },
{0, 5, \\'K\\', 3, \\'E\\' },
{0, 6, \\'K\\', 3, \\'E\\' },
{0, 7, \\'K\\', 3, \\'E\\' },
{0, 8, \\'K\\', 3, \\'E\\' },
{0, 9, \\'K\\', 3, \\'E\\' },

{0, 0, 0, 1, \\'E\\'  },
{0, 0, 0, 0,  0, 0},
{0, 1, 0, 0,  1, 0},
{0, 2, 0, 0,  0   },
{0, 3, 0, 0,  3, 0},
{0, 4, 0, 0,  0   },
{0, 5, 0, 0,  0   },
{0, 6, 0, 0,  0   },
{0, 7, 0, 0,  0   },
{0, 8, 0, 0,  8, 0},
{0, 9, 0, 0,  0   },

{0, 0, 1, 0,  0, 1},
{0, 1, 1, 1, \\'E\\'  },
{0, 1, 1, 0,  1, 1},
{0, 2, 1, 0,  1   },
{0, 3, 1, 0,  3, 1},
{0, 4, 1, 0,  1   },
{0, 5, 1, 0,  1   },
{0, 6, 1, 0,  1   },
{0, 7, 1, 0,  1   },
{0, 8, 1, 0,  8, 1},
{0, 9, 1, 0,  1   },

{0, 0, 3, 0,  0, 3},
{0, 1, 3, 0,  1, 3},
{0, 2, 3, 0,  3   },
{0, 3, 3, 1, \\'E\\'  },
{0, 3, 3, 0,  3, 3},
{0, 4, 3, 0,  3   },
{0, 5, 3, 0,  3   },
{0, 6, 3, 0,  3   },
{0, 7, 3, 0,  3   },
{0, 8, 3, 0,  8, 3},
{0, 9, 3, 0,  3   },

{0, 0, 8, 0,  0, 8},
{0, 1, 8, 0,  1, 8},
{0, 2, 8, 0,  8   },
{0, 3, 8, 0,  3, 8},
{0, 4, 8, 0,  8   },
{0, 5, 8, 0,  8   },
{0, 6, 8, 0,  8   },
{0, 7, 8, 0,  8   },
{0, 8, 8, 1, \\'E\\'  },
{0, 8, 8, 0,  8, 8},
{0, 9, 8, 0,  8   },

{1, 0, 0, 1,\\'E\\'},
{1, 2, 0, 1, 0 },
{1, 4, 0, 1, 0 },
{1, 5, 0, 1, 0 },
{1, 6, 0, 1, 0 },
{1, 7, 0, 1, 0 },
{1, 9, 0, 1, 0 },

{1, 1, 1, 1,\\'E\\'},
{1, 2, 1, 1, 1 },
{1, 4, 1, 1, 1 },
{1, 5, 1, 1, 1 },
{1, 6, 1, 1, 1 },
{1, 7, 1, 1, 1 },
{1, 9, 1, 1, 1 },

{1, 3, 3, 1,\\'E\\'},
{1, 2, 3, 1, 3 },
{1, 4, 3, 1, 3 },
{1, 5, 3, 1, 3 },
{1, 6, 3, 1, 3 },
{1, 7, 3, 1, 3 },
{1, 9, 3, 1, 3 },

{1, 8, 8, 1,\\'E\\'},
{1, 2, 8, 1, 8 },
{1, 4, 8, 1, 8 },
{1, 5, 8, 1, 8 },
{1, 6, 8, 1, 8 },
{1, 7, 8, 1, 8 },
{1, 9, 8, 1, 8 },

{1, 2, \\'K\\', 1,\\'K\\'},
{1, 4, \\'K\\', 1,\\'K\\'},
{1, 5, \\'K\\', 1,\\'K\\'},
{1, 6, \\'K\\', 1,\\'K\\'},
{1, 7, \\'K\\', 1,\\'K\\'},
{1, 9, \\'K\\', 1,\\'K\\'},

{1, \\'E\\', \\'K\\', 2,\\'E\\'}
						};


	if ((f=fopen ("F:\\file.txt","r")) == NULL)
	{	printf ("Datoteka nije dobro dohvacena!!\n");
		exit(1);
	} printf("%c",automat[83][1]);

	while ((fscanf (f, "%s", &polje))!=EOF)
	{	i=0;
		st=0;
		niz=0;
		vrh=-1;
		printf ("Primljeni niz: %s\n",polje);
		zstog=\\'K\\';
		stavi(stog, &vrh, zstog);
		n=(int) strlen (polje);
		while (i<=n+1)
		{	if (st==0)
			{	znak=(int)polje[i]-48;
				uznak(znak);
				ststoga(stog, vrh);
				skini(stog, &vrh, &zstog);
				sstog(zstog);
				if(znak==-48) st=3;
				nemsta=0;
				for(x=0; x<54; x++)
				{	if(automat[x][0]==st && automat[x][1]==znak && automat[x][2]==zstog)
					{	if(automat[x][4]==\\'E\\' && automat[x+1][4]!=\\'E\\' && razdio==0)
						{	stavi(stog, &vrh, zstog);
							for(j=0;j<=vrh;j++)
								stog2[j]=stog[j];
							vrh2=vrh;
							j=i;
							razdio++;
							skini(stog, &vrh, &zstog);
						}
						if(razdio!=2)
						{	printf("\nStaro stanje:%d",st);
							st = automat[x][3];
							printf("\nNovo stanje:%d",st);
													
							if (st==0)
							{	zstog=automat[x][2];
								stavi(stog, &vrh, zstog);
								nstog(zstog,1);
								
								if(automat[x][1]==0 || automat[x][1]==1 || automat[x][1]==3 || automat[x][1]==8)
								{	zstog=automat[x][1];
									stavi(stog, &vrh, zstog);
									nstog(zstog,2);
								}
							}
							ststoga(stog, vrh);
							nemsta=1;
							break;
						}
						else razdio=0;
					}	

				}
				if (nemsta==0)
					st=3;
				i++;
				scanf("\n");
			}
			else if (st==1)
			{	znak=(int)polje[i]-48;
				uznak(znak);
				ststoga(stog, vrh);
				skini(stog, &vrh, &zstog);
				sstog(zstog);
				if(i==n && zstog==75)
				{	printf("\nStaro stanje:%d",st);
					st=2;
					printf("\nNovo stanje:%d",st);
					printf("\nPRIHVACA se trenutni niz");
					niz=1;
				}
				i++;
				nemsta=0;

				for(x=54; x<90; x++)
				{	if(automat[x][0]==st && automat[x][1]==znak && automat[x][2]==zstog)
					{	printf("\nStaro stanje:%d",st);
						printf("\nNovo stanje:%d",st);
						if(automat[x][1]!=0 && automat[x][1]!=1 && automat[x][1]!=3 && automat[x][1]!=8)
						{	stavi(stog, &vrh, zstog);
							nstog(zstog,1);
						}
						nemsta=1;
						break;
					}
				}
				if (nemsta==0)
				{	if(razdio==1)
					{	if(st!=2)printf ("\nNE PRIHVACA se trenutni niz\n");
						for(i=0;i<=vrh2;i++)		
							stog[i]=stog2[i];
						vrh=vrh2;
						st=0;
						i=j;
						razdio=2;
					}
					else 
					{	printf("\nStaro stanje:%d",st);
						st=3;
						printf("\nNovo stanje:%d",st);
						ststoga(stog, vrh);
						break;
					}
				}
				scanf("\n"); 
			}
			else if (st==3)
			{	printf ("\nNE PRIHVACA se trenutni niz\n");
				break;
			}
		}
		if (niz==1)
			printf ("\nPRIHVACA se niz");
		else if (niz==0)
			printf ("\nNE PRIHVACA se niz");
	}
	return 0;
}