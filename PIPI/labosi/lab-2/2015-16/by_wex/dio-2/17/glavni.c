#include <stdio.h>
#include "funkcije.h"

int main(void) {
	player igrac[10];
	int i, krugovi, igraci;
	
	for (i=0; i<10; i++) {
		igrac[i].bodovi = 0;
		igrac[i].ispao = 0;
	}
	
	printf("Upisi broj igraca i broj krugova: ");
	scanf(" %d %d", &igraci, &krugovi);
	
	simulirajIgru(&igrac[0], igraci, krugovi);
	
	printf("igrac    negativnih bodova\n");
	for (i=0; i<igraci; i++) {
		printf("%3d%9d", i+1, igrac[i].bodovi);
		if (igrac[i].ispao) printf(" - ispao u %d. krugu\n", igrac[i].krug_ispadanja);
		else printf("\n");
	}

	return 0;
}