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
	for(i=br-1;i>=0;--i)
	{
		if((q[i]>='A' && q[i]<='Z') || (q[i]>='0' && q[i]<='9'))
		{
		  printf("%c\n",q[i]);
	    }
	
	}
	return 0;
}
