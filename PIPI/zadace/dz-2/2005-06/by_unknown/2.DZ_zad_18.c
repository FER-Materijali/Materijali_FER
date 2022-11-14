#include <stdio.h>
#define MAX 40

int main(){
	int n, i, s=0;
	char c[MAX], pom['Z'-'A'+1]={0};        //pom[26];

	do{
		printf("Unesi n iz intervala [1,40]: ");
		scanf("%d", &n);
	}while (n<1 || n>40);

	for(i=0;i<n;++i){
		printf("Unesi %2d. znak: ", i+1);
		c[i]=getche();
		if((c[i]>='A') && (c[i]<='Z')) pom[c[i]-'A']++;
		if((c[i]>='a') && (c[i]<='z')) pom[c[i]-'a']++;
	}

	s = c[0];
	for(i=0;i<n;++i){
		if(c[i]>s) s=c[i];
	}

	if(s==0){
		printf("\n\nMedu unesenim znakovima nema ni jednog slova.\n\n\");
	}
	else printf("\n\nMedu unesenim znakovima najvise se pojavljuje slovo %c.\n\n", s+65);

	return 0;
}