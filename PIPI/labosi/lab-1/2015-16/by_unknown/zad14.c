#include <stdio.h>
int main(void) {
	int m,n;
	printf("Ucitajte 2 cijela broja");
	scanf("%d %d", &m, &n);
	if ((n%10)==0)
		printf("Dijeljenje nije moguce");
	else {
		float f=((float)m/(n%10));
		printf("%d / %d = %.2f", m, n%10, f);
	}
	return 0;
}
	