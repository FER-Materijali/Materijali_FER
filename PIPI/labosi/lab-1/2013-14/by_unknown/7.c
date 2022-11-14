#include<stdio.h>

int main(void){
			
			int x;
			scanf("%d", &x);
			if(((x%2)==0) && ((x%3)==0)) printf("\r\n Broj %d je djeljiv sa 6.", x);
			else if(((x%2)!=0) && ((x%3)!=0)) printf("\r\n Broj %d nije djeljiv sa 6 jer nije djeljiv ni s 2 ni s 3.", x); 
			else if((x%2)!=0) printf("\r\n Broj %d nije djeljiv sa 6 jer nije djeljiv s 2.", x);
			else if((x%3)!=0) printf("\r\n Broj %d nije djeljiv sa 6 jer nije djeljiv s 3.", x);
			return 0;
}