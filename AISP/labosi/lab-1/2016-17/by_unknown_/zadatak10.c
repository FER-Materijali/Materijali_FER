#include <stdio.h>

double f(double z, int k){
	if (k == 0) return z;
	return (-1)*z*z/((2*k+1)*(2*k))*f(z, k-1);
}

int main(void){
	double z = 0.5;
	int k;
	do {
		printf("Unesite broj k! (za izlaz unijeti -1) > ");
		scanf("%d", &k);
		if (k==-1) return 0;
		printf("Rezultat: %0.10f\n", f(z, k));
	}while(1);
	return 0;
}