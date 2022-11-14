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
					case 'a':a[i]='9';break;
					case 'e':a[i]='8';break;
					case 'i':a[i]='7';break;
					case 'o':a[i]='6';break;
					case 'u':a[i]='5';break;
					default : ;
					}
				puts(a);
				return 0;
}
		
		 
		 
		 