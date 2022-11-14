#include <stdio.h>
int main(void)
{
	char q[11];
	int len=0;
	int i;
	int max=0;
	int cnt=0;
	gets(q);
	while(q[len]!='\0')++len;
	for(i=0;i<len;++i)
	{
		if(q[i]!='0' && q[i]!='1')
		{
			printf("Ucitani niz nije ispravno zadan.\n");
			return 0;
		}
	}
	for(i=0;i<len;++i)
	{
		if(q[i]=='0')++cnt;
		else
		{
			if(max<cnt)max=cnt;
			cnt=0;
		}
	}
	if(max<cnt)max=cnt;
	printf(max>=2?"Uneseni binarni broj sadrzi dvije ili vise uzastopnih znamenki 0.":"Uneseni binarni broj ne sadrzi dvije ili vise uzastopnih znamenki 0.");
	return 0;
}
