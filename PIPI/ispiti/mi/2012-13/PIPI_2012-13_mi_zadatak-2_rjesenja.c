#include <stdio.h>
#define MAX 50

int main (void){
	int suma, n, broj1, i, broj2, polje[MAX*2], max;
	scanf("%d", &n);
	max=0;
	for(i=0; i<n; ++i){
		scanf("%d %d", &broj1, &broj2);
		polje[i*2]=broj1;
		polje[i*2+1]=broj2;
		if(i==0)
		    max=broj1+broj2;
		else if(max<broj1+broj2)
			max=broj1+broj2;
	}
	for(i=0; i<n; ++i)
		if(max==polje[i*2]+polje[i*2+1])
			printf("(%d, %d)\n", polje[i*2], polje[i*2+1]);
	return 0;
}