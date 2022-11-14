#include <stdio.h>
int arr[40+1];
int main(void)
{
	int a,i;
	int broji=1;
	do
	{
		scanf("%d",&a);
		if(arr[a]==0)arr[a]=broji;
		++broji;
	}while(a>=1 && a<=40);
	for(i=0;i<=40;++i)
	  if(arr[i]>0)
	     printf("Broj %2d : %d\n",i,arr[i]);
	return 0;
}
