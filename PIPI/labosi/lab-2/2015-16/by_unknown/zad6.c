#include <stdio.h>
double fabs(double x){return x>=0?x:-x;}
int main(void)
{
	int i;
	int a;
	double broj=0;
	do
	{
		scanf("%d",&a);
	}while(!(a>=1 && a<=1000));
	for(i=1;i<=a;++i)
	{
		broj+=(1.0/((2*i-1)*(2*i+1)));
	}
	printf("%lf\n",broj);
	printf("%lf\n",fabs(broj-0.5));
	return 0;
}
