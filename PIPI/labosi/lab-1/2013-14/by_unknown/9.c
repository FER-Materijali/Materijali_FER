#include<stdio.h>

int main(void){
			
			int x;
			scanf("%d", &x);
			if(((x%3)==0) && ((x%10)==8)) printf("\r\n Broj %d je djeljiv s 3 i zadnja znamenka mu je 8.", x);
			else if(((x%3)!=0) && ((x%10)==8)) printf("\r\n Broj %d nije djeljiv s 3 i zadnja znamenka mu je 8.", x);
			else if(((x%3)==0) && ((x%10)!=8)) printf("\r\n Broj %d je djeljiv s 3 i zadnja znamenka mu nije 8.", x);
			else if(((x%3)!=0) && ((x%10)!=8)) printf("\r\n Broj %d nije djeljiv s 3 i zadnja znamenka mu nije 8.", x);
			return 0;
}		