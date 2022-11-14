#include <stdio.h>
int main(void) {
	float a,b,c,m,M;
	printf("Ucitajte tri realna broja");
	scanf("%f %f %f", &a, &b, &c);
	m=a;
	M=a;
	if (b>M)
		M=b;
	if (b<m)
		m=b;
	if (c>M)
		M=c;
	if (c<m)
		m=c;
	printf("Minimum: %.2f ; Maksimum: %.2f", m, M);
	return 0;
}
	
	