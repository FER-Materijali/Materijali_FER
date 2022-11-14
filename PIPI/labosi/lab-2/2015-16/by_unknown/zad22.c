#include <stdio.h>
int main(void)
{
	int x;
	int i;
	int a;
	int novi_broj=0;
	do
	{
		scanf("%d",&x);
		
	}while(x<100 || x>999);
	a=x;
	while(x>0)
	{
		novi_broj=novi_broj*10+x%10;
		x/=10;
	}
	if(novi_broj<a)printf("Broj %d je manji od ucitanog.\n",novi_broj);
	else if(novi_broj>a)printf("Broj %d je veci od ucitanog.\n",novi_broj);
	else if(novi_broj==a)printf("Broj %d je jednak od ucitanog.\n",novi_broj);
	return 0;
}
