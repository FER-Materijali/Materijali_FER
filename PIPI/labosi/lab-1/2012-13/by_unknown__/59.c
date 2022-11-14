#include<stdio.h>
#include<string.h>
#define FOREVER 1
int main()
{
				char a[101],b[25]={0};
				gets(a);
				int i;
				for(i=0;i<strlen(a);i++)
				if(isupper(a[i]))
				b[a[i]-65]++;
				else
				if(islower(a[i]))
				b[a[i]-97]++;
				int max=b[0],k=0;
				for(i=0;i<25;i++)
				if(b[i]>max)
				{max=b[i];k=i;}
				
				printf("najvise se ponovilo slovo %c %c",k+65,k+97);
				return 0;
}
		 
		 
		 