#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

	int broj;
	printf("Unesite cijeli broj: \n");
	scanf("%d", &broj);
	if(broj<=0){
		printf("Neispravan broj! \n");
	}
	else{
		if(broj%2==0)
			printf("Broj %d je paran broj. \n", broj);
	else
		printf("Broj %d je neparan broj. \n", broj);
	}
	return 0;
	
}

