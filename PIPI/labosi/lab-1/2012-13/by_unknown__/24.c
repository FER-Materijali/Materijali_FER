#include<stdio.h>
int main()
{
					int n,a[101]={0},i;
					do
					{
							scanf("%d",&n);
							if(n<1 || n>100)
							{printf("nedozvoljeno podrucje");return 0;}
							a[n]++;
							for(i=0;i<101;i++)
							if(a[i]==5)
							{printf("broj %d je napisan 5 puta",i);return 0;}
							}while(n>=1 && n<=100);
}