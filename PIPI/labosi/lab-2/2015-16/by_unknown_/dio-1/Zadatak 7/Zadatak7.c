#include <stdio.h>
#define MAX 20

int main(void){
	char niz[MAX + 1] = {'0'};
	int i = 0, Slovo = 0, Kratak = 1;
	gets(niz);
	while(niz[i] != '\0'){
		if(i >= 8){
			Kratak = 0;
			break;
		}else if((niz[i] >= 65 && niz[i] <= 90) || (niz[i] >= 97 && niz[i] <= 122)){
			Slovo = 1;
		}
		i++;
	}
	if(Kratak == 1){
		printf("Prekratak");
	}else if(Slovo == 1){
		printf("Zadovoljava uvjete");
	}else{
		printf("Ne sadrzi slovo");
	}
	return 0;
}