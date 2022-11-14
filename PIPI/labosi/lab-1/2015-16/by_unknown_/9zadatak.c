#include <stdio.h>

int main(void){
	int broj;
	scanf("%d",&broj);
	int a=broj%10;
	if (broj%3==0){
		if(a==8){
			printf("Broj %d je djeljiv s 3 i zadnja znamenka mu je 8.",broj);
		} else {
			printf("Broj %d je djeljiv s 3 i zadnja znamenka mu nije 8.",broj);
		}
	} else {
		if(a==8){
			printf("Broj %d nije djeljiv s 3 i zadnja znamenka mu je 8.",broj);
		} else {
			printf("Broj %d nije djeljiv s 3 i zadnja znamenka mu nije 8.",broj);
		}
	}
	return 0;
}