#include <stdio.h>
int main(void)
{
	int i;
	int a;
	int zbroj=0;
	int arr[20];
	do
	{
		scanf("%d",&a);
	}while(!(a>=1 && a<=20));
	for(i=0;i<a;++i)scanf("%d",&arr[i]);
	for(i=0;i<a;++i)
	{
		zbroj+=arr[i]>=-10 && arr[i]<=10?arr[i]:0;
	}
	printf("Zbroj vrijednosti promijenjenih elemenata: %d\n",zbroj);
	return 0;
}
