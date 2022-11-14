#include<stdio.h>
int main(void){
	int sek, min, sat, sek1;
	printf("Upisi vrijeme izrazeno u sekundama:");
	scanf("%d", &sek);
	sat = sek/3600;
	min = (sek%3600)/60;
	sek1 = sek - sat*3600 - min*60;
	printf("sekunde: %d =  %d-%d-%d", sek, sat, min, sek1 );
	return 0;
}