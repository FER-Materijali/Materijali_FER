#include <stdio.h>
int main(void) {
	float x1,x2,y;
	printf("Ucitajte 2 realna broja");
	scanf("%f %f", &x1, &x2);
	if (x1>x2){
		if (x1<0)
			y=-x1;
		else
			y=x1;
	}
	if (x2>=x1){
		if ((x2*x2)>(x1*x1))
			y=x2*x2;
		else
			y=x1*x1;
	}
	printf("y= %.2f", y);
	return 0;
}