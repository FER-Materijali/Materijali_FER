#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void){
	
	float R1, R2, I, U, Rab, Rbc, Rca, a, b, c, d, e, f, g, h, i, j, k, l, fiA, fiB, fiC;
	
	printf("Upisite R1 u omima: ");
	scanf("%f", &R1);
	printf("Upisite R2 u omima: ");
	scanf("%f", &R2);
	printf("Upisite I u amperima: ");
	scanf("%f", &I);
	printf("Upisite U u voltima: ");
	scanf("%f", &U);
	printf("Upisite Rab u omima: ");
	scanf("%f", &Rab);
	printf("Upisite Rbc u omima: ");
	scanf("%f", &Rbc);
	printf("Upisite Rca u omima: ");
	scanf("%f", &Rca);
	
	a = 1/Rab + 1/Rca;
	b = -1/Rab;
	c = -1/Rca;
	d = I;
	e = -1/Rab;
	f = 1/Rab + 1/Rbc + 1/R1;
	g = -1/Rbc;
	h = U/R1;
	i = -1/Rca;
	j = -1/Rbc;
	k = 1/Rbc + 1/Rca + 1/R2;
	l = 0;
	
	fiC = ((l - (d*i)/a) + (b*h*i)/(-b*e + f*a) - ((b*d*e*i)/a)/(-b*e + f*a) - (h*j)/(-(b*e)/a + f) + ((d*e*j)/a)/(-(b*e)/a + f))/((b*(-(c*e)/a + g)*i)/(-b*e + f*a) - (c*i)/a - ((-(c*e)/a + g)*j)/(-(b*e)/a + f) + k);
	fiB = (h - (d*e)/a - (-(c*e)/a + g)*fiC)/(-(b*e)/a + f);
	fiA = (d - b*fiB - c*fiC)/a;
	
	printf("fiA = %f V\n", fiA);
	printf("fiB = %f V\n", fiB);
	printf("fiC = %f V\n", fiC);
	
	system ("PAUSE");
	return 0;
}