#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int postotakSnizenja;
	float cijena, novaCijena;
	printf("Unesite cijenu proizvoda: \n");
	scanf("%f", &cijena);
	if(cijena<=0){
		printf("Cijena mora biti pozitivan broj. \n");
		return 0;
	}
	printf("Unesite postotak snizenja: \n");
	scanf("%d", &postotakSnizenja);
	if(postotakSnizenja<=0){
		printf("Postotak snizenja mora biti prirodan broj. \n");
		return 0;
	}
	novaCijena=cijena * (100.-postotakSnizenja)/100;
	printf("Cijena %.2f umanjena za %d posto iznosi %.2f . \n", cijena, postotakSnizenja, novaCijena);
	return 0;
	
}
