#include<stdio.h>
#include<string.h>
int main()
{
				char niz[11],min='8';
				int i,br=0;
				gets(niz);
				for(i=0;i<strlen(niz);i++)
				if(!(isdigit(niz[i]) && niz[i]<56))
				{printf("niz je neispravno zadan");return 0;}
				else if(niz[i]<min)
				min=niz[i];
				
				printf("%c",min);
							
				return 0;
}
				 
				
				