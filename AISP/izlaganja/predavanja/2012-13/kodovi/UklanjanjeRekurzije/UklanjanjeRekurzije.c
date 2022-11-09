// UklanjanjeRekurzije.c
#include <stdio.h>
#include <stdlib.h>
#define MAXA 10

// uklonjena rekurzija iz maxclan() u Rekurzija.c
/* originalni algoritam
  if (i >= n-1) return n-1;
  imax = maxclan (A, i + 1, n);
  if (A[i] > A[imax]) return i;
  return imax;

 * pri tom je promijenjen u 
  if (i < n-1) { 
    imax = maxclan (A, i + 1, n);
    if (A[i] > A[imax]) 
		  return i;
		else
		  return imax;
	} else {
	  return n-1;
	}
*/
int maxclan2 (int A[], int i, int n) {
  int imax, k, adresa, vrh, *stog;
  vrh = -1;											//Pravilo  1
  stog = (int *) malloc (2 * n * sizeof(int));
L1:													//Pravilo  2
  if (i < n-1) { 						
	vrh++; stog[vrh] = i;    						//Pravilo  3
    vrh++; stog[vrh] = 2;  							//Pravilo  4
    i++; 											//Pravilo  5
    goto L1;  										//Pravilo  6
L2:													//Pravilo  7
    imax = stog[vrh]; vrh--;				 				
    if (A[i] > A[imax]) { 
      k = i;
    } else {
      k = imax;
    }
  } else {
    k = n-1;
  }
  if (vrh == -1) { 									//Pravilo  8
    free (stog);
    return k;
  } else {											//Pravilo  9 
    adresa = stog[vrh]; vrh--;						//Pravilo 10
    i = stog[vrh]; vrh--;							//Pravilo 11
    vrh++; stog[vrh] = k;							//Pravilo 12
    if (adresa == 2) goto L2;	 					//Pravilo 13
  }
}
// Trazenje najveceg clana iterativno
// Rekurzija je uklonjena intuitivno znajuci redoslijed poziva
// max(0) -> max(1) -> max(2) -> max(3) -> max(4)
// i pitalice if (A[i] > A[imax]) po povratku iz rekurzije
int maxclan3 (int A[], int n) {
	int i, imax;
	i = n-1;
	imax = n-1;
	while (i > 0) {
		i--;
		if (A[i] > A[imax]) imax = i;
	}
	return imax;
}
// Trazenje najveceg clana iterativno
int maxclan4 (int A[], int n) {
	// Vrijedi samo za n > 0
	int i, imax = 0;			// pretpostavimo da je prvi najveci
	for (i = 1; i < n; i++)		// trazimo veci u ostatku polja
		if (A[i] > A[imax])		// da li je trenutni veci?
			imax = i;			// postaje najveci
	return imax;
}
int main () {
  int A[MAXA], n;
	FILE *fi;
	int i;
	fi = fopen ("UlazZaUklanjanjeRekurzije.txt", "r");
	if (!fi) exit (1);
	n = 0;
	while(n < MAXA && fscanf(fi,"%d",&A[n])!= EOF) n++;
	fclose (fi);
	for (i = 0; i < n; i++) printf("\nA [%d] = %d", i, A [i]);
	i = maxclan2 (A, 0, n);
	printf("\nNajveci clan je A [%d] = %d",i, A[i]);
	i = maxclan3 (A, n);
	printf("\nNakon pojednostavnjenja:\nNajveci clan je A [%d] = %d",i, A[i]);
	i = maxclan4 (A, n);
	printf("\nZa n > 0:\nNajveci clan je A [%d] = %d\n",i, A[i]);
	return 0;
}

