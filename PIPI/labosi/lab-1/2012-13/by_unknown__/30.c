#include<stdio.h>
#include<string.h>
int main()
{
					char niz[21],i,t,k=0;
					gets(niz);
					for(i=0;i<strlen(niz) && !k;i++)
					if(islower(niz[i]))
					{
					t=niz[strlen(niz)-1];
					niz[strlen(niz)-1]=niz[i];
					niz[i]=t;
					k=1;
					}
					puts(niz);
					return 0;
					}
					
