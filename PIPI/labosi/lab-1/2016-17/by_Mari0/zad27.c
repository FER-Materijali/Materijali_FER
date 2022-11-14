#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj1, broj2, noviBroj1, noviBroj2, rezultat;
	printf("Unesite 2 jednoznamenkasta prirodna broja: \n");
	scanf("%d %d", &broj1, &broj2);
	noviBroj1=broj1*10 + broj2;
	noviBroj2=broj1 + broj2*10;
	if((noviBroj1%2==0) && (noviBroj2%2==0)){
		printf("Parni brojevi kreirani od znamenaka %d i %d su: %d %d \n", broj1, broj2, noviBroj1, noviBroj2);
	}
	else if((noviBroj1%2==0) || (noviBroj2%2==0)){
		rezultat= ((noviBroj1%2==0) ? (noviBroj1) : (noviBroj2));
		printf("Parni brojevi kreirani od znamenaka %d i %d su: %d \n", broj1, broj2, rezultat);
	}
	else{
		printf("Parni brojevi kreirani od znamenaka %d i %d su: - \n", broj1, broj2);
	}
	return 0;
	
}
