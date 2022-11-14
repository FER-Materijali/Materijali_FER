#include <stdio.h>
#include <math.h>

int fun1(void);
void dev(float *sredina, float *dev);

int main()
{
	float sredina, devi;

	dev(&sredina, &devi);

	printf("%f %f", sredina, devi);
}

int fun1(void)
{
	return rand() % 201 - 100;
}

void dev(float *sredina, float *dev)
{
	int i, brojevi[1000];

	srand(time(NULL));

	*sredina = *dev = 0;

	for (i = 0; i < 1000; i ++) {
		brojevi[i] = fun1();
		*sredina += brojevi[i] / 1000.f;
	}

	for (i = 0; i < 1000; i++)
		*dev += pow(brojevi[i] - *sredina, 2);

	*dev = pow(*dev / 1000, 1/2.);
}
