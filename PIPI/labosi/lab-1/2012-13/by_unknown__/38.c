#include<stdio.h>
int main()
{
			int n,a[10]={0},i,max,k=0;
			do
			{
						scanf("%d",&n);
						}while(n<100 || n>999);
						int t=n;
						k=(n%10)*10*10 + ((n/10)%10)*10 + (n/100)%10;
						
						if(n<k)
						printf("%d < %d ",n,k);
						if(n>k)
						printf("%d > %d ",n,k);
						if(n==k)
						printf("%d = %d ",n,k);
						
						return 0;
						}				
						