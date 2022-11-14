#include <stdio.h>
int arr[101];
int main(void)
{
	int a;
	int i;
	int min=0;
	int max=0;
	scanf("%d",&a);
	if((a<0 || a>100))
	{
		printf("Nije unesen niti jedan broj iz trazenog intervala");
		return 0;
	}
	while(a>=0 && a<=100)
	{
		arr[a]=1;
		scanf("%d",&a);
	}
	for(i=4;i<=100;i+=4)
	   if(arr[i])
		{
			min=i;
			break;
		}
	for(i=100;i>=4;i-=4)
	   if(arr[i])
		{
			max=i;
			break;
		}
	printf("Zbroj najveceg (%d) i najmanjeg (%d) unsesenog broja djelivog s 4 je %d.\n",max,min,max+min);
	return 0;
}
