#include <stdio.h>
#define PI 3.141593

int main(void){
	int n, i, Promjena = 1;
	float pi_c = 0, Apsolutno;
	do{
		scanf("%d", &n);
	}while((n < 1) && (n >1000));
	for(i = 1; i <= n; i++){
		pi_c += Promjena * ( 1. / ( 2 * i - 1 ));
		Promjena = - Promjena;
	}
	Apsolutno = PI - ( pi_c * 4 );
	if(Apsolutno < 0){
		Apsolutno = - Apsolutno;
	}
	printf("%f \n%f \n", pi_c * 4, Apsolutno);
	return 0;
}