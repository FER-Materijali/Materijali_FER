#include<stdio.h>
int main()
{
					int n,a[101]={0},i,brojac=0;
					do
					{
							scanf("%d",&n);
							brojac++;
							if(n<1 || n>50)
							{printf("nedozvoljeno podrucje");return 0;}
							a[n]++;
							for(i=0;i<101;i++)
							if(a[i]==6)
							{printf("ucitano je %d brojeva",brojac);return 0;}
							}while(1367);
}