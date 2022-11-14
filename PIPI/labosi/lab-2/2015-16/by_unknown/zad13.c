#include <stdio.h>
int main(void)
{
	int arr[30+1];
	int a,i;
	for(i=0;i<=30;++i)arr[i]=0;
	scanf("%d",&a);
	while(1)
	{
		if(a<1 || a>30)
		{
			break;
		}
		arr[a]++;
		
		scanf("%d",&a);
	}
	for(i=1;i<=30;++i)
	{
		if(arr[i])
		{
			printf("broj %2d: %d\n",i,arr[i]);
		}
	}
	return 0;
}
