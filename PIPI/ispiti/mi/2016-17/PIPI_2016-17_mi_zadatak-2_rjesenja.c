#include <stdio.h>

int main (void){
	char niz[100+1], ispis[100+1];
	int i, j;
	printf("ulazni niz: ");
	gets(niz);
	i=0;
	j=0;
	while(niz[j]!='\0'){
		if(i%2==0){
			if(niz[j]>='A' && niz[j]<='Z'){
				ispis[i]=niz[j];
				++i;
			}
		}
		else{
			if(niz[j]>='a' && niz[j]<='z'){
				ispis[i]=niz[j];
				++i;
			}
		}
		++j;
	}
	ispis[i]='\0';
	printf("novi niz: %s\n", ispis);
	printf("stari niz: %s", niz);
	return 0;
}