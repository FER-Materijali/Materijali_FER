#include <stdio.h>
int main(void) {
	int a,b,c;
	printf("Ucitati 3 prirodna broja");
	scanf("%d %d %d", &a, &b, &c);
	if (b+c==a)
		printf("%d + %d = %d", b, c, a);
	if (a+c==b)
		printf("%d + %d = %d", a, c, b);
	if (a+b==c)
		printf("%d + %d = %d", a, b, c);
	if ((a+b!=c) && (a+c!=b) && (b+c!=a))
		printf("Niti jedan broj nije jedan zborju preostalih brojeva");
	return 0;
}