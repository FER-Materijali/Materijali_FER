#include<stdio.h>
#include<string.h>
#define min 10
int main()
{
		char s[61];
		int i;
		gets(s);
		
		if(strlen(s)<min)
		{printf("niz je prekratak");return 0;}
		
		for(i=0;i<strlen(s);i++)
		if(s[i]>64 && s[i]<91)

		printf("%c\n",s[i]);
		return 0;
}