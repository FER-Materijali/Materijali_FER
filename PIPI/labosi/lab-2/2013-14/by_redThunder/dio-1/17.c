#include <stdio.h>
#include <string.h>
#define MAX 30
#define MIN(a,b) ((a)<(b)?(a):(b))

int main( void ){
	char s1[MAX+1],s2[MAX+1];
	char tmp;
	int i, len;
	scanf("%s%s",s1,s2);
	len = MIN( strlen(s1), strlen(s2) );

	for(i=0; i<len; i+=2){
		tmp = s1[i];
		s1[i] = s2[i];
		s2[i] = tmp;
	}
	
	printf("Promijenjeni niz: %s\nPromijenjeno znakova: %d\n",s1,i/2);
	return 0;
}