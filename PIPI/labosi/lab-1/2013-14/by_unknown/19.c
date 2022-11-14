#include<stdio.h>

int main(void){

			unsigned int x, y;
			scanf("%u %u", &x, &y);
			if(x==y){
					printf("\r\n Brojevi moraju biti razliciti.");
					return 0;
			}
			else if((x%y)==0) printf("\r\n Broj %u je visekratnik broja %u.", x, y);
			else if((y%x)==0) printf("\r\n Broj %u je visekratnik broja %u.", y, x);
			else printf("\r\n Niti jedan ucitani broj nije visekratnik drugog ucitanog broja.");
			return 0;
}
			
			