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
					case 'A':a[i]='0';break;
					case 'E':a[i]='1';break;
					case 'I':a[i]='2';break;
					case 'O':a[i]='3';break;
					case 'U':a[i]='4';break;
					default : ;
					}
				puts(a);
				return 0;
}
		
		 
		 
		 