#include <stdio.h>
#include <math.h>

int main(){
	int n, zz;
	long int broj;
	double f, rez;
	do{
		printf("Unesi broj koji ce se zaokruziti: ");
		scanf("%lf",&f);
		printf("Unesi n: ");
		scanf("%d", &n);
		
		broj = zz = (int)(f*pow(10,n+1));
		zz %=10;
		
		broj = (int)(broj*pow(10,-1));
		if(zz>5) broj++;

		rez = broj*pow(10,-n);
		printf("\n\nBroj %f zaokruzne na %d decimala iznosi: %f\n\n", f,n,rez);
	}while (f!=rez);
	return 0;
}