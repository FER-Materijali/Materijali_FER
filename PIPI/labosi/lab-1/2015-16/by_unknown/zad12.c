#include <stdio.h>
int main(void) {
	int a,b,c;
	printf("Unesite 2 cijela broja,a zatim operaciju\n");
	scanf("%d %d", &a, &b);
	printf("Operacija 1: zbrajanje, Operacija 2: oduzimanje\n");
	scanf("%d", &c);
	if (c==1)
		printf("%d + %d = %d", a, b, a+b);
	if (c==2) {
		if (a>=b)
			printf("%d - %d = %d", a, b, a-b);
		else
			printf("%d - %d = %d", b, a, b-a);		
	}
	return 0;
}