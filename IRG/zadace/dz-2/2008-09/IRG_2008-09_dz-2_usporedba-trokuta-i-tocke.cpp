#include <stdio.h>
#include <math.h>

void pravac (float *p, float *t1, float *t2)
{
	float i, j, k;
	i = t1[1]*t2[2] - t1[2]*t2[1];
	j = - t1[0]*t2[2] + t1[2]*t2[0];
	k = t1[0]*t2[1] - t1[1]*t2[0];
	p[0] = i;
	p[1] = j;
	p[2] = k;
	return;
}

float pomnozi(float *t, float *p)
{
	float rez;
	rez = t[0]*p[0]+t[1]*p[1]+t[2]*p[2];
	return rez;
}

float povrsina (float *t1, float *t2, float *t3)
{
	float rez;
	float pom2[3], pom3[3], pom1[3];
	int i;
	for (i =0; i< 3; i++)
	{
		pom2[i] = t2[i] - t1[i];
		pom3[i] = t3[i] - t1[i];
	}
	pravac (pom1, pom2, pom3);
	rez = sqrt(pom1[0]*pom1[0]+pom1[1]*pom1[1]+pom1[2]*pom1[2]);
	return rez;
}

int main()
{
	float V1[3] = {13., 7., 6.}, V2[3] = {10., 1., 5.}, V3[3]= {5., 16., 9.};
	float t1[3] = {8.34, 9.84, 7.2 }, t2[3] = {10.74, 6.66, 6.19};
	float a[3], b[3], c[3], rez[6];
	float A[4];


	
	A[0] = povrsina (V1, V2, V3);
	A[1] = povrsina (V1, V2, t1);
	A[2] = povrsina (V1, t1, V3);
	A[3] = povrsina (t1, V2, V3);
	printf ("\n %2.2f = %2.2f + %2.2f + %2.2f + = %2.2f", A[0], A[1], A[2], A[3], A[1]+ A[2]+ A[3]);
	//pravac (test, T1, T2);

	A[1] = povrsina (V1, V2, t2);
	A[2] = povrsina (V1, t2, V3);
	A[3] = povrsina (t2, V2, V3);
	printf ("\n %2.2f = %2.2f + %2.2f + %2.2f + = %2.2f", A[0], A[1], A[2], A[3], A[1]+ A[2]+ A[3]);


	//V1[0] = 2.*V1[0]/V1[2];
	//V1[1] = 2.*V1[1]/V1[2];
	V1[2] = 1.;
	//V2[0] = 2.*V2[0]/V2[2];
	//V2[1] = 2.*V2[1]/V2[2];
	V2[2] = 1.;
	//V3[0] = 2.*V1[0]/V1[2];
	//V3[1] = 2.*V1[1]/V1[2];
	V3[2] = 1.;


	//t1[0] = 2.*t1[0]/t1[2];
	//t1[1] = 2.*t1[1]/t1[2];
	t1[2] = 1.;
	//t2[0] = 2.*t2[0]/t2[2];
	//t2[1] = 2.*t2[1]/t2[2];
	t2[2] = 1.;

	pravac (a, V1, V2);
	pravac (b, V2, V3);
	pravac (c, V3, V1);

	rez[0] = pomnozi (t1, a);
	rez[1] = pomnozi (t1, b);
	rez[2] = pomnozi (t1, c);
	rez[3] = pomnozi (t2, a);
	rez[4] = pomnozi (t2, b);
	rez[5] = pomnozi (t2, c);

	if (rez[0] > 0 || rez[1] > 0 || rez[2] > 0)
		printf ("\n Tocka1 nije unutar trokuta");
	else
		printf ("\n Tocka1 je unutar trokuta");

	if (rez[4] > 0 || rez[5] > 0 || rez[3] > 0)
		printf ("\n Tocka2 nije unutar trokuta\n");
	else
		printf ("\n Tocka2 je unutar trokuta\n");


	return 0;
}