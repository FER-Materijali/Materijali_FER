#include<stdio.h>
int main (void) {
int n, suma=0, ispravan=1;
scanf("%d", &n);
if (n<0 || n>100) {
	printf("Nije unesen niti jedan broj iz trazenog intervala");
	ispravan=0;
}
if (ispravan) {
   do {
      if (n<50) {
	  	suma+=n;
	  }
	  scanf("%d", &n);
   } while (n>=0 && n<=100);
   printf("Zbroj svih unesenih brojeva manjih od 50 je %d.", suma);
}
return 0;
}