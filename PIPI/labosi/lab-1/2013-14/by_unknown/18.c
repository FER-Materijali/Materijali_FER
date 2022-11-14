#include<stdio.h>

int main(void){
			
			unsigned int a, b, c;
			scanf("%u %u %u", &a, &b, &c);
			if((a+b)==c) printf("\r\n %u + %u = %u", a, b, c);
			else if((a+c)==b) printf("\r\n %u + %u = %u", a, c, b);
			else if((b+c)==a) printf("\r\n %u + %u = %u", b, c, a);
			else printf("\r\n Niti jedan broj nije jednak zbroju preostalih brojeva");
			return 0;
}