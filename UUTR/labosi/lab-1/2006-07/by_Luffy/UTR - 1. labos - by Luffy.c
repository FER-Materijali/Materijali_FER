#include<stdio.h>
#include <malloc.h>
int automat(char *polje,int i)
{   
    int j,st1=0,st2,automat[24][8]={ {0,1,2,3,23,23,23,1},
                              {1,23,23,23,4,5,6,0},
                              {2,23,23,23,7,8,9,0},
                              {3,23,23,23,10,11,12,0},
                              {4,23,13,14,23,23,23,1},
                              {5,23,23,15,23,23,23,1},
                              {6,23,16,14,23,23,23,1},
                              {7,17,23,18,23,23,23,1},
                              {8,23,23,23,23,23,23,1},
                              {9,19,23,20,23,23,23,1},
                              {10,21,13,23,23,23,23,1},
                              {11,22,23,23,23,23,23,1},
                              {12,21,16,23,23,23,23,1},
                              {13,23,23,23,23,23,9,0},
                              {14,23,23,23,23,11,23,0},
                              {15,23,23,23,10,23,12,0},
                              {16,23,23,23,7,23,23,0},
                              {17,23,23,23,23,23,6,0},
                              {18,23,23,23,23,23,12,0},
                              {19,23,23,23,4,23,23,0},
                              {20,23,23,23,10,23,23,0},
                              {21,23,23,23,23,5,23,0},
                              {22,23,23,23,4,23,6,0},
                              {23,23,23,23,23,23,23,0}}; 
	
	for(j=0;j<i;j++){ printf("Ulazni znak:%c\nTrenutacno stanje:q%d   ",polje[j],st1); st2=st1;
                       if (polje[j]==\\'A\\') st1=automat[st1][1];
				  else if (polje[j]==\\'B\\') st1=automat[st1][2];
                  else if (polje[j]==\\'C\\') st1=automat[st1][3];
				  else if (polje[j]==\\'1\\') st1=automat[st1][4];
				  else if (polje[j]==\\'2\\') st1=automat[st1][5];
				  else if (polje[j]==\\'3\\') st1=automat[st1][6];
                                  else st1=automat[23][1];
				  printf("\nPrijelaz: (q%d,%c)=q%d \nNovo stanje=q%d\n",st2,polje[j],st1,st1);
				  if( automat[st1][7]==1) printf("Dosadasnji niz:Prihvatljiv\n");
				  else printf("Dosadasnji niz:Neprihvatljiv\n");
				  printf("-----------------------------------------------------------------\n");}
              if( automat[st1][7]==1) return 1;
			  else return 0;
   
 }
void main(){
    FILE *dat;
	char *polje=NULL;
	char znak;
	int i=0;
	int flag = 0;
	dat=fopen("dka.txt","r");// Ili kako god se zove datoteka
	while (fscanf(dat,"%c",&znak)>0)
	{
	     if(znak!=(char)32)
		{
			if(znak!=\\'\n\\')
			{
				polje = (char *)realloc(polje,(i+1)*sizeof(char));
				polje[i]=znak;
				i++;
			}
		}
		else
		{
			polje=(char *)realloc(polje,(i+1)*sizeof(char));
			polje[i]=\\'\0\\';
			if(automat(polje,i)) printf("\nNiz \"%s\" je prihvatljiv!\n",polje);
			else printf("\nNiz \"%s\" nije prihvatljiv!\n",polje);
			free(polje);
			polje=NULL;
			i=0;
			flag = 1;
		}
	}
	if(!flag)
	{
		polje=(char *)realloc(polje,(i+1)*sizeof(char));
		polje[i]=\\'\0\\';
		if(automat(polje,i)) printf("\npolje \"%s\" je prihvatljiv!\n",polje);
		else printf("\nNiz \"%s\" nije prihvatljiv!\n",polje);
		free(polje);
		polje=NULL;
		i=0;
	} 
}