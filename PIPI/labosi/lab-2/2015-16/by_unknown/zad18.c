#include <stdio.h>
int arr[10];
int main(void)
{
	int x;
	int i;
	do
	{
		scanf("%d",&x);
		
	}while(x<100 || x>99999);
	while(x>0)
	{
		arr[x%10]++;
		x/=10;
	}
	for(i=0;i<10;++i)
	  if(arr[i]>0)
	    printf("znamenka %d: %d\n",i,arr[i]);
	return 0;
}
