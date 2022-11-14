#include <stdio.h>
int arr[10];
int main(void)
{
	int x;
	int i;
	int a;
	int suma=0;
	do
	{
		scanf("%d",&x);
		
	}while(x<1 || x>99999);
	a=x;
	while(x>0)
	{
		arr[x%10]++;
		x/=10;
	}
	for(i=0;i<10;++i)
	  suma+=arr[i]==1?i:0;
	printf("Broj %d - suma znamenaka koje se jednom pojavljuju %d\n",a,suma);
	return 0;
}
