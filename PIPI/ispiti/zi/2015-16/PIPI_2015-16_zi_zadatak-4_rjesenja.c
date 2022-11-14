#include <stdio.h>

void umetniclan(float *polje, int n, float x){
	int i=0, j;
	while (i < n && polje[i] >= x) {
        ++i;
    }
	if(i!=n){
		for (j = n - 1; j > i; --j) 
		    polje[j] = polje[j - 1];
		polje[i]=x;
		}
	
	return;
}

int main (void){
	float polje[5]={0.2f};
	int i, j;
	float broj;
	for(i=0; i<10; ++i){
		broj=rand()%1000/100.f;
		printf("ubacujem %4.2f: ", broj);
		umetniclan(polje, 5, broj);
		for(j=0; j<5; ++j)
			printf(" %4.2f", polje[j]);
		printf("\n");
	}
	return 0;
}