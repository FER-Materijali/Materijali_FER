//ovaj zadatak se moze rijesit na jako puno nacina, ja sam odabrao malo kompliciraniji 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj1, broj2, minimum, brojac=0;
	printf("Unesite 2 prirodna broja: \n");
	scanf("%d %d", &broj1, &broj2);
	if((broj1%2==0) && (broj2%2==0)){
		minimum= ((broj1<broj2)? (broj1) : (broj2));
		brojac=1;
	}
	else if((broj1%2==0) || (broj2%2==0)){
		minimum= ((broj1%2==0) ? (broj1) : (broj2));
		brojac=1;
	}
	if(brojac){
		printf("Manji parni broj je: %d", minimum);
	}
	else{
		printf("Niti jedan broj nije paran. \n");
	}
	return 0;
	
}
