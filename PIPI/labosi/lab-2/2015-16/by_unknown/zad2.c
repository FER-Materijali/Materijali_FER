#include <stdio.h>
int main(void)
{
	char q[60+1];
	int len=0;
	int br=0;
	int i=0;
	gets(q);
	while(q[br]!='\0')++br;
	if(br<10)
	{
		printf("Prekratak niz\n");
		return 0;
	}
	for(i=0;i<br;i+=2)
	{
		if(q[i]>='a' && q[i]<='z')
		{
		  printf("%c\n",q[i]);
	    }
	
	}
	return 0;
}
