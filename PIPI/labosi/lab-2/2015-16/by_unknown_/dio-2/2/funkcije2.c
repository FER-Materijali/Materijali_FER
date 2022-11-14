#include <stdio.h>
#define A 9001
#define C 29
#define M 225

static unsigned int x0 = 1;

void setSeed(unsigned int broj)
{
	x0 = broj;
}

unsigned int getRand(void)
{
	x0 = (A * x0 + C) % M;
	return x0;
}