#include<stdio.h>
#include<string.h>
int main()
{
				char niz[10];
				int sum=0;
				gets(niz);
				if(!isxdigit(niz[0]))
				{printf("ne valja");return 0;}
				else if(niz[0]<56)
				sum++;
				do
				{
						gets(niz);
						if(!isxdigit(niz[0]))
						{printf("ima %d oktalnih znamenki",sum);return 0;}
						else if (niz[0]<56)
						sum++;
						}while(1367);
						return 0;
}
		
				
				