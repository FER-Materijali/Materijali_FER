// RazneSlozenosti.c
// Kubni, kvadraticni, NlogN ili linearni algoritam
#include <stdio.h>
#include <stdlib.h>

// vraca niz znakova c u zadanoj duljini n
char* nc (int c, int n) {
	static char s[80+1];
	s[n] = '\0';								// prirubi
  while (--n >= 0) s[n] = c;	// popuni
	return s;
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


// Kubna slozenost
int MaxPodSumaNiza3 (int A[], int N) {
	int OvaSuma, MaxSuma, i, j, k;
	int iteracija = 0;
	MaxSuma = 0;
	for (i = 0; i < N; i++) {
		printf ("i=%d\n", i);
		for (j = i; j < N; j++) {
			OvaSuma = 0;
			for (k = i; k <= j; k++) {
				OvaSuma += A [k];
				++iteracija;
			}
			if (OvaSuma > MaxSuma) MaxSuma = OvaSuma;
			printf ("Suma clanova [%d, %d] = %d, a najveca = %d\n", 
										i, j, OvaSuma, MaxSuma);
		}
	}
	printf ("Broj iteracija: %d\n", iteracija);
	return MaxSuma;
}

// Kvadratna slozenost
int MaxPodSumaNiza2 (int A[ ], int N) {
	int OvaSuma, MaxSuma, i, j;
	int iteracija = 0;
	MaxSuma = 0;
	for (i = 0; i < N; i++) {
		printf ("i=%d\n", i);
		OvaSuma = 0;
		for (j = i; j < N; j++) {
			OvaSuma += A[ j ];
			++iteracija;
			if (OvaSuma > MaxSuma) MaxSuma = OvaSuma;
			printf ("Suma clanova [%d, %d] = %d, a najveca = %d\n", 
										i, j, OvaSuma, MaxSuma);
		}
	}
	printf ("Broj iteracija: %d\n", iteracija);
	return MaxSuma;
}
// NlogN slozenost - koristi funkcije max3 i MaxPodSuma
// racuna najveci od 3 broja
int Max3 (int A, int B, int C) {
	return A > B ? A > C ? A : C : B > C ? B : C;
}
// trazi najvecu podsumu clanova od Lijeva do Desna
int MaxPodSuma (int A[], int Lijeva, int Desna, int dubina) {
	int MaxLijevaSuma, MaxDesnaSuma;
	int MaxLijevaRubnaSuma, MaxDesnaRubnaSuma;
	int LijevaRubnaSuma, DesnaRubnaSuma;
	int Sredina, i, ret;
	printf ("%s> MaxPodSuma(%d, %d) ...\n", 
					 nc(' ', dubina*2), Lijeva, Desna);
	if (Lijeva == Desna) { // Osnovni slucaj
	  if (A [Lijeva] > 0)
		  ret = A [Lijeva]; // podniz od clana A[Lijeva]
	  else
		  ret = 0; // suma je 0 ako su svi brojevi negativni
    printf ("%s< MaxPodSuma(%d, %d) = %d\n", 
			       nc(' ', dubina*2), Lijeva, Desna, ret);
	return ret;
	}
	// racun lijeve i desne podsume s obzirom na Sredina
	Sredina = (Lijeva + Desna) / 2;
	MaxLijevaSuma = MaxPodSuma (A, Lijeva, Sredina, dubina+1);
	MaxDesnaSuma = MaxPodSuma (A,Sredina + 1, Desna, dubina+1);
	// najveca gledano ulijevo od sredine
	MaxLijevaRubnaSuma = 0; LijevaRubnaSuma = 0;
	for (i = Sredina; i >= Lijeva; i--) {
		LijevaRubnaSuma += A [i];
		if (LijevaRubnaSuma > MaxLijevaRubnaSuma)
			MaxLijevaRubnaSuma = LijevaRubnaSuma;
	}
	// najveca gledano udesno od sredine
	MaxDesnaRubnaSuma = 0; DesnaRubnaSuma = 0;
	for (i = Sredina + 1; i <= Desna; i++) {
		DesnaRubnaSuma += A [i];
		if (DesnaRubnaSuma > MaxDesnaRubnaSuma)
		MaxDesnaRubnaSuma = DesnaRubnaSuma;
	}
	printf ("%s  Lijeva=%d Desna=%d Rubna=%d\n", 
				nc (' ', dubina*2), MaxLijevaSuma, MaxDesnaSuma,
				MaxLijevaRubnaSuma + MaxDesnaRubnaSuma);
	// najveca od lijeva, desna, rubna
	ret = Max3 (MaxLijevaSuma, MaxDesnaSuma,
		          MaxLijevaRubnaSuma + MaxDesnaRubnaSuma);
  	printf ("%s< MaxPodSuma(%d, %d) = %d\n", 
			       nc(' ', dubina*2), Lijeva, Desna, ret);
	return ret;
}
// NlogN slozenost
int MaxPodSumaNizaLog (int A [], int N) {
	return MaxPodSuma (A, 0, N - 1, 0);
}
// Linearna složenost
int	MaxPodSumaNiza1 (int A[], int N) {
	int OvaSuma, MaxSuma, j;
	OvaSuma = MaxSuma = 0;
	for (j = 0; j < N; j++) {
		OvaSuma += A[ j ];
		if (OvaSuma > MaxSuma) MaxSuma = OvaSuma;
		else if (OvaSuma < 0) OvaSuma = 0;	
		printf ("j=%d OvaSuma=%2d MaxSuma=%2d\n", 
			       j, OvaSuma, MaxSuma);
	}
	return MaxSuma;
}

int main (void) {
	int A [] = {4, -3, 5, -2, -1, 2, 6, -2};
	int rez;

	printf("\n\nKubna slozenost\n");
	ispisi(A, sizeof (A) / sizeof (A [0]));
	rez = MaxPodSumaNiza3 (A, sizeof (A) / sizeof (A [0]));
	printf("\nMaxSuma3 = %d", rez);

	printf("\n\nKvadratna slozenost\n");
	ispisi(A, sizeof (A) / sizeof (A [0]));
	rez = MaxPodSumaNiza2 (A, sizeof (A) / sizeof (A [0]));
	printf("\nMaxSuma2 = %d", rez);

	printf("\n\nLogaritamska slozenost\n");
	ispisi(A, sizeof (A) / sizeof (A [0]));
	rez = MaxPodSumaNizaLog (A, sizeof (A) / sizeof (A [0]));
	printf("\nMaxSumaLog = %d", rez);
	
	printf("\n\nLinearna slozenost\n");
	ispisi(A, sizeof (A) / sizeof (A [0]));
	rez = MaxPodSumaNiza1 (A, sizeof (A) / sizeof (A [0]));
	printf("\nMaxSuma1 = %d\n", rez);
	
	return 0;
}
