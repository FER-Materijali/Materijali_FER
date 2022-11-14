#include <stdio.h>
int arr[101];
int main(void)
{
	int a;
	int i;
	int max1=-1;
	int max2=-1;
	int cnt=0;
	for(cnt=0;;++cnt)
	{
		scanf("%d",&a);
		if((a<0 || a>100) && cnt<2)
		{
		   printf("Nije uneseno dovoljno brojeva iz trazenog intervala.\n");
		   return 0;
	    }
	    else if(a<0 || a>100)
		{
		   break;
	    }
	    arr[a]++;
	}
	for(i=100;i>=0;--i)
	{
		if(arr[i]>0)
		{
			if(arr[i]>1)
			{
				/* Situacija kada imamo dva najveca ista broj. npr. 15 i 15*/
				if(max1==-1)max1=i;
				if(max2==-1)max2=i;
				break;
			}
			else
			{
				if(max1!=-1 && max2==-1)max2=i;/* Ako smo nasli vec prvog najveceg onda cemo ovog postaviti na drugo mjesto*/
				else if(max1==-1)max1=i;
				
			}
		}
	}
	printf("Ostatak pri dijeljenju %d sa %d je %d.\n",max1,max2,max1%max2);
	return 0;
}
