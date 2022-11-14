#include<stdio.h>
int main(void){
	int a, b, c;
	printf("Upisi tri prirodna broja:");
	scanf("%d %d %d", &a, &b, &c);
	if (a+b==c)
		printf("%d + %d = %d", a, b, c);
	else if (a+c==b)
		printf("%d + %d = %d", a, c, b);
	else if(b+c==a)
		printf("%d + %d = %d", b, c, a);
	else
		printf("Niti jedan broj nije jedan zbroju preostalih brojeva.");
	return 0;
}