#include <stdio.h>
#define MAX 50

int main(){
	int n, i, zbroj=0;
	char niz[MAX];

	printf("Unesi n iz intervala [1,50]: ");
	scanf("%d", &n);

	if(n<1 || n>MAX) return 0;

	for(i=0;i<n;++i){
		printf("\nUnesi %2d. znak: ", i+1);
		niz[i]=getche();
		if(niz[i]>='0' && niz[i]<='9') zbroj +=niz[i]-'0';
	}
	printf("\n\nIspis ucitanog niza:\n %4d ", zbroj);
	for(i=0;i<n;++i){
		if(niz[i]<'0' || niz[i]>'9')printf("%c", niz[i]);
		else continue;
	}
	printf("\n\n");
	return 0;
}


