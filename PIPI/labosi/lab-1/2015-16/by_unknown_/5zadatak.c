#include <stdio.h>

int main(void){
	int broj;
	scanf("%d", &broj);
	int a=broj/100;
	int b=broj/10%10;
	int c=broj%10;
	int rez=a*b*c;
	printf ("Umnozak znamenaka broja %d je %d", broj, rez);
	return 0;
}