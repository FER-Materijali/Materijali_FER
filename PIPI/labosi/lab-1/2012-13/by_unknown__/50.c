#include<stdio.h>
#include<string.h>
int main()
{
				int n,i,sum=0,k=0;
				scanf("%d",&n);
				if(n<0 || n>100)
				{printf("NE VALJA!!!!");return 0;}
				else if(n<50)
				{sum+=n;}
				do
				{		
						scanf("%d",&n);
						if(n<1 || n>100)
						{printf("zbroj unesenih brojeva manjih od 50 je %d",sum);k=1;}
						else if(n<50)
						sum+=n;
						}while(!k);
						return 0;
				}
				 
				
				