#include <stdio.h>

int main(void){
	int broj;
	scanf("%d", &broj);
	if(broj<=0){
	printf("Neispravan broj");
	} else {
		if(broj%2==0){
		printf("Broj je paran");
		} else {
		printf("Broj je neparan");
		}
	}
	return 0;
}