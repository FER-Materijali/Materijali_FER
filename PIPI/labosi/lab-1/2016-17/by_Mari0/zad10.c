#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int broj, jedinica, desetica, stotica, uvjet;
	printf("Unesite cijeli troznamenkasti broj: \n");
	scanf("%d", &broj);
	jedinica=broj%10;
	desetica=(broj/10)%10;
	stotica=broj/100;
	uvjet=pow(jedinica,3) + pow(desetica,3) + pow(stotica,3);
	if(uvjet == broj)
		printf("Broj %d je Armstrongov broj. \n", broj);
	else
		printf("Broj %d nije Armstrongov broj. \n", broj);
	return 0;
	
}
