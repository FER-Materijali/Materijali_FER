#include <stdio.h>
int main(void)
{
	int i;
	int a;
	int arr[30];
	do
	{
		scanf("%d",&a);
	}while(!(a>=1 && a<=30));
	for(i=0;i<a;++i)scanf("%d",&arr[i]);
	for(i=0;i<a;++i)
	{
		arr[i]=arr[i]>=-1 && arr[i]<=22?0:arr[i];
	}
	printf("Promijenjeno polje: ");
	for(i=0;i<a;++i)printf("%d ",arr[i]);
	return 0;
}
