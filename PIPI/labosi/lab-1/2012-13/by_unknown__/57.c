#include<stdio.h>
#include<string.h>
#define FOREVER 1
int main()
{
				char a[31];
				int i;
				gets(a);
				for(i=0;i<strlen(a);i++)
				if(!(isdigit(a[i]) || isalpha(a[i])))
				{printf("niz nije dobar");return 0;}
				puts(a);
				for(i=0;i<strlen(a);i++)
				switch (a[i])
				{	
					case '0':a[i]='A';break;
					case '1':a[i]='E';break;
					case '2':a[i]='I';break;
					case '3':a[i]='O';break;
					case '4':a[i]='U';break;
					default : ;
					}
				puts(a);
				return 0;
}
		
		 
		 
		 