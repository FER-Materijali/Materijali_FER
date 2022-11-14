#include<stdio.h>
int main()
{
					int n,a[101]={0},i,brojac=0,k=0;
					do
					{
							scanf("%d",&n);
							if(n>=1 && n<=30)
							a[n]++;
							
							}while(n>=1 && n<=30);
						for(i=1;i<41;i++)
						if(a[i]!=0)
						printf("broj %d: ucitan je %d puta\n",i,a[i]);
						return 0;
						
}