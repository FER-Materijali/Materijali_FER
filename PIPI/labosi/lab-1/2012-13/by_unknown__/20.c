#include<stdio.h>
int main()
{
				int n,i,a[20];
				do
				{
						scanf("%d",&n);
						}while(!(n>=1)&&(n<=20));
						for(i=0;i<n;i++)
						{
						scanf("%d",&a[i]);
						if(a[i]>=-1 && a[i]<=22)
						a[i]=0;
						}
						for(i=0;i<n;i++)
						printf("%d ",a[i]);
						return 0;
}