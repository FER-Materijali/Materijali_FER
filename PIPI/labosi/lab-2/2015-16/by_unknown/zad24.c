#include <stdio.h>
int main(void)
{
	char q[5+1];
	int i;
	int len=0;
	int cnt=0;
	gets(q);
	while(q[len]!='\0')++len;
	for(i=0;i<len;++i)
	{
		if(!(q[i]>='0' && q[i]<='7'))
		{
			printf("Ucitani niz nije ispravno zadan.\n");
			return 0;
		}
	}
	for(i=0;i<len;++i) 
	  cnt=q[i]=='4'?cnt+1:cnt;
	printf("Znamenka 4 se u ucitanom broju pojavljuje %d puta.\n",cnt);
	return 0;
}
