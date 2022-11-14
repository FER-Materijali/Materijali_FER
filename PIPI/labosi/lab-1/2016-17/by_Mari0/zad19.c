//kada sam prvi put rjesavo ovaj zadatak, dobivo sam cudna rjesenja pa tek kad sam ubacio ovu varijablu brojac, program mi je dobro radio, probajte nekako napravit program bez te varijable :)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj1, broj2, uvjet1, brojac=1;
	float uvjet2;
	printf("Unesite 2 prirodna broja: \n");
	scanf("%d %d", &broj1, &broj2);
	if(broj1==broj2){
		printf("Brojevi moraju biti razliciti. \n");
		return 0;
	}
	if(broj1>broj2){
		uvjet1=broj1/broj2;
		uvjet2=(float)(broj1)/broj2;
		if((float)uvjet1==uvjet2){
			printf("Broj %d je visekratnik broja %d. \n", broj2, broj1);
			brojac=0;
		}
	}
	else {
	if(broj1<broj2){
		uvjet1=broj2/broj1;
		uvjet2=(float)broj2/broj1;
		if((float)uvjet1==uvjet2){
			printf("Broj %d je visekratnik broja %d. \n", broj1, broj2);
			brojac=0;
		}
		}
		}
	if(brojac){
		printf("Niti jedan ucitani broj nije visekratnik drugog ucitanog broja. \n");
	}
	return 0;
}
