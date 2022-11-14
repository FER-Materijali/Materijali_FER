#include <stdio.h>
#define MAX 30

int main( void ){
	int x,freq[MAX+1]={0},i;
	while (1){
		scanf("%d",&x);
		if (x<1 || x>30) break;
		freq[x]++;
	}
	for(i=1;i<31;i++){
		if( freq[i]>1 ) printf("broj %2d: %d\n",i,freq[i]);
	}
	return 0;
}