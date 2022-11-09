#include <stdio.h>
#include <malloc.h>


double pi(int n){
	double ostatak = n%2? 1.f : -1.f;
	if (n==1) return (double)4;
	return (double)4/(2*n-1)*ostatak+pi(n-1);
}

int main(void){
	int n, i;
	double  *p;
	printf("Unesite broj elemenata > \n");
	scanf("%d", &n);
	p = malloc(n*sizeof(double));
	printf("\nPolje:\n");
	for(i=0;i<n;i++){
		*(p+i)=pi(i+1);
		printf("%f ", *(p+i));
	}
	return 0;
}