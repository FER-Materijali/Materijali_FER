#include<stdio.h>

int main(void){
			
			unsigned int x, y;
			scanf("%u %u", &x, &y);
			if(((x%2==0) && (y%2==0))){
									if(x>y) printf("\r\n Manji parni broj je: %u.", y);
									}
			else if(x%2==0) printf("\r\n Manji parni broj je: %u.", x);
			else if(y%2==0) printf("\r\n Manji parni broj je: %u.", y);
			else printf("\r\n Niti jedan broj nije paran.");
			return 0;
}