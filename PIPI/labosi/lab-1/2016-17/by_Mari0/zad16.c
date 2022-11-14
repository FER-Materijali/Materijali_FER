#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int brojMinuta, brojSekundi, sekunde;
	float sati;
	printf("Unesite 2 prirodna broja koji predstavljaju broj minuta i broj sekundi: \n");
	scanf("%d %d", &brojMinuta, &brojSekundi);
	if(brojSekundi>59)
		printf("Neispravan broj sekundi. \n");
	else{
		sekunde=brojSekundi + brojMinuta*60;
		sati=(float)sekunde/3600;
		printf("sekunde: %d , sati: %.3f", sekunde, sati);
	}
	return 0;
}
