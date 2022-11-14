#include<stdio.h>
int main(void){
	float b;
	printf("Upisi duljinu kraka pravokutnog jednakokracnog trokuta:");
	scanf("%f", &b);
	if (b<=0)
		printf("Duljina stranice mora biti pozitivni broj.");
	else 
		printf("Povrsina trokuta: %.2f\nPovrsina kruga: %.2f", b*b/2, b*b*3.14159);
	return 0;
}