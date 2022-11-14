#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int x1, x2, y1, y2;
	printf("Unesite koordinate prve tocke u obliku(x y): \n");
	scanf("%d %d", &x1, &y1);
	printf("Unesite koordinate druge tocke u obliku (x y): \n");
	scanf("%d %d", &x2, &y2);
	if(x1==x2){
		printf("Pravac koji prolazi tockama (%d, %d) i (%d, %d) je paralelan s y-osi. \n", x1, y1, x2, y2);
	}
	else if(y1==y2){
		printf("Pravac koji prolazi tockama(%d, %d) i (%d, %d) je paralelan s x-osi. \n", x1, y1, x2,y2 );
	}
	else{
		printf("Pravac koji prolazi tockama (%d, %d) i (%d, %d) nije paralelan ni s jednom osi. \n", x1, y1, x2, y2);
	}
	return 0;
	
}
