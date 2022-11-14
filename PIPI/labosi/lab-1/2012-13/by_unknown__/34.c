#include<stdio.h>
int main()
{
			int n,a[10]={0},i,max;
			do
			{
						scanf("%d",&n);
						}while(n<100 || n>10000);
						max=n%10;
						int t=n;
						while(n>0)
						{
							if(n%10>max)
							max=n%10;
							n/=10;
							}
						printf("U broju %d najveca je znamenka %d\n",t,max);
						return 0;
}
						