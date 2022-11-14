#include <stdio.h>
#include <math.h>

int main(){
	int n, a=1, b=1, x=0;

	printf("Unesi n: ");
	scanf("%d", &n);

	do{
		if(x)a++;
		x=a*a;
	}while(x<n);
	a--;
	b=a+1;
	if(b*b == n) b++;

	printf("%dx%d < n\n", a, a);
	printf("%dx%d > n\n\n", b, b);

	return 0;
}
