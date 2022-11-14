#include<stdio.h>
int main()
{
					int n,a[101]={0},i,brojac=0;
					do
					{
							scanf("%d",&n);
							brojac++;
							if(n<-30 || n>30)
							{printf("nedozvoljeno podrucje");return 0;}
							a[n]++;
							for(i=0;i<101;i++)
							if(a[i]==3)
							{printf("ucitan je bar 3 puta broj %d",i);return 0;}
							}while(1367);
}