#include <stdio.h>
#include <math.h>
#define MAX 30
int main() {
	char niz[MAX+1];
	int i, k=0, l=0;
	gets(niz);
		for(i=0; niz[i]!='\0' && i<MAX; i++) {
			if(niz[i]>='a' && niz[i]<='z')
				k++;
			else if(niz[i]>='0' && niz[i]<='9')
				l++;
		}
		if(k>=7 && l>=2)
			printf("Zadovoljava uvjete.\n");
		else
			printf("Ne zadovoljava uvjete.\n");

	
	return 0;
}