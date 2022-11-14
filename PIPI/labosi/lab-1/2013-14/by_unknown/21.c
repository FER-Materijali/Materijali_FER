#include<stdio.h>

int main(void){

			float x, y;
			scanf("%f", &x);
			if(x<0) y=-x;
			else if(x==0) y=x;
			else if(x>0) y=((2*x)/3) + 3;
			printf("\r\n x = %.2f y = %.2f", x, y);
			return 0;
}
					