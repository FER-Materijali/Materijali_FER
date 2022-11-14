#include <stdio.h>
#include <math.h>

int main(){
	int i=1,k=0, broj2, broj3, znam;
	float broj, br=0;

	printf("Unesi broj: ");
	scanf("%f",&broj);
	broj2 = (int)(broj*100);
	
	while (broj2>0){                             //kraca verzija
		br+= (broj2%10)*(float)(pow(10,i));
		broj2/=10;
		i--;
	}

	/*
	broj2 = (int)(broj*pow(10,2));          //kompliciranija verzija
	broj3 = broj2;

	while(broj3>0){
		broj3 /=10;
		k++;
	}
	for(i=k;i>0;--i){
		znam=broj2%10;
		br += znam*(int)(pow(10,(i-1)));
		broj2/=10;
	}

	br*=pow(10,(-k+2));
	*/

	printf("Novi broj citan naopacke je: %f\n\n", br);
	return 0;
}



