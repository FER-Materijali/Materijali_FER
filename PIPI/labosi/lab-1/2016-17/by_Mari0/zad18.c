//ovo se mozda moglo i na laksi nacin napravit :) //

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int a, b, c;
	printf("Unesite 3 prirodna broja: \n");
	scanf("%d %d %d", &a, &b, &c);
	if(a+b==c){
		printf("%d + %d = %d \n", a, b, c);
	}
	else{
		if(a+c==b){
			printf("%d + %d = %d \n", a, c, b);
		}
		else{
			if(b+c==a){
				printf("%d + %d = %d \n", b, c, a);
			}
			else{
				printf("Niti jedan broj nije jednak zbroju preostalih brojeva. \n");
			}
		}
	}
	return 0;
	
}
