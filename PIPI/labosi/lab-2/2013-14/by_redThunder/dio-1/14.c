#include <stdio.h>
#define MAX 30

int main( void ){
	int num[MAX+1]={0},i=1,x;
	while(1){
		scanf("%d",&x);
		if( x<1 || x>30 ) continue;
		if( num[x] ) break;
		num[x] = i++;
	}
	printf("Broj %d bio je %d. ucitani broj.\nUkupno ucitano brojeva: %d",x,num[x],i);
	return 0;
}