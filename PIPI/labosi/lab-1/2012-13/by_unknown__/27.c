#include<stdio.h>
int main()
{
					int n,a[101]={0},i,brojac=0,k=0;
					do
					{
							scanf("%d",&n);
							a[n]++;
							for(i=0;i<41;i++)
							if(a[i]==4)
							k=1;
							}while(!k);
						for(i=1;i<41;i++)
						if(a[i]!=0)
						printf("broj %d: ucitan je %d puta\n",i,a[i]);
						return 0;
						
}