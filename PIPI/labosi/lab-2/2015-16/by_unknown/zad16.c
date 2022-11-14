#include <stdio.h>
int main(void)
{
	int pos=-1;
	int len=0;
	char t;
	char q[21];
	gets(q);
	while(q[len]!='\0')
	{
		if(q[len]>='a' && q[len]<='z' && pos==-1)pos=len;
		++len;
	}
	t=q[pos];
	q[pos]=q[len-1];
	q[len-1]=t;
	printf("%s",q);
	return 0;
}
