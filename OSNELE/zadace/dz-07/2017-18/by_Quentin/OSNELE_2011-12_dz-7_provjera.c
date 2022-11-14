#include <stdio.h>
#include <math.h>

int main(void)
{
	double R, X, Pw, I, U, S, Q;
	
	printf("Upisite ukupan otpor jednog otpornika (pazite je li R ili 2R): ");
	scanf("%lf", &R);
	printf("Upisite ukupnu impedanciju jedne zavojnice (pazite je li X ili 2X): ");
	scanf("%lf", &X);
	printf("Upisite snagu Pw: ");
	scanf("%lf", &Pw);
	
	I = sqrt(2 * Pw / R);
	U = I * sqrt(R * R + X * X) / 2.;
	S = U * I;
	Q = X * I * I / 2.;
	
	printf("I = %lf A\nU = %lf V\nS = %lf VA\nQ = %lf VAr\n", I, U, S, Q);
	
	getchar();
	
	return 0;
}