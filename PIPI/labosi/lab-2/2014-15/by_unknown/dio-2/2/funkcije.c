#include"funkcije.h"
#define A 9001
#define C 29
#define M 225
static unsigned int x0=1;
void setSeed (unsigned int seed) {
	x0=seed;
}
unsigned int getRand (void) {
    x0=(A*x0+C)%M;
	return x0;
}