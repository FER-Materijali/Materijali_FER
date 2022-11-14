#include<stdio.h>
#include<string.h>
int main()
{
				char niz[11];
				int i,br=0;
				gets(niz);
				for(i=0;i<strlen(niz);i++)
				if(!(isdigit(niz[i]) && niz[i]<56))
				{printf("niz je neispravno zadan");return 0;}
								
				printf("%c %c",niz[0],niz[strlen(niz)-1]);
				return 0;
}
				 
				
				