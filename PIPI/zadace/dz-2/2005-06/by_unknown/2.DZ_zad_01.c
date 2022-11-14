#include <stdio.h>
#include <math.h>
#define MAX 20


int main (){
	int n,x, znam=0, zbroj=0, lijeva_p=0, desna_p=0;
		
	printf("Unesi broj n: ");
	scanf("%d", &n);
	
	x=n;
	do{
		x/=10;
		znam++;
	}while(x>0);

	lijeva_p = (int)(n*pow(10,-znam/2));

	desna_p = n - lijeva_p*pow(10,znam/2);

	zbroj=lijeva_p + desna_p;
    	
	printf("\n\n");

	printf("Zbroj lijeve i desne polovice broja %d iznosi: %d", n, zbroj);
	
	printf("\n\n");
	return 0;
}

/*
#include <stdio.h>
#include <math.h>
#define MAX 20

int zbroj(int n){	
	int duljina = (int) log10(n) + 1;
	return n / (int) pow(10,duljina/2) + n % (int) pow(10,duljina/2);	
}

int main (){
	int n,x;
		
	printf("Unesi broj n: ");
	scanf("%d", &n);
	
	printf("\n\n");
	x=zbroj(n);

	printf("Zbroj lijeve i desne polovice broja %d iznosi: %d", n, x);
	
	printf("\n\n");
	return 0;
}

*/
