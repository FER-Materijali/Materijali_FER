#include<stdio.h>
int main (void) {
int n, max1=0, max2=0, ispravnih=0;
scanf("%d", &n);
while (n>=0 && n<=100) {
      ++ispravnih;
      if (n>max1) {
	  	max1=n;
	  } else if (n>max2) {
	  	max2=n;
	  }
	  scanf("%d", &n);
}
if (ispravnih>1) {
	 printf("Ostatak pri dijeljenju %d sa %d je %d.", max1, max2, max1%max2);
} else {
	printf("Nije uneseno dovoljno brojeva iz trazenog intervala");
}  
return 0;
}