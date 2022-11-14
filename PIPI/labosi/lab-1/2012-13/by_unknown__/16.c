#include<stdio.h>
int main()
{
			int n,i;
			double sum=0;
			
			do
			{
					scanf("%d",&n);
					}while (!(n>=1 && n<=1000));
					
					for(i=1;i<=n;i++)
					sum+=1./((2*i-1)*(2*i+1));
					
					printf("%lf %lf",sum, 0.5-sum);
					
					return 0;
}