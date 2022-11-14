#include <stdio.h>
int main(void)
{
	int i;
	int a;
	int broj;
	int a_novo=0;
	int zbroj=0;
	int arr[20];
	do
	{
		scanf("%d",&a);
	}while(!(a>=1 && a<=15));
	for(i=0;i<a;++i)
	{
	  scanf("%d",&broj);
	  if(broj>=-10 && broj<=15)
	  {
	    arr[a_novo]=broj;
	    ++a_novo;
	  }
    }
	printf("Novo polje: ");
	for(i=0;i<a_novo;++i)
	 printf("%d ",arr[i]);
	return 0;
}
