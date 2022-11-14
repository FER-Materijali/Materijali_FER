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
				else if(niz[i]=='0' && niz[i+1]=='0')
				br=1;
				
				if(br)
				printf("niz sadrzi dvije ili vise uzastopnih 0");
				else
				printf("niz ne sadrzi dvije ili vise uzastopnih 0");
				return 0;
}
				 
				
				