#include <stdio.h>
int main(void) {
	int a,b;
	float z;
	printf("Ucitajte 2 cijela broja razlicita od 0: \n");
	scanf("%d %d", &a, &b);
	if ((a+b)>0)
		printf("Aritmeticka sredina brojeva %d i %d: %.4f", a, b, (float)((a+b)/2));
	else{
		if (a<0)
			a=-a;
		if (b<0)
			b=-b;
		z=(float)((1.f/a)+(1.f/b));
		printf("Izracunata vrijednost: %.4f",z);
	}
	return 0;
}