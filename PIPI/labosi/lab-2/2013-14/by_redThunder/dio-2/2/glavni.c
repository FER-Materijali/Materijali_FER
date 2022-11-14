#include <stdio.h>
#include <ctype.h>
#include "funkcije.h"

int main( void ){
	unsigned int sjeme, n, tmp;
	
	do{
		printf("Unesite sjeme: ");
		scanf("%u",&sjeme);
		if(!sjeme) return 0;

		setSeed(sjeme);
		n = getRand();

		while(n--){
			while(1){
				tmp = getRand();
				if ( isalpha(tmp) || tmp==',' || tmp==' ' ) { 
					printf("%c",tmp); 
					break; 
				}
			}
		}
		printf(".\n");
	}while(1);
	return 0;
}