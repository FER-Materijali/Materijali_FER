#include <stdio.h>
int main(void)
{
	int arr[60+1];
	int a,i;
	int cnt=0;
	for(i=0;i<=60;++i)arr[i]=0;
	scanf("%d",&a);
	while(1)
	{
		if(a<-30 || a>30)
		{
			printf("Krivi raspon brojeva.\n");
			return 0;
		}
		arr[a+30]++;
		if(arr[a+30]>=3)break;
		scanf("%d",&a);
	}
	for(i=0;i<=60;++i)
	{
		cnt+=arr[i];
	}
	printf("Ukupno je ucitano %d brojeva.\n",cnt);
	return 0;
}
