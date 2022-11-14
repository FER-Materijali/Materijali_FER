#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

int main( void ){
	char str[MAX+1];
	int check=0,i;
	scanf("%s",str);
	if (strlen(str)<8){
		printf("Prekratak\n");
		return 0;
	}
	for(i=0;i<strlen(str);i++) check += isalpha(str[i]);
	if (!check){
		printf("Ne sadrzi slovo\n");
		return 0;
	}
	printf("Zadovoljava uvjete\n");
	return 0;
}
