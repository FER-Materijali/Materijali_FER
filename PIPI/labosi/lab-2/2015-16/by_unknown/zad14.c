#include <stdio.h>
int arr[30+1]; /* malo za promjenu, ovako je sve na nuli*/
int main(void)
{
	int a,i;
	int broji=1;
	while(1)
	{
		do
		{
		   scanf("%d",&a);
		}while(a<1 || a>30);
		if(arr[a]>0)break;
		arr[a]=broji;
		++broji;
	}
	printf("Broj %d bio je %d. ucitani broj.\n",a,arr[a]);
	printf("Ukupno ucitanih brojeva %d\n",broji);
	return 0;
}
