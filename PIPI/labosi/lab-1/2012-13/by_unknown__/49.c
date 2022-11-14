#include<stdio.h>
#include<string.h>
int main()
{
				int n,i,min=100,k=0,max=0;
				scanf("%d",&n);
				if(n<0 || n>100)
				{printf("NE VALJA!!!!");return 0;}
				else if(!(n%4))
				{min=n;max=n;}
				do
				{		
						scanf("%d",&n);
						if(n<1 || n>100)
						{printf("zbroj najmanjeg i najveceg unesenog broja djeljivog s 4 je %d",min+max);k=1;}
						else if(!(n%4) && n<min)
						min=n;
						else if(!(n%4) && n>max)
						max=n;
						}while(!k);
						return 0;
				}
				 
				
				