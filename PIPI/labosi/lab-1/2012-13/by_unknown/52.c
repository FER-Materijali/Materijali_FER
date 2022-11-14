#include <stdio.h>
#define MAX 5
int main() {
	char znak;
	int i=0, brojac=0, pomocna;
	do{
		scanf("%c", &znak);
		scanf("%c", &pomocna);
		if(znak>='0' && znak<='9' || znak>='A' && znak<='F' || znak>='a' && znak<='f'){
			i++;
			if(znak>='0' && znak<='7')
				brojac++;
		}
		else if(i==0)
			printf("Nije unesen niti jedan broj iz trazenog intervala.\n");
	} while(znak>='0' && znak<='9' || znak>='A' && znak<='F' || znak>='a' && znak<='f');
	if(brojac)
		printf("Broj unesenih oktalnih znamenki: %d\n", brojac);

	return 0;
}
