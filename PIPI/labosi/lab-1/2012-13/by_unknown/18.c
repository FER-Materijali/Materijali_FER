#include <stdio.h>
#include <math.h>
#define MAX 20
int main() {
	char niz[MAX+1];
	int i, k=0;
	gets(niz);
	for(i=0; niz[i]!='\0' && i<MAX; i++);
	if(i<8)
		printf("Prekratak\n");
	else {
		for(i=0; niz[i]!='\0' && i<MAX; i++) {
			if(niz[i]>='A' && niz[i]<='Z' || niz[i]>='a' && niz[i]<='z')
				k++;
		}
		if(k)
			printf("Zadovoljava uvjete.\n");
		else
			printf("Ne sadrzi slovo.\n");

	}
	return 0;
}
