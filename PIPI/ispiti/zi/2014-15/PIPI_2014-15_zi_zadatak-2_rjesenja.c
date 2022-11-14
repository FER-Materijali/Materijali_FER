#include <stdio.h>

void ispisiStupacMaksimuma(int polje, int stupac, int red){
	int i, j, max, k, l;
	for(j=0; j<stupac; ++j){
		max=polje[i][j];
		for(i=0; i<red; ++i){
			if(max<polje[i][j]){
				max=polje[i][j];
				k=j;
			}
		}
		printf("%d\n", k);
	}
}