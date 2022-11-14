#include <stdio.h>

int main(void){
	int n, i;
	float Pola = 0, Apsolutno;
	do{
		scanf("%d", &n);
	}while((n < 1) && (n >1000));
	for(i = 1; i <= n; i++){
		Pola += ( 1. / (( 2 * i - 1 ) * ( 2 * i + 1)));
	}
	Apsolutno = 0.5 - Pola;
	if(Apsolutno < 0){
		Apsolutno = - Apsolutno;
	}
	printf("%f \n%f \n", Pola, Apsolutno);
	return 0;
}