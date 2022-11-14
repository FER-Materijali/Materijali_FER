#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj1, broj2, broj3, razlika1, razlika2;
	printf("Unesite 3 cijela broja: \n");
	scanf("%d %d %d", &broj1, &broj2, &broj3);
	if((broj1<=broj2) && (broj2<=broj3)){
		razlika1=broj2-broj1;
		razlika2=broj3-broj2;
		if(razlika1==razlika2){
			printf("Brojevi %d , %d i %d su poredani uzlazno (razlika izmedju susjednih brojeva je %d). \n", broj1, broj2, broj3, razlika1);
		}
		else{
			printf("Brojevi %d , %d i %d su poredani uzlazno (razlika izmedju susjednih brojeva nije jednaka). \n", broj1, broj2, broj3);
		}
	}
	else{
		printf("Brojevi %d , %d i %d nisu poredani uzlazno. \n", broj1, broj2, broj3);
	}
	return 0;
	
}
