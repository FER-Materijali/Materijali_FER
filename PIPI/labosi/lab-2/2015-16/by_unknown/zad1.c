#include <stdio.h>
int main(void)
{
	int a,b;
	int i;
	double j;
	scanf("%d",&a);
	if(a<5 || a>20)
	{
		printf("Neispravan broj.\n");
		return 0;
	}
	for(i=0;i<=a;++i)
	{
		int br=0;
		for(j=0;br<=i;j+=0.1,++br)
		 printf("%.1lf ",j);
		printf("\n");
	}
	return 0;
}
