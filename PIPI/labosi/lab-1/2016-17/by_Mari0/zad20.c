#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	float broj1, broj2, broj3, minimum, maksimum;
	printf("Unesite 3 razlicita realna broja: \n");
	scanf("%f %f %f", &broj1, &broj2, &broj3);
	minimum=broj1;
	if(minimum>broj2)
		minimum=broj2;
	if(minimum>broj3)
		minimum=broj3;
	maksimum=broj1;
	if(maksimum<broj2)
		maksimum=broj2;
	if(maksimum<broj3)
		maksimum=broj3;
	printf("Broj %.1f je najmanji, a broj %.1f je najveci od ucitanih brojeva. \n", minimum, maksimum);
	return 0;
	
}
