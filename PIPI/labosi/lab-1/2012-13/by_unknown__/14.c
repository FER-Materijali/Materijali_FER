#include<stdio.h>
int main()
{		
					int n,i;
					double sum=0;
					do
					{
						scanf("%d",&n);
						}while(n<1 || n>1000);
						
						for(i=1;i<=n;i++)
						sum+=1./(i*(i+1));
						
						printf("%lf %lf", sum,1-sum);
						return 0;
}
						
						
						