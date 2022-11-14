#include <stdio.h>

int main(void){
	int niz[10] = { 0 }, Ulaz, i = 0;
	scanf("%d", &Ulaz);
	printf("Znamenke u broju %d su:\n", Ulaz);
	while(Ulaz != 0){
		i = (Ulaz % 10);
		niz[i]++;
		Ulaz /= 10;
	}
	for(i = 0; i < 10; i++){
		if(niz[i] != 0){
			printf(" - znamenka %d: %d\n", i, niz[i]);
		}
	}
	return 0;
}