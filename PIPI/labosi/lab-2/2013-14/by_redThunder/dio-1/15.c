#include <stdio.h>
#define MAX 40

int main( void ){
	int x,num[MAX+1]={0},i=1;
	while (1){
		scanf("%d",&x);
		if (x<1 || x>40) break;
		if ( !num[x] ) num[x]=i++;
	}
	for(i=1;i<31;i++){
		if( num[i] ) printf("broj %2d: %d\n",i,num[i]);
	}
	return 0;
}