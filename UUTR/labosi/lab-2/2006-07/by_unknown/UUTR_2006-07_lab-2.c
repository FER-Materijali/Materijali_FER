#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct potisniautomat {
	int aktivan;
	int stanje;
	char stog[30];
	int kaz;
	int prihvat;
};

char f(char ulazni_znak)
{
	switch (ulazni_znak)
	{
	case '0':
		return 'N';
	case '1':
		return 'A';
	case '2':
		return 'B';
	case '3':
		return 'C';
	case '4':
		return 'D';
	case '5':
		return 'E';
	case '6':
		return 'F';
	case '7':
		return 'G';
	case '8':
		return 'H';
	case '9':
		return 'I';
	}
}

typedef struct potisniautomat PA;

void init(PA *a, int *b, int stanje){
	a[*b].aktivan=1;
	a[*b].stanje=0;
	a[*b].kaz=0;
	a[*b].stog[a[*b].kaz]='K';
	a[*b].kaz++;
	a[*b].prihvat=0;
	*b=*b+1;
}

void delta(PA *a, int b, int st, char znak){
	a[b].stanje=st;
	if (st==0){
		a[b].stog[a[b].kaz]=znak;
		a[b].kaz++;
	} else {
		a[b].kaz--;
        a[b].stog[a[b].kaz]=znak;
    }
}

void prenesi(PA *a, int b, int c){
	unsigned int i;
	for(i=0; i<strlen(a[b].stog); i++) a[c].stog[i]=a[b].stog[i];
	a[c].kaz=a[b].kaz-1;
}

void zaustavi(PA *a, int b){
	a[b].aktivan=0;
}

void prihvat(PA *a, int b){
	if(a[b].stog[a[b].kaz-1]=='K') a[b].prihvat=1;
	else a[b].prihvat=0;
}

void ispis_stoga (char *s, int i){
	i=i-1;
	for (;i>=0;i--) printf("%c",s[i]);
}

int main(int argc, char *argv[]) 
{	
	FILE *dat;
	char s[100];
	PA aut[100];
	int i,j,k, s_stanje, n_stanje, j_b;
	i=j=k=0;
	
	init(aut, &j, 0);
	

  if((dat=fopen(argv[1], "r"))==NULL)
   {
     printf("Ne mogu otvoriti datoteku.");
     return 0;
   }
  

  while (fscanf(dat, "%c", &s[i])==1)
  {
      
	  if ((s[i]!='\n') && (s[i]!='\t') && (s[i]!=' ')) 
	  {
		  j_b=j;   
		  for(k=0; k<j_b;k++)
		  {
			  if (aut[k].aktivan) 
			  {
				  switch (s_stanje=aut[k].stanje)
					{
				  case 0:	if (f(s[i])==aut[k].stog[aut[k].kaz-1])	{printf("Nedeterminizam: d(q%d,%c,%c)={(q0, %c%c), (q1, eps)} \n",
								s_stanje ,s[i] ,aut[k].stog[aut[k].kaz-1], aut[k].stog[aut[k].kaz-1], aut[k].stog[aut[k].kaz-1]);
					  printf("                              PA%d       PA%d     \n", k+1,j+1);}
						printf("%d. Potisni Automat \n", k+1);
						printf("Znak koji se trenutno ucitava: %c \n", s[i]);
						printf ("Trenutno stanje: q%d \n", aut[k].stanje);
						printf ("Stanje stoga:"); ispis_stoga(aut[k].stog, aut[k].kaz); printf("\n");
						n_stanje=0;
						delta(aut, k, n_stanje, f(s[i]));
						printf("d(q%d, %c, %c)={(q%d, %c%c)}\n",s_stanje ,s[i] ,aut[k].stog[aut[k].kaz-2] ,aut[k].stanje, aut[k].stog[aut[k].kaz-1], aut[k].stog[aut[k].kaz-2]);
						printf("Novo stanje: q%d\n", aut[k].stanje);
						printf("Novo stanje stoga:"); ispis_stoga(aut[k].stog, aut[k].kaz); printf("\n");
						printf("Dosadasnji niz se NE PRIHVACA. \n \n");
						if (f(s[i])==aut[k].stog[aut[k].kaz-2]) {
							init(aut, &j, 1);
							prenesi(aut, k, j-1);
							s_stanje=aut[j-1].stanje;
							printf("%d. Potisni Automat \n", j);
							printf("Znak koji se trenutno ucitava: %c \n", s[i]);
							printf ("Trenutno stanje: q%d \n", aut[j-1].stanje);
							printf ("Stanje stoga:"); ispis_stoga(aut[j-1].stog, aut[j-1].kaz); printf("\n");
							n_stanje=1;
							delta(aut, j-1, n_stanje, '\0');
							prihvat(aut, j-1);
							printf("d(q%d, %c, %c)={(q%d, eps)}\n",s_stanje ,s[i] ,aut[j-1].stog[aut[j-1].kaz-1] ,aut[j-1].stanje);
							printf("Novo stanje: q%d\n", aut[j-1].stanje);
							printf("Novo stanje stoga:"); ispis_stoga(aut[j-1].stog, aut[j-1].kaz); printf("\n");
							if (aut[j-1].prihvat) printf("Dosadasnji niz se PRIHVACA. \n \n");
							else printf("Dosadasnji niz se NE PRIHVACA. \n \n");
							break;
						}
						break;

					case 1:	if (f(s[i])==aut[k].stog[aut[k].kaz-1]) 
						{
							printf("%d. Potisni Automat \n", k+1);
							printf("Znak koji se trenutno ucitava: %c \n", s[i]);
							printf("Trenutno stanje: q%d \n", aut[k].stanje);
							printf("Stanje stoga:"); ispis_stoga(aut[k].stog, aut[k].kaz); printf("\n");
							n_stanje=1;
							delta(aut, k, n_stanje, '\0');
							prihvat(aut, k);
							printf("d(q%d, %c, %c)={(q%d, eps)}\n",s_stanje ,s[i] ,aut[k].stog[aut[k].kaz-1] ,aut[k].stanje);
							printf("Novo stanje: q%d\n", aut[k].stanje);
							printf("Novo stanje stoga:"); ispis_stoga(aut[k].stog, aut[k].kaz); printf("\n");
							if (aut[k].prihvat) printf("Dosadasnji niz se PRIHVACA. \n \n");
							else printf("Dosadasnji niz se NE PRIHVACA. \n \n");
						} else 
						{
							zaustavi(aut, k);
							printf("%d. Potisni Automat \n", k+1);
							printf("Znak koji se trenutno ucitava: %c \n", s[i]);
							printf("Trenutno stanje: q%d \n", aut[k].stanje);
							printf("Stanje stoga:"); ispis_stoga(aut[k].stog, aut[k].kaz); printf("\n");
							printf("d(q%d, %c, %c)=prazan skup\n",aut[k].stanje ,s[i] ,aut[k].stog[aut[k].kaz-1]);
							printf("Potisni automat broj %d prestaje s radom jer nema mogucih prijelaza.\n", k+1);
							printf("\n");
						}
						break;

					}
			  }
		  }
		i++;
	  }else {
				j=0;
				s[i]='\0';
				i=0;
				init(aut, &j, 0);
				printf("Gotov je niz %s.\n", s);
				printf("Ucitava se novi niz.\n");
				printf("\n");
			}
  }
  s[i]='\0';	
  printf("Gotov je zadnji niz %s.\n", s);

  return 0;
}
