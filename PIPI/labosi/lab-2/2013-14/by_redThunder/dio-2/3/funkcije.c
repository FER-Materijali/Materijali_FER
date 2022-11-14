#include "funkcije.h"
#include <stdio.h>

int search( int *niz, int n, int elem ){
	/* traženje elementa u nizu */
	int i;
	for( i=0; i<n; i++ ){
		if ( niz[i] == elem ) return 1;
	}
	return 0;
}

void sort( int *niz, int n ){
	int tmp, i, j;
	for( i=0; i<n; i++ ){
		for( j=i+1; j<n; j++ ){
			if ( niz[i] > niz[j] ){
				tmp = niz[i];
				niz[i] = niz[j];
				niz[j] = tmp;
			}
		}
	}
}

int ucitaj( int *skup ){
	int n=0,x;
	do{
		scanf("%d",&x);
		if (x<0) break;
		if ( !search(skup,n+1,x) ) skup[n++] = x;
	}while(1);
	sort(skup,n);
	return n;
}

void unija( int n1, int *s1, int n2, int *s2, int nrez, int *rez ){
	int i=0, j=0, k=0;
	
	/*merge sort*/
	while( 1 ){
		if ( n1 == i && n2 == j ) break;
		if ( n1 == i ) { rez[k++]=s2[j++]; continue; }
		if ( n2 == j ) { rez[k++]=s1[i++]; continue; }
		if ( s1[i] == s2[j] ){
			rez[k++] = s1[i++];
			j++;
			continue;
		}
		if ( s1[i] < s2[j] ) rez[k++] = s1[i++]; else rez[k++] = s2[j++];
	}

	printf("Unija: ");
	for( i=0; i<k; i++ ) printf("%d ", rez[i]);
	printf("\n");
}

int je_podskup( int npodskup, int *podskup, int nskup, int *skup ){
	int i=0,j=0;

	while( i<npodskup ){
		if ( podskup[i] < skup[j] ) return 0;
		else if ( podskup[i] == skup[j] ) { 
			i++; j++; 
		} else j++;
	}
	return 1;
}