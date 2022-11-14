#include <stdio.h>
#define MAX 10

int main( void ){
	int num[MAX]={0},x,i,t;
	do{
		scanf("%d",&x);
	}while(x<100 && x>99999);
	t=x;
	while(t){
		num[t%10]++;
		t/=10;
	}
	printf("Znamenke u broju %d su: \n\n",x);
	for(i=0;i<10;i++){
		if (num[i]) printf("  -  znamenka %d: %d\n",i,num[i]);
	}
	return 0;
}