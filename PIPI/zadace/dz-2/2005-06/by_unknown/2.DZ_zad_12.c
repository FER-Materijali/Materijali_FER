#include <stdio.h>
#include <math.h>

int main(){
	int n, k=1,i, x=0;

	printf("Unesi n: ");
	scanf("%d",&n);

	do{
		if(x)k++;
		x = k*k;
	}while(x<n);

	printf("\n%d brojeva ciji je kvadrat manji od broja %d su:\n  ", k-1, n);
	for(i=1;i<k;++i) printf("%d  ", i);
	printf("\n\n\n");
	return 0;
}




