#include<stdio.h>
int main(void){
	int x,y;
	printf("Upisi cijele brojeve x i y, s uvjetom da je y>x:");
	scanf("%d %d", &x, &y);
	if (y>x){
		printf("x = %d i y = %d", y, x);
	}
	else
		printf("Brojevi nisu dobro zadani.");	
		
	return 0;
}