#include <stdio.h>

int main (void){
	int broj, suma, preth;
	printf("upisati brojeve: ");
	scanf("%d", &broj);
	suma=broj;
	do{
		preth=broj;
		scanf("%d", &broj);
		if(broj>preth)
			suma+=broj;
	}while(broj>preth);
	printf("suma: %d", suma);
	return 0;
}