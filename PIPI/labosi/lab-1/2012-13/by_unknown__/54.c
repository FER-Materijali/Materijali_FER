#include<stdio.h>
#include<string.h>
#define FOREVER 1
int main()
{
	     int i,n,min,max;
		 
		 scanf("%d",&n);
		 if(n<0 || n>100)
		 {printf("nema dovoljno brojeva iz intervala");return 0;}
		 else
		 {min=n; max=n;}
		 
		 scanf("%d",&n);
		 if(n<0 || n>100)
		 {printf("nema dovoljno brojeva iz intervala");return 0;}
		 else if(n>max)
		 {min=max;max=n;}
		 else if(n>min)
		 min=n;
		 
		 do
		 {
			scanf("%d",&n);
			if(n<0 || n>100)
			{printf("ostatak je %d %d %d",max%min, max, min);return 0;}
			else if(n>max)
			{min=max;max=n;}
			else if(n>min && n<max)
			min=n;
			}while(FOREVER);
			return 0;
		}
				
		 
		
		 
		 
		 