#include <stdio.h>
#define PI 3.14159
int main(void) {
	float a,b,s1,s2;
	printf("Ucitati 2 realna broja koja predstavljaju opseg kruga i opseg kvadrata\n");
	scanf("%f %f", &a, &b);
	s1=(float)(a/(2.f*PI));
	s2=(float)(b/4.f);
	printf("Polumjer kruznice = %.3f\n", s1);
	printf("Stranica kvadrata =%.3f\n", s2);
	if ((2*s1)>s2)
		printf("Krug nije moguce smjestiti unutar kvadrata");
	else
		printf("Krug je moguce smjestiti unutar kvadrata");
	return 0;
}
	
	
