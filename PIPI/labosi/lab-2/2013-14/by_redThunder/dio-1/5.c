#include <stdio.h>
#include <math.h>
#define PI 3.141593

int main( void ){
	int i,predznak=1,n;
	double sol=0.;
	do{
		scanf("%d",&n);
	}while(n<1 || n>1000);
	for(i=1; i<=n; i++){
		sol += 4./(2*i-1)*predznak;
		predznak *= -1;
	}
	printf("pi = %.6lf\ngreska = %.6lf\n",sol,fabs(sol-PI));
	return 0;
}