#include <stdio.h>
int main(void)
{
	char q[30+1];
	int len=0;
	int i=0;
	int broj_slova=0;
	int broj_znamenki=0;
	gets(q);
	while(q[len]!='\0')++len;
	for(i=0;i<len;++i)
	{
		if(q[i]>='0' && q[i]<='9')++broj_znamenki;
		if(q[i]>='a' && q[i]<='z')++broj_slova;
	}
	printf(broj_slova>=7 && broj_znamenki>=2?"Zadovoljava uvjete":"Ne zadovoljava uvjete");
	return 0;
}
