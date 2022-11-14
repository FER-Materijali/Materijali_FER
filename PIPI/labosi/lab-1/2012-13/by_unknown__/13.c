#include<stdio.h>
#include<math.h>
#define pi 3.141593
int main()
{		
			int n,i;
			double sum=0,pi1;
			do
			{
					scanf("%d",&n);
					}while(n<1 || n>1000);
					
					for(i=1;i<=n;i++)
					sum+=pow(-1,i+1)*1./(2*i-1);
					pi1=4*sum;
					printf("izracunali smo pi %lf s pogreskom %lf a najbolji pi je %.20lf", pi1, pi1-pi,4*atan(1)); 
					return 0;
}