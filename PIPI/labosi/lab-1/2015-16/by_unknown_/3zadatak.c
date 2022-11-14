#include <stdio.h>
#include <math.h>

int main(void){
	int broj;
	scanf("%d", &broj);
	int a=broj/10%10;
	printf ("Srednja znamenka broja %d je %d", broj,abs(a));
	return 0;
}