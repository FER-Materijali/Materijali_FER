/*
 * mandelbrot.cpp
 *
 *  Created on: 3. tra. 2010.
 *      Author: Goran
 */

#include <cstdio>
#include <math.h>
using namespace std;

int main(int argc, char **argv) {
    int x, y, k;
    float u, v;
    float zre, zim, cre, cim, a, b;

    int eps = 240;
    x = 427;
    y = 100;

    int xmin = 0, ymin = 0;
    int xmax = 800, ymax = 600;

    float umin = -2, umax = -1;
    float vmin = 0.25, vmax = 1;
    int m = 8;

    eps = eps * eps;

    v = (float)ymin * (vmax - vmin)/ymax + vmin;
    u = (float)xmin * (umax - umin)/ xmax + umin;

    cre = u;
    cim = v;
    zre = zim = 0;
    k = -1;
    do {
    	k++;
		a = zre * zre - zim * zim + cre;
		b = 2 * zre * zim + cim;
		zre = a;
		zim = b;
		printf ("%d %f\n", k, sqrt(a*a + b*b));
    } while (a*a + b*b < eps && k < m);


    return 0;
}
