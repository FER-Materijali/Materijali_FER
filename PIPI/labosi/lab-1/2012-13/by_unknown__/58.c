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
					case '5':a[i]='a';break;
					case '6':a[i]='e';break;
					case '7':a[i]='i';break;
					case '8':a[i]='o';break;
					case '9':a[i]='u';break;
					default : ;
					}
				puts(a);
				return 0;
}
		
		 
		 
		 