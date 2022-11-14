#include<stdio.h>
int main()
{
						int n,a[31][2]={0},i,br=-1;
						do
						{
						do
						{
								scanf("%d",&n);
								br++;
								}while(n<1 || n>30);
								if(a[n][0]==1)
								{printf("Broj %d je %d. procitani broj",n,a[n][1]);return 0;}
								a[n][0]++;
								a[n][1]=br;
								}while(1367);
}