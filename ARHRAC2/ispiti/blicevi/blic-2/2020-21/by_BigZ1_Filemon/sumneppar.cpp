#include<iostream>

extern "C" int sumneppar_asm(int) asm("sumneppar_asm");

int sumneppar_c(int n){
	int sumap=0;
	int suman=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			sumap+=i;
		}
		if(i%2==1){
			suman+=i;
		}
	}
	return sumap-suman;
}

int main(){
	int n=10;
	int a=sumneppar_asm(n);
	int b=sumneppar_c(n);
	printf("%d",a);
	printf("%d",b);
	return 0;
}