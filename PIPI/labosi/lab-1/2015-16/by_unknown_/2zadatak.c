#include <stdio.h>
#include <math.h>

int main(void){
	int broj;
	scanf ("%d", &broj);
	int a=broj/10;
	int b=broj%10;
	if (a!=5, a!=-5){
	printf("Prva znamenka broja %d je %d",broj,abs(a));
	} else {
	printf("Zadnja znamenka broja %d je %d",broj,abs(b));
	}
	return 0;
}