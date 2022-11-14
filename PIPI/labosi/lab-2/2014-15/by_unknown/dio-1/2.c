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
    i=0;
	while (x[i]!='\0') {
		if (x[i]>='a' && x[i]<='z') {
			printf("%c\n", x[i]);
		}
		i+=2;
	}
}
	return 0;
}