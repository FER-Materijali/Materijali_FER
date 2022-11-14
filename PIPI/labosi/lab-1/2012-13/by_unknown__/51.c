#include<stdio.h>
#include<string.h>
int main()
{
				int n,i,sum=0,k=0;
				scanf("%d",&n);
				if(n<0 || n>100)
				{printf("NE VALJA!!!!");return 0;}
				else if(!(n%17))
				{sum++;}
				do
				{		
						scanf("%d",&n);
						if(n<1 || n>100)
						{printf("ima %d brojeva djeljivih s 17",sum);k=1;}
						else if(!(n%17))
						sum++;
						}while(!k);
						return 0;
				}
				 
				
				