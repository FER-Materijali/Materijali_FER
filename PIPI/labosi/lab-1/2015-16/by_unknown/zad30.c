#include <stdio.h>
int main(void) {
	int a,b,c,r1,r2;
	printf("Unesite 3 razlicita cijela broja\n");
	scanf("%d %d %d", &a, &b, &c);
	r1=b-a;
	r2=c-b;
	if ((a<b) && (b<c) && (r1==r2))
		printf("Brojevi %d, %d, %d su poredani uzlazno (razlika izmedu susjednih brojeva je %d)", a, b, c, r1);
	if ((a<b) && (b<c) && (r1!=r2))
		printf("Brojevi %d, %d, %d su poredani uzlazno (razlika izmedu susjednih brojeva nije jednaka)", a, b, c);
	if ((a>=b) || (a>=c) || (b>=c))
		printf("Brojevi %d, %d, %d nisu poredani uzlazno", a, b, c);
	return 0;
}