#include <stdio.h>
#define MAX 10

int main( void ){
	int num[MAX]={0},x,i,t,sol=0;
	do{
		scanf("%d",&x);
	}while(x<1 && x>99999);
	t=x;
	while(t){
		num[t%10]++;
		t/=10;
	}

	for(i=0;i<10;i++){
		if (num[i]==1) sol+=i;
	}
	printf("Broj %d - suma znamenaka koje se jednom pojavljuju: %d\n",x,sol);
	return 0;
}