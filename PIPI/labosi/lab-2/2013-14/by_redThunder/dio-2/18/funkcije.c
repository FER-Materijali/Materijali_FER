#include "funkcije.h"

void prosjek( int *polje, int r, int s, int maxs, double *redak, double *stupac ){
	int i,j;

	for( i=0; i<r; i++ ){
		for( j=0; j<s; j++ ){
			redak[i] += (double) polje[ i*maxs+j ] / s;
			stupac[j] += (double) polje[ i*maxs+j ] / r;
		}
	}
}