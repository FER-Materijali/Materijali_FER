#include <stdio.h>
#include <math.h>
#define MAX 30
int main() {
	char niz1[MAX+1], niz2[MAX+1], pomocna=0;
	int i;
	gets(niz1);
	gets(niz2);
	for(i=0; niz1[i]!='\0' && niz2[i]!='\0' && i<MAX; i++) {
		if(i%2==0){
			niz1[i]=niz2[i];
			pomocna++;
		}
	}
	printf("promjenjeni niz: %s\n", niz1);
	printf("Promijenjeno znakova: %d\n", pomocna);

	return 0;
}