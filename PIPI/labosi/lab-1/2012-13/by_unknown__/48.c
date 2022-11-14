#include<stdio.h>
#include<string.h>
int main()
{
				int n,i,min=100,k=0;
				scanf("%d",&n);
				if(n<0 || n>100)
				{printf("NE VALJA!!!!");return 0;}
				else if(!(n%4))
				min=n;
				do
				{		
						scanf("%d",&n);
						if(n<1 || n>100)
						{printf("najmanji uneseni broj djeljiv s 4 je %d",min);k=1;}
						else if(!(n%4) && n<min)
						min=n;
						}while(!k);
						return 0;
				}
				 
				
				