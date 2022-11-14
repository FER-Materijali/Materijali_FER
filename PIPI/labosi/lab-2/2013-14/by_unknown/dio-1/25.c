#include<stdio.h>
#include<string.h>
#define MAX 5
							
int main(void){

			char s[MAX+1];
			int i=0;
			memset(s, '\0', MAX);
			printf("Upisi oktalni broj:");
			gets(s);
			for(i=0;i<strlen(s);++i){
								if((s[i]<'0') || (s[i]>'7')){
														printf("\nUcitani niz nije ispravno zadan.");
														return 0;
								}
			}
			printf("\nPrva znamenka ucitanog broja je %c.", s[0]);
			printf("\nPosljednja znamenka ucitanog broja je %c.", s[strlen(s)-1]);
			return 0;
			
			
			
			
}