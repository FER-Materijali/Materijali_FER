#include<stdio.h>
#include<string.h>
int main()
{
				char niz[11];
				int i,br=0;
				gets(niz);
				for(i=0;i<strlen(niz);i++)
				if(niz[i]!='1' && niz[i]!='0')
				{printf("niz je neispravno zadan");return 0;}
				
				if(niz[strlen(niz)-1]=='0')
				printf("posljednja je nula");
				else 
				printf("NIJE!!!!!");
				return 0;
}
				 
				
				