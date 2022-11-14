#include<stdio.h>
int main(void){
	int a, b, c;
	printf("Upisi tri cijela broja:");
	scanf("%d %d %d", &a, &b, &c);
	if ((a<b)<c) {
		printf("Brojevi %d, %d, %d su poredani uzlazno ", a, b, c);
		if ((b-a)==(c-b))
			printf("(razlika izmedju susjednih brojeva je %d).", b-a);
		else 
			printf("(razlika izmedju susjednih brojeva nije jednaka).");
	}
	else
		printf("Brojevi %d, %d, %d nisu poredani uzlazno.", a, b, c);
	return 0;
}