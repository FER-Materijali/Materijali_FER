#include<stdio.h>
#include<string.h>
int main()
{
				char niz[21];
				int i,j=0,k=0;
				gets(niz);
				for(i=0;i<strlen(niz);i++)
				if(isalpha(niz[i]))
				{j=1;break;}
				
				if(strlen(niz)>=8)
				k=1;
				
				if(k&&j)
				printf("niz zadovoljava uvjete");
				else if(k==0 && j==0)
				printf("niz je prekratak\nnema slova u nizu");
				else if(k==1 && j==0)
				printf("niz je dovoljno dug\nnema slova u nizu");
				else if(k==0 && j==1)
				printf("niz je prekratak\nima slova u nizu");
				
				return 0;
}