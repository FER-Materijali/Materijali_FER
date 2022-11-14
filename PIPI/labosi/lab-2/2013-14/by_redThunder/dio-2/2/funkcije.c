#include "funkcije.h"
#define A 9001
#define C 29
#define M 225

static unsigned int x = 1;

void setSeed( unsigned int seed ){
	x = seed;
}

unsigned int getRand( void ){
	x = ( A*x + C ) % M ;
	return x;
}