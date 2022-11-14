#include<stdio.h>
int main()
{
		int x,i,j;
		scanf("%d",&x);
		if(x<5 || x>20)
		printf("pogresnoooo");
		else
		{
			for(i=0;i<=x;i++)
			{
				printf("%d. red: ", i);
					for(j=0;j<=i;j++)
						if(j==i)
						printf("%d ",j);
						else printf(" ");
				printf("\n");
			}
		}
		return 0;
}

