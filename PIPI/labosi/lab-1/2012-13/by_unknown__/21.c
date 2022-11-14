#include<stdio.h>
int main()
{
				int n,i,a[20],sum=0;
				do
				{
						scanf("%d",&n);
						}while(!(n>=1)&&(n<=20));
						for(i=0;i<n;i++)
						{
						scanf("%d",&a[i]);
						if(a[i]>=-10 && a[i]<=10)
						a[i]=0;
						sum+=a[i];
						}
						printf("%d ",sum);
						return 0;
}