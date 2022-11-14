#include<stdio.h>
int main(void){
	float krug, kvad, a, r;
	printf("Upisi realne brojeve koji predstavljaju opseg kruga i opseg kvadrata: ");
	scanf("%f %f", &krug, &kvad);
	a = kvad/4;
	r = krug/(2*3.14159);
	printf("Polumjer kruga = %.3f\nStranica kvadrata=%.3f", r, a);
	if (2*r<a)
		printf("Moguce je smjestiti krug unutar kvadrata.");
	else
		printf("\nKrug nije moguce smjestiti unutar kvadrata.");
		
	return 0;
}