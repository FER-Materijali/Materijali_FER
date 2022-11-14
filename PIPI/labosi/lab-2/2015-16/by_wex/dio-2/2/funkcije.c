#define A 9001
#define C 29
#define M 225

static int x = 1;

void setSeed(unsigned seed) {
	x = seed;
	return;
}

unsigned getRand() {
	x = (A*x + C) % M;
	return x;
}