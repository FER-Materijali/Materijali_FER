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
					sum+=1./(i*(i+2));
					
					printf("%50.14lf %25.14lf",sum, 0.75-sum);
					
					return 0;
}