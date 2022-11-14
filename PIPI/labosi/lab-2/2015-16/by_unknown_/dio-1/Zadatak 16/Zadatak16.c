#include <stdio.h>
#define MAX 20

int main(void){
	char niz[MAX + 1];
	int i = 0, PomVar, Slovo = 21, Znak = 21;
	gets(niz);
	while(niz[i] != '\0'){
		if(niz[i] >= 97 && niz[i] <= 122 && Slovo == 21){
			Slovo = i;
		}
		if((niz[i] < 48) || (niz[i] > 58 && niz[i] < 65) || (niz[i] > 90 && niz[i] < 97) || (niz[i] > 122)){
			Znak = i;
		}
		i++;
	}
	if(Slovo != 21 && Znak != 21){
		PomVar = niz[Slovo];
		niz[Slovo] = niz[Znak];
		niz[Znak] = PomVar;
	}
	printf("%s", niz); 
	return 0;
}