#include<stdio.h>
#include<string.h>
int main()
{
				char niz[21];
				int i,j=0,k=0;
				gets(niz);
				for(i=0;i<strlen(niz);i++)
				{
				if(islower(niz[i]))
				j++;
				if(isdigit(niz[i]))
				k++;
				}			
				
				if(k>=2 && j>=7)
				printf("niz zadovoljava uvjete");
				else 
				printf("niz ne zadovoljava uvjete");
								
				return 0;
}