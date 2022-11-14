#include <stdio.h>
int arr[10];
int main(void)
{
	int x;
	int i;
	int a;
	int prva=0;
	int broj=0;
	do
	{
		scanf("%d",&x);
		
	}while(x<1 || x>99999);
	a=x;
	while(x>0)
	{
		arr[x%10]++;
		prva=x%10;
		x/=10;
	}
	if(prva< (a%10))printf("Broj %4d: zadnja znamenka je veca od prve.\n",a);
	if(prva> (a%10))printf("Broj %4d: prva znamenka je veca od zadnje.\n",a);
	if(prva== (a%10))printf("Broj %4d: prva i zadnja znamenka su jednake.\n",a);
	return 0;
}
