#include <stdio.h>
int arr[101];
int main(void)
{
	int a;
	int i;
	int cnt=0;
	scanf("%d",&a);
	if((a<0 || a>100))
	{
		printf("Nije unesen niti jedan broj iz trazenog intervala");
		return 0;
	}
	while(a>=0 && a<=100)
	{
		arr[a]++;
		scanf("%d",&a);
	}
	for(i=0;i<=49;++i)
	   cnt+=arr[i]*i;
	printf("Zbroj svih unesenih brojeva manjih od 50 je %d.\n",cnt);
	return 0;
}
