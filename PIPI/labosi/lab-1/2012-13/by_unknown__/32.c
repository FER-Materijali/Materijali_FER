#include<stdio.h>
#include<string.h>
int main()
{
							char a[31],b[31];
							int i;
							gets(a);
							gets(b);
							for(i=0;i<strlen(a) && i<strlen(b);i+=2)
							a[i]=b[i];
							
							puts(a);
							
							return 0;
}
							
							