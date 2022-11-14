#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj, uvjet1, uvjet2;
	printf("Unesite jedan prirodni broj: \n");
	scanf("%d", &broj);
	uvjet2=broj%3;
	uvjet1=broj%10;
	if(uvjet1==8){
		if(!uvjet2)
			printf("Broj %d je djeljiv sa 3 i zadnja znamenka mu je 8. \n", broj);
	else
			printf("Broj %d nije djeljiv sa 3 i zadnja znamenka mu je 8. \n", broj);
	}
	else{
		if(!uvjet2)
			printf("Broj %d je djeljiv sa 3 i zadnja znamenka mu nije 8. \n", broj);
		else
			printf("Broje %d nije djeljiv sa 3 i zadnja znamenka mu nije 8. \n", broj);
	}
	return 0;
	
}
