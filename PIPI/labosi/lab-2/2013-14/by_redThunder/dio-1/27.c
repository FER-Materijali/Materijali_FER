#include <stdio.h>

int main( void ){
	int x, min = 101, max = 0;
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
			if( !(x%4) ){
				min = (min>x ? x : min);
				max = (max<x ? x : max);
			}
		}
	}

	printf("Zbroj najveceg (%d) i najmanjeg (%d) unesenog broja djeljivog s 4 je %d.\n",max,min,max+min);
	return 0;
}