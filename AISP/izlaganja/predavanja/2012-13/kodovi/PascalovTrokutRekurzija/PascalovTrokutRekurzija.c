#include <stdio.h>


int p(int kat, int i){
	if (i==0 || i==(kat+1)) return 1;
	return p(kat-1, i-1) + p(kat-1, i);
}

void BlaisePascal(int kat){
	int i, k;
	for (k=0; k <= kat; k++){
		printf("\n");
		for (i=0; i<=k+1; i++)
			printf(" %3d", p(k, i));
	}
}
int main (void) {
	int kat;
	scanf("%d", &kat);
	BlaisePascal(kat);	
	system("PAUSE");
	return 0;
}


