#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main(void){
	
	float opsegKruga, opsegKvadrata, polumjerKruga, duljinaStraniceKvadrata;
	printf("Unesite opseg kruga i opseg kvadrata: \n");
	scanf("%f %f", &opsegKruga, &opsegKvadrata);
	polumjerKruga=opsegKruga/(2*PI);
	duljinaStraniceKvadrata=opsegKvadrata/4;
	printf("Polumjer kruga: %.3f \nStranica kvadrata: %.3f \n", polumjerKruga, duljinaStraniceKvadrata);
	if((2*polumjerKruga) == duljinaStraniceKvadrata){
		printf("Krug je moguce smjestiti unutar kvadrata. \n");
	}
	else{
		printf("Krug nije moguce smjestiti unutar kvadrata. \n");
	}
	return 0;
	
}
