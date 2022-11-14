#include<stdio.h>

int main(void){

			int x, y, k, a;
			scanf("%d %d %d", &x, &y, &k);
			if(k==1){ a=x+y;
			}else{if(x>y){ 
							a=x-y;
							}else{
							a=y-x;
							}
							}
			printf("\r\n Za ucitane brojeve %d i %d i odabranu operaciju %d rezultat je %d", x, y, k, a);
			return 0;
}
