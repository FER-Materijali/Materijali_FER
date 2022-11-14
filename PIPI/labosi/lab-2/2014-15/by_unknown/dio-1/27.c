#include<stdio.h>
int main (void) {
int n, min=100, max=0, ispravan=1;
scanf("%d", &n);
if (n<0 || n>100) {
	printf("Nije unesen niti jedan broj iz trazenog intervala");
	ispravan=0;
}
if (ispravan) {
   do {
      if (n%4==0) {
	  	if (n<min) {
			min=n;
		} else if (n>max) {
			max=n;
		}
	  }
	  scanf("%d", &n);
   } while (n>=0 && n<=100);
   printf("Zbroj najveceg (%d) i najmanjeg (%d) unesenog broja djeljivog s 4 je %d.", max, min, max+min);
}
return 0;
}