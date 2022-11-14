#include<stdio.h>
int main(void){
	int a, b;
	float a1, b1, sum;
	sum = 0;
	printf("Upisi dva cijela broja:");
	scanf("%d %d", &a, &b);
	if ((a+b)>0)
		printf("Aritmeticka sredina brojeva %d i %d je: %.4f", a, b, (a+b)/2.);
	else {
		a1 = 1./a;
		b1 = 1./b;
		sum = a1 + b1;
		printf("Izracunata vrijednost: ");
		if (sum<0)
			printf("%.4f", -sum);
		else
			printf("%.4f", sum);	
	}
	return 0;
}