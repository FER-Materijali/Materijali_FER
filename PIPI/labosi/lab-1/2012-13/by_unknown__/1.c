#include<stdio.h>
int main()
{
		int x,i,j;
		
		scanf("%d",&x);
		if(x<5 || x>20)
		printf("Unijeli ste pogresan broj");
		else 
		{
		for(i=0;i<=x;i++)
		{
		printf("%d. red: ",i);
		for(j=0;j<=i;j++)
		printf("%d ",j);
		printf("\n");
		}
		}
		return 0;
}