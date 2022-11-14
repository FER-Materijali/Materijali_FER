#include<stdio.h>
int main()
{
			int n,a[10]={0},i;
			do
			{
						scanf("%d",&n);
						}while(n<100 || n>10000);
						
						while(n>0)
						{
							a[n%10]++;
							n/=10;
							}
						for(i=0;i<10;i++)
						if(a[i])
						printf("Znamenka %d se pojavila %d. puta\n",i,a[i]);
						return 0;
}
						