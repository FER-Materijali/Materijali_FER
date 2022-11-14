#include <stdio.h>
int main(void)
{
	char q[30+1];
	int i=0;
	int len=0;
	gets(q);
	while(q[len]!='\0')++len;
	for(i=0;i<len;++i)
	{
	    switch(q[i])
	    {
	    	case('a'):
	    		q[i]='9';
	    		break;
	    	case('e'):
	    		q[i]='8';
	    		break;
	    	case('i'):
	    		q[i]='7';
		}
	}
	printf("%s",q);
	return 0;
}
