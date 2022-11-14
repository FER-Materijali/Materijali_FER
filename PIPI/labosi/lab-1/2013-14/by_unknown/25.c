#include<stdio.h>
#define PI 3.14159
#define K3 1.73

int main(void){

			float a, b, c;
			scanf("%f", &a);
			if(a<0){
					printf("\r\n Duljina stranice mora biti pozitivni broj.");
					return 0;
			}
			b=(a*a)/2;
			c=a*a*PI;
			printf("\r\n Povrsina trokuta: %.2f \r\n Povrsina kruga: %.2f", b, c);
			return 0;
}
			