#include <stdio.h>

int main (void){
	char niz1[100+1], niz2[100+1], abeceda[26];
	int x, i, j, duljina, duljina2, a, b, slovo, enter;
	scanf("%d %d", &a, &b);
	scanf("%s", &niz1);
	duljina=26;
	for(i=0; i<duljina; ++i)
		abeceda[i]='A'+i;
	abeceda[i+1]='\0';
	puts(abeceda);
	printf("\n");
	duljina2=strlen(niz1);
	for(i=0; i<duljina2; ++i){
		for(j=0; j<duljina; ++j)
			if(niz1[i]==abeceda[j])
				x=j;
		slovo=(a*x+b)%26;
		niz2[i]=slovo+'A';
	}
	puts(niz1);
	printf("\n");
	puts(niz2);
	printf("\n");
	return 0;
}