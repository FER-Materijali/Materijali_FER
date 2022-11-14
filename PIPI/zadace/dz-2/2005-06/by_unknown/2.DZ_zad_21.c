#include <stdio.h>
#define MAX 100

int main(){
	int n, i;
	char c[MAX], pom['z'-'a'+1]={0};        //pom[26];

	do{
		printf("Unesi n iz intervala [1,100]: ");
		scanf("%d", &n);
	}while(n<1 || n>100);

	for(i=0;i<n;++i){
		printf("\nUnesi %2d. znak: ", i+1);
		c[i] = getche();
		if(c[i]>='a' && c[i]<='z') pom[c[i]-'a']++;
		if(c[i]>='A' && c[i]<='Z') pom[c[i]-'A']++;
	}

	printf("\n\n");

	for(i=0;i<26;++i) printf("\nSlovo %c pojavljuje se %2d puta.", i+65, pom[i]);
	printf("\n\n");

	return 0;
}
		
