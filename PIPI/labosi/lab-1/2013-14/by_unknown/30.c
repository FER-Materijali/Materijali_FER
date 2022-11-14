#include<stdio.h>

int main(void){

			int a, b, c, x, y, k=0;
			scanf("%d %d %d", &a, &b, &c);
			if((a<b) && (b<c)) k=1;
			else printf("\r\n Brojevi %d, %d, %d nisu poredani uzlazno.", a, b, c);
			x=b-a;
			y=c-b;
			if((k==1) && (x==y)) printf("\r\n Brojevi %d, %d, %d su poredani uzlazno(razlika izmedu susjednih brojeva je %d).", a, b, c, x);
			else if(k==1) printf("\r\n Brojevi %d, %d, %d su poredani uzlazno(razlika izmedu susjednih brojeva nije jednaka).", a, b, c);
			return 0;
}