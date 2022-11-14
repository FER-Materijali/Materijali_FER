#include<stdio.h>
int main()
{
				int n,i,a[20],k=0,b[20];
				do
				{
						scanf("%d",&n);
						}while(!(n>=1)&&(n<=20));
						for(i=0;i<n;i++)
						{
						scanf("%d",&a[i]);
						if(a[i]>=-10 && a[i]<=15)
						{b[k]=a[i];k++;}
						}
						for(i=0;i<k;i++)
						printf("%d ",b[i]);
						return 0;
}