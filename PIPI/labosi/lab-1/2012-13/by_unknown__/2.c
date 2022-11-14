#include<stdio.h>
int main()
{
		int x,i;
		double j;
		scanf("%d",&x);
		if(x<5 || x>20)
		printf("Pogresno!!!!");
		else 
		{
			for(i=0;i<=x;i++)
			{
				printf("%d. red: ",i);
				for(j=0;j<=i;j++)
				printf("%.1f ",j/10);
				printf("\n");
				}
				}
		return 0;
}
			