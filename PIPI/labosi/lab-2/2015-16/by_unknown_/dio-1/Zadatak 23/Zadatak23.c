#include <stdio.h>
#define MAX 10

int main(void){
	char niz[MAX + 1];
	int i = 0, Provjera = 0, DvijeNule = 0;
	gets(niz);
	while(niz[i] != '\0'){
		if(niz[i] != '0' && niz[i] != '1'){
			Provjera = 1;
			break;
		}else if(niz[i] == '0' && niz[i + 1] == '0'){
			DvijeNule = 1;
			break;
		}
		i++;
	}
	if(Provjera == 1){
		printf("Ucitani niz nije ispravno zadan.");
	}else if(DvijeNule == 1){
		printf("Ucitani binarni broj sadrzi dvije ili vise uzastopnih znamenki 0.");
	}else{
		printf("Ucitani binarni broj ne sadrzi dvije ili vise uzastopnih znamenki 0.");
	}
	return 0;
}