#include <stdio.h>

int main (void){
	int dg1, gg1, dg2, gg2, broj1=0, broj2=0, broj3=0, broj;
	scanf("%d", &dg1);
	scanf("%d", &gg1);
	scanf("%d", &dg2);
	scanf("%d", &gg2);
	scanf("%d", &broj);
	while(broj!=0){
		if(broj>=dg1 && broj<=gg1)
			++broj1;
		if(broj>=dg2 && broj<=gg2)
			++broj2;
		if((gg1-dg2)>0)
			if(broj>=dg2 && broj<=gg1)
				++broj3;
		scanf("%d", &broj);
	}
	printf("interval [%d, %d]: %d\n", dg1, gg1, broj1);
	printf("interval [%d, %d]: %d\n", dg2, gg2, broj2);
	printf("interval [%d, %d]: %d\n", dg2, gg1, broj3);
	return 0;
}