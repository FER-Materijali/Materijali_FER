#include <stdio.h>
#define MAX 30

int main(void){
	char niz[MAX + 1];
	int i = 0, Slovo = 0, Broj = 0;
	gets(niz);
	while(niz[i] != '\0'){
		if(niz[i] >= 97 && niz[i] <= 122){
			Slovo += 1;
		}else if(niz[i] >= 48 && niz[i] <= 58){
			Broj += 1;
		}
		i++;
	}
	if(Slovo < 7 || Broj < 2){
		printf("Ne zadovoljava uvjete");
	}else{
		printf("Zadovoljava uvjete");
	}
	return 0;
}