#include <stdio.h>
#define MAX 30
		
int main(void){
	char niz1[MAX + 1], niz2[MAX + 1];
	int Brojac = 0, i = 0;
	gets(niz1);
	gets(niz2);
	while((niz1[i] != '\0') && (niz2[i] != '\0')){
		if(i % 2 == 0){
			niz1[i] = niz2[i];
			Brojac++;
		}
		i++;
	}
	printf("Promijenjeni niz: %s\n", niz1);
	printf("Proijenjeno znakova: %d\n", Brojac);
	return 0;
}