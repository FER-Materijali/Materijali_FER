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
						if(a[i]>=-20 && a[i]<=40)
						{a[i]=-100;
						sum++;}
						}
						printf("%d ",sum);
						return 0;
}