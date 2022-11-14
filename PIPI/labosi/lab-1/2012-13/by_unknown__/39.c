#include<stdio.h>
int main()
{
			unsigned int n;
			int a[10]={0};
			scanf("%d",&n);
			int min=n%10;
			int t=n;
			while(n>0)
			{
				if((n%10<min && n%10) || !min)
				min=n%10;
				n/=10;
				}
				if(!(n%min))
				printf("broj %d je djeljiv s min. znamenkom %d",t,min);
				else
				printf("broj %d nije djeljiv s min. znamenkom %d",t,min);
				return 0;
}				