#include<stdio.h>
#include<string.h>
int main()
{
				char niz[11],max=47;
				int i,br=0;
				gets(niz);
				for(i=0;i<strlen(niz);i++)
				if(!(isxdigit(niz[i])))
				{printf("niz je neispravno zadan");return 0;}
				else if(niz[i]>max)
				max=niz[i];
				
				printf("%c",max);
							
				return 0;
}
				 
				
				