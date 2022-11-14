#include <stdio.h>
#include <string.h>
#include "funkcije.h"
#define MAX 300

int main( void ){
	char s1[MAX+1], s2[MAX+1];
	char tmp1[6], tmp2[6];
	int n,i,j,l1,l2,sol=0;
	scanf("%s%s",s1,s2);
	scanf("%d",&n);
	l1 = strlen(s1);
	l2 = strlen(s2);

	for(i=0; i<=l1-n; i++){
		genPodniz(s1,tmp1,i,n);
		for(j=0; j<=l2-n; j++){
			genPodniz(s2,tmp2,j,n);
			sol += nizoviJednaki(tmp1,tmp2);
		}
	}

	printf("Rjesenje je:%lf\n",sol*2./(l1+l2+2-2*n));
	return 0;
}