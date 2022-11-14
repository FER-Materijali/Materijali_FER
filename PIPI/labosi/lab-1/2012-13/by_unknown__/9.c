#include<stdio.h>
int main()
{
				int n,a[20],i;
				do
				{		
						printf("unesite n \2: ");
						scanf("%d",&n);
						}while(n<1 || n>20);
						
						for(i=0;i<n;i++)
						scanf("%d",&a[i]);
						
						for(i=0;i<n;i++)
						if(a[i]>9 && a[i]<21)
						printf("na %d. poziciji je clan: %d\n",i,a[i]);
						
						return 0;
}
						
						