#include <stdio.h>
int main(void)
{
	int x;
	int i;
	int a;
	int broj=0;
	do
	{
		scanf("%d",&x);
		
	}while(x<100 || x>99999);
	a=x;
	while(x>0)
	{
		if(broj<(x%10))broj=x%10;
		x/=10;
	}
	printf("U broju %d najveca znamenka je: %d\n",a,broj);
	return 0;
}
