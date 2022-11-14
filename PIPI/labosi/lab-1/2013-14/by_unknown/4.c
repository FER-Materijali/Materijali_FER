#include<stdio.h>

int main(void){
    
			int x;
			scanf("%d", &x);
			if(x <= 0){
				printf("\r\n Neispravan broj");
				return 0;
			}else{
				if((x%2)==0) 
					printf("\r\n Broj %d je parni broj.", x);
					else
						printf("\r\n Broj %d je neparani broj.", x);
			}
			return 0;
}
