#include <stdio.h>

int main (void){
	int dg, gg, broj, i, j, ne, brojac=0;
	scanf("%d", &dg);
	scanf("%d", &gg);
	if(dg>gg){
		broj=dg-gg+1;
		i=gg;
	}
	else{
		broj=gg-dg+1;
		i=dg;
	}
	while(broj!=0){
	    ne=1;
		for(j=2; j<=7; ++j){
			if(i%j==0){
				ne=0;
			}
		}
		if(ne==1){
			printf("%d\n", i);
			++brojac;
		}
		++i;
		--broj;
	}
	printf("%d", brojac);
	return 0;
}