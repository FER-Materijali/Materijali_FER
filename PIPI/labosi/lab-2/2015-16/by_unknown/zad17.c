#include <stdio.h>
int min(x,y){return x>y?y:x;}
int main(void)
{
	char q[30+1];
	char w[30+1];
	int i=0;
	int cnt=0;
	int len=0,len2=0;
	gets(q);
	gets(w);
	while(q[len]!='\0')++len;
	while(w[len2]!='\0')++len2;
	for(i=1;i<min(len,len2);i+=2)
	{
		w[i]=q[i];
		++cnt;
	}
	printf("Promijenjeni niz: ");
	for(i=0;i<len;++i)
	  printf("%c",w[i]);
	printf("\nPromijenjeno znakova: %d\n",cnt);
	return 0;
}
