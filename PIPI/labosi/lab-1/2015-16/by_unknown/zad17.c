#include <stdio.h>
int main(void) {
	float c;
	float p;
	printf("Unesite cijenu,a zatim postotak snizenja");
	scanf("%f %f", &c, &p);
	if (c<0) 
		printf("Cijena mora biti pozitivan broj\n");
	if (p<0)
		printf("Postotak mora biti prirodan broj");
	if (p>0 && c>=0) {
		printf("Cijena %.2f umanjena za %.0f posto iznosi %.2f", c, p, c*(1-(p/100)));
	}
	return 0;
}