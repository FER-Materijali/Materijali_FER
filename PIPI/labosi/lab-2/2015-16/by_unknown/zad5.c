#include <stdio.h>
double fabs(double x){return x>=0?x:-x;}
int main(void)
{
	int i;
	int a;
	double pi=0;
	int predznak=1;
	do
	{
		scanf("%d",&a);
	}while(!(a>=1 && a<=1000));
	for(i=1;i<=a;++i)
	{
		pi+=(predznak)*(1.0/(2*i-1));
		predznak*=-1;
	}
	printf("%lf\n",pi*4);
	printf("%lf\n",fabs(pi*4-3.141593));
	return 0;
}
