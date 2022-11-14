#include <stdio.h>

int main( void ){
	int x, max1 = 0, max2 = 0;
	int hm = 0;

	while(1){
		scanf("%d",&x);
		hm++;
		if (x<0 || x>100){
			if( hm<2 ){
				printf("Nije uneseno dovoljno brojeva iz trazenog intervala\n");
				return 0;
			}
			else break;
		}
		else{
				if( x>max1 ){
					max2 = max1;
					max1 = x;
				}
				else if ( x>max2) max2 = x;
		}
	}

	printf("Ostatak pri dijeljenju %d sa %d je %d.",max1,max2,max1%max2);
	return 0;
}