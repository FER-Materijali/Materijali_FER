#include <stdio.h>
#include <math.h>
#define POLA 0.5

int main( void ){
	int i,n;
	double sol=0.;
	do{
		scanf("%d",&n);
	}while(n<1 || n>1000);
	for(i=1; i<=n; i++){
		sol += 1./((2*i-1)*(2*i+1));
	}
	printf("pi = %.6lf\ngreska = %.6lf\n",sol,fabs(sol-POLA));
	return 0;
}