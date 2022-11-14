#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

int main( void ){
	char str[MAX+1];
	int slova=0,brojke=0,i;
	scanf("%s",str);
	for(i=0;i<strlen(str);i++){
		slova += islower( str[i] );
		brojke += isdigit( str[i] );
	}
	printf("%sadovoljava uvjete\n",(slova>6 && brojke>2) ? "Z" : "Ne z");
	return 0;
}
