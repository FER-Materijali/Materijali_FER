#include <stdio.h>

int main( void ){
	int x, sol=0;
	int hm = -1;

	while(1){
		scanf("%d",&x);
		hm++;
		if (x<0 || x>100){
			if( !hm ){
				printf("Nije unesen niti jedan broj iz trazenog intervala\n");
				return 0;
			}
			else break;
		}
		else{
			if( x<50 ) sol += x;
		}
	}

	printf("Zbroj svih unesenih brojeva manjih od 50 je %d.\n",sol);
	return 0;
}