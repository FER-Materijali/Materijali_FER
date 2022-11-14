#include <stdio.h>
int main(void)
{
	int i;
	int a;
	int arr[20];
	do
	{
		scanf("%d",&a);
	}while(!(a>=1 && a<=20));
	for(i=0;i<a;++i)scanf("%d",&arr[i]);
	for(i=0;i<a;++i)
	{
		if(arr[i]>=10 && arr[i]<=20)
		{
			printf("%2d. %d\n",i,arr[i]);
		}
	}
	return 0;
}
