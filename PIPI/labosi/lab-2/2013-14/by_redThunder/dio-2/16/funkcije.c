#include "funkcije.h"

int dobreDimenzije( int r, int s, int maxr, int maxs ){
	return (r<=maxr && s<=maxs);
}

void minMax( int *polje, int r, int s, int maxs, int *min, int *max ){
	int i,j;
	for( i=0; i<r; i++ ){
		for( j=0; j<s; j++ ){
			*max = ( *max > polje[maxs*i + j] ? *max : polje[maxs*i + j] );
			*min = ( *min < polje[maxs*i + j] ? *min : polje[maxs*i + j] );
		}
	}
}