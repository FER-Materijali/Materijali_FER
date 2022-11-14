#include <stdio.h>
#define PI 3.14159
int main(void) {
	float x;
	printf("Ucitati duljinu kraka:");
	scanf("%f", &x);
	if (x<0)
		printf("Duljina stranice nije pozitivan broj");
	else {
		printf("Povrsina trokuta iznosi: %.2f\n", ((x*x)/2.f));
		printf("Povrsina kruga iznosi: %.2f\n",(x*x*PI));
	}
	return 0;
}
	