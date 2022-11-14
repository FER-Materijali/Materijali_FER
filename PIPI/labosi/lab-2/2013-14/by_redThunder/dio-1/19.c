#include <stdio.h>

int main( void ){
	int x,max=-1,t;
	do{
		scanf("%d",&x);
	}while(x<100 && x>99999);
	t=x;
	while(t){
		if (max < t%10) max = t%10;
		t/=10;
	}
	printf("U broju %d najveca znamenka je: %d\n",x,max);
	return 0;
}