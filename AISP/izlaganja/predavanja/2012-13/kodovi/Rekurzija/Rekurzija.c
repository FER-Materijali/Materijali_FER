// Rekurzija.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXA 10

// ispis znaka c u zadanoj duljini n
void nznak (int c, int n) {
  while (--n >= 0) putchar(c);
}  
// ispis polja
void ispisi(int A[], int n) {
	int i;
	printf("\n");
	for (i = 0; i < n; i++) printf(" A[%d]",i);
	printf("\n");
	for (i = 0; i < n; i++) printf("%5d", A[i]);
	printf("\n");
}
// Rekurzivno trazenje indeksa clana u polju
int trazi (int A[], int x, int n, int i) {
	// A-polje x-trazeni i-indeks od kojeg se trazi
	int ret;
	nznak(' ', i*5); printf("^^^^^\n");
	if (i >= n) ret = -1;					
	else if (A[i] == x) ret = i;		
	else ret = trazi (A, x, n, i+1);	
	nznak(' ', i*5); printf("%5d\n", ret);
	return ret;
}
// Rekurzivno trazenje indeksa clana u polju s ogranicivacem
int trazi1 (int A[], int x, int i){
	int ret;
	nznak(' ', i*5); printf("^^^^^\n");
	if(A[i] == x)	ret = i;			
	else ret= trazi1 (A, x, i+1);	
	nznak(' ', i*5); printf("%5d\n", ret);
	return ret;
}

// Drugi rekurzivni nacin bez ogranicivaca
int trazi2 (int A[], int x, int n){
    if (n < 1) return 0;    // Ako element ne postoji, vratiti æe indeks n
    if (A[0] == x) return 0;
    return 1 + trazi2(&A[1], x , n-1);
}


// Rekurzivno trazenje najveceg clana polja
int maxclan (int A[], int i, int n) {
	int imax;
	if (i >= n-1) return n-1;
	imax = maxclan (A, i + 1, n);
	if (A[i] > A[imax]) return i;
	return imax;
}

// Rekurzivno trazenje najveceg clana polja - strukturirano
int maxclan1 (int A[], int i, int n) {
	int imax, ret;
	printf ("max(%d) -> ", i);
	if (i >= n-1) {
		printf ("\n");
		ret = n-1;
	} else {
		imax = maxclan1 (A, i + 1, n);
		if (A[i] > A[imax])
			ret = i;
		else 
			ret = imax;
	}
	printf ("<- max(%d)=%d ", i, ret);
	return ret;
}
// macro naredba za vecu od dvije vrijednosti
#define maxof(a,b) ((a) > (b) ? (a) : (b))

// Funkcija s macro naredbom 
// koja vraca vrijednost najveceg clana
int maxclan2 (int A[], int i, int n) {
	int m;
  if (i >= n-1) return A[i];
	m = maxclan2 (A, i + 1, n);
  return maxof(A[i], m);
}
// Primjer neispravne rekurzije
int los (int n, int *dubina) {
	int r;
	(*dubina)++;
 	printf ("n = %d, dubina rekurzije = %d\n", n, *dubina);
	if (n == 0)
		r = 0;
	else
		r = los (n / 3 + 1, dubina) + n - 1;
  return r;
}
int main () {
	int A[MAXA], x, i, n, dubina;
	FILE *fi;
	fi = fopen ("UlazZaTrazenje.txt", "r");
	if (!fi) return 1;
	n = 0;
	while (n < MAXA - 1 && fscanf (fi, "%d", &A[n]) != EOF)	n++;
	fclose (fi);
	ispisi (A, n);
	printf ("Upisite vrijednost za x =");
	scanf ("%d", &x);
	printf ("\nRekurzivno trazenje indeksa clana\n");
	ispisi (A, n);
	if ((i = trazi (A, x, n, 0)) < 0)
		printf ("Vrijednost %d ne postoji u polju\n", x);
	else
		printf ("A [%d] = %d\n", i, A [i]);
	printf ("\nRekurzivno trazenje ... s ogranicivacem\n");
	A [n] = x;  // postavljanje ogranicivaca
	ispisi (A, n+1);
	if ((i = trazi1 (A, x, 0)) == n) 
		printf ("Vrijednost %d ne postoji u polju", x);
	else 
		printf ("A [%d] = %d\n", i, A [i]);

    printf("\nTraženje na treci nacin:\n");
    if ((i = trazi2(A, x, n)) == n) {
        printf ("Vrijednost %d ne postoji u polju", x);
    }
    else {
        printf ("A [%d] = %d\n", i, A [i]);
    }

	printf ("\nRekurzivno trazenje najveceg...\n");
	ispisi(A, n);
	if ((i = maxclan (A, 0, n)) != maxclan1 (A, 0, n)) {
		printf ("Pogreska: Strukturirana i nestrukturirana funkcija daju razlicite rezultate!\n");
		return 1;
	}
	printf ("\nNajveci clan A [%d] = %d\n",i, A [i]);
	printf ("Funkcija s macro naredbom je nasla najveci clan %d\n", maxclan2 (A, 0, n));
	printf ("\nPozivam neispravnu rekurziju\n");
	while (1) {
		dubina = 0;
		printf ("Upisite vrijednost za n =");	// primjer: n=4
		scanf ("%d", &n);
		i = los (n, &dubina);
		printf ("\ni = %d", i);
	}
}
