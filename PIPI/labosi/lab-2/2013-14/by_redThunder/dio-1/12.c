#include <stdio.h>
#define MAX 60

int main( void ){
	int x,freq[MAX]={0},n=0;
	while(1){
		scanf("%d",&x);
		freq[x+30]++;
		n++;
		if (freq[x+30]>2){
			break;
		}
	}
	printf("Ukupno je ucitano %d brojeva\n",n);
	return 0;
}