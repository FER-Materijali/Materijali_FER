#include <stdio.h>
//#include <stdlib.h>
#define MAX 20

int main(){
	int n, i, suma=0;
	char niz[MAX];

	printf("Unesi n iz intervala [10,20]: ");
	scanf("%d",&n);
	
	if(n<10 || n>20) return 0;

	/*
	if (n<10 || n>20) exit (1);
	*/

	for(i=0;i<n;++i){
		printf("\nUnesi %2d. znak: ", i+1);
		niz[i] = getche();
		if((niz[i]>='0') && niz[i]<='9') 
			if (niz[i]%2 == 0) suma += niz[i]-'0';
	}
	printf("\n\nSuma parnih znamenaka iznosi: %d\n\n", suma);
	return 0;
}