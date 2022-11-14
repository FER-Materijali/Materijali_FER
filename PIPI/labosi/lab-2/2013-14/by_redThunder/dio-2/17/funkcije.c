void kvadrat( int *polje, int r, int s, int maxs ){
	int i,j;
	for( i=0; i<r; i++ ){
		for( j=0; j<s; j++ ){
			polje[ i*maxs+j ] *= polje[ i*maxs+j ]; 
		}
	}
}

void minStupac( int *polje, int r, int s, int maxs, int *niz ){
	int i, j, min;
	for( i=0; i<s; i++ ){
		niz[i] = 0;
		min = 100000;
		for( j=0; j<r; j++ ){
			min = ( polje[ j*maxs+i ] < min ? polje[ j*maxs+i ] : min ); 
		}
		niz[i] = min;
	}
}