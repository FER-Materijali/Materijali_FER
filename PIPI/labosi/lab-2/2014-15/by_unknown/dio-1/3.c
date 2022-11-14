#include<stdio.h>
int main (void) {
char x[61];
int i=0, brojac=0;
gets (x);
while (x[i]!='\0') {
	++i;
	++brojac;
}
if (brojac<10) {
	printf("Prekratak niz");
} else {
   for (i=brojac-1; i>=0; --i) {
   	if (x[i]>='A' && x[i]<='Z' || x[i]>='0' && x[i]<='9') {
		printf("%c\n", x[i]);
	}
   }
   
}
	return 0;
}