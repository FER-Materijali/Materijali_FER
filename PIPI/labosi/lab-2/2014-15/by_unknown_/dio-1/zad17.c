#include<stdio.h>
int main(void){
	float cij;
	int pos;
	printf("Upisi cijenu proizvoda i postotak snizenja:");
	scanf("%f %d", &cij, &pos);
	if (cij<=0)
		printf("Cijena mora biti pozitivan broj");
	else if (pos<1)
		printf("Postotak snizenja mora biti prirodni broj");
	else 
		printf("Cijena %.2f umanjena za %d posto iznosi %.2f", cij, pos, cij-cij*(pos/100.));
	return 0;
}