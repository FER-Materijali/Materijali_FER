#include <stdio.h>

int zadatak (int broj){
	int x=0;
	while(broj>0){
		x+=broj%10;
		broj/=10;
	}
	x=x%15+1;
	return x;
}

int main () {
	int mat, i, n=50;
	for(i=0;i<n;++i){
		printf("Unesi maticni broj: ");
		scanf("%d", &mat);
		printf("\n\nTrebate rijesiti %d. zadatak.\n\n", zadatak(mat));
	}
	return 0;
}
