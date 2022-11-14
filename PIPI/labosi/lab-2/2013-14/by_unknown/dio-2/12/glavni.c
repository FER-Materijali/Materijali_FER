#include "funkcije.h"
#include <stdio.h>
#define MAX 1500

int main( void ){
			
			char s[MAX+1]={'\0'};
			int n=0;
			printf("Upisi niz:");
			gets(s);
			n=analiza(s);
			switch(n){
					case 1:
						printf("\nJezik na kojem je tekst vjerojatno napisan je: Hrvatski");
						break;
					case 2:
						printf("\nJezik na kojem je tekst vjerojatno napisan je: Engleski");
						break;
					case 3:
						printf("\nJezik na kojem je tekst vjerojatno napisan je: Njemacki");
						break;
					default:
						printf("\nJezik na kojem je tekst vjerojatno napisan je: Nepoznat");
						break;
			}
			return 0;
}