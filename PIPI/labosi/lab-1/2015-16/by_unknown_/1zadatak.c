#include <stdio.h>

int main(void){
	int broj;
	scanf("%d", &broj);
	int a=broj%10;
	int b=broj%100;
	if(broj % 10<5){
	printf("Zadnja znamenka broja %d je %d", broj,a);
	} else {
	printf("Zadnje dvije znamenke broja %d su %d", broj,b);
	}
	return 0;
}