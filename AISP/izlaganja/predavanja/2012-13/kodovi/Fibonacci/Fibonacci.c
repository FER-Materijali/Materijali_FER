// Fibonacci.c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Fibonacci izravno
int FI(int n) { 
  int i, fib, f1, f2;
  if (n <= 1) { 
    fib = 1;
	} else {
	f1 = 1; f2 = 1;		// predzadnji i zadnji broj
	for (i = 2; i <= n; i++) {
		fib = f1 + f2;	// novi broj
		if (fib < 0) {	
			printf ("Ne moze se prikazati %d. Fibonaccijev broj!\n", i);
			(void) getch();
			exit (1);
		}
		f1 = f2;				// zadnji postaje predzadnji
		f2 = fib;				// novi postaje zadnji
	}
  }
	return fib;
}
// Fibonacci rekurzivno
int FR(int n, int *brojac) { 
  int fib;
  if (n <= 1) {
    fib = 1; 
  } else {
    fib = FR(n-2, brojac) + FR(n-1, brojac);
	if (fib < 0) {
		printf ("\nNe moze se prikazati %d. Fibonaccijev broj!", n);
		(void) getch();
		exit (1);
	}
  }
  (*brojac) ++; 
  return fib;
}
// F(0) = F(1) = 1
// F(i) = F(i-2)+F(i-1); i>1
int main () {
  int n, brojac, fib;
  while (1) {
    brojac = 0;
    printf("Upisite broj >"); // Primjeri: n=5,40,50
    scanf("%d", &n);
    if (n < 0) {
		printf ("gotovo!\n");	break;
    } else {
		fib = FI (n);
		printf("%d. Fibonaccijev broj = %d , Izravno! \n", n, fib);
		fib = FR(n, &brojac);
		printf("%d. Fibonaccijev broj = %d , Rekurzivno u %d iteracija\n",
														n, fib, brojac);
    }
  }
  return 0;
}
