#include <stdio.h>
int main(void)
{
	char q[10+1];
	int i;
	int len=0;
	int cnt=0;
	int max=0;
	gets(q);
	while(q[len]!='\0')++len;
	for(i=0;i<len;++i)
	{
		if(!((q[i]>='0' && q[i]<='9') || (q[i]>='A' && q[i]<='F') || (q[i]>='a' && q[i]<='f')))
		{
			printf("Ucitani niz nije ispravno zadan.\n");
			return 0;
		}
	}
	for(i=0;i<len;++i)
	{
		if(q[i]>='0' && q[i]<='7')cnt++;
	}
	printf("Broj unesenih oktalnih znamenki: %d\n",cnt);
	return 0;
}
