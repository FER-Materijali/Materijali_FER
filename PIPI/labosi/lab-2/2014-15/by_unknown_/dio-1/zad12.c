#include<stdio.h>
int main(void){
	int b1, b2, op;
	printf("Upisi dva cijela broja odvojena razmakom:");
	scanf("%d %d", &b1, &b2);
	printf("Upisi 1 ako brojeve zelis zbrojiti, a 2 ako zelis oduzeti manji od veceg:");
	scanf("%d", &op);
	if (op==1)
		printf("%d + %d = %d", b1, b2, b1+b2);
	else if (b1>b2)
		printf("%d - %d = %d", b1, b2, b1-b2);
	else
		printf("%d - %d = %d", b2, b1, b2-b1);
	return 0;
}