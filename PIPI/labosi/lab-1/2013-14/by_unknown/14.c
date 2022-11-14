#include<stdio.h>

int main(void){
			
			unsigned int m, n, x;
			float a;
			scanf("%u %u", &m, &n);
			x=n%10;
			if(x==0){ 
					printf("\r\n Dijeljenje nije moguce");
					return 0;
			}
			a=(float)m/x;
			printf("\r\n %u/%u = %.2f", m, n, a);
			return 0;
}