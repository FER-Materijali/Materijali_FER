#include <stdio.h>
int main(void) {
	int a, b, s1, s2;
	printf("Ucitajte 2 prirodna broja ");
	scanf("%d %d", &a, &b);
	s1=a/10+ a%10;
	s2=b/10+ b%10;
	if (s1==s2) {
		printf("Brojevi %d i %d imaju jednaku sumu znamenaka", a, b);
	}
	if (s1>s2) {
		printf("Broj %d ima vecu sumu znamenaka od %d", a, b);
	} 
	if (s2>s1) {
		printf("Broj %d ima vecu sumu znamenaka od %d", b, a);
	}
	return 0;
}