#include<stdio.h>
int main(void){
	int m, n;
	float d;
	printf("Upisi dva prirodna broja:");
	scanf("%d %d", &m, &n);
	if (n%10!=0){
		d = m*1.0 / (n%10);
		printf("%d / %d = %.2f", m, n%10, d);
	}
	else
		printf("Dijeljenje nije moguce.");
	return 0;
}
/*zasto ne mogu m stavit kao float, nego treba nova varijabla*/