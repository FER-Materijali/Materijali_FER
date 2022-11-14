#include<stdio.h>
int main()
{
			int n,a[10]={0},i,max,k=0;
			do
			{
						scanf("%d",&n);
						}while(n<1 || n>10000);
						int t=n;
						while(n>0)
						{
						a[n%10]++;
						n/=10;
						}
						for(i=0;i<10;i++)
						if(a[i]==1)
						k++;
						printf("Broj %d - jednoputne znamenke: %d",t, k);
						return 0;

}
						