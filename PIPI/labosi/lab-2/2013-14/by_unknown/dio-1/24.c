#include<stdio.h>
#include<string.h>
#define MAX 5
							
int main(void){

			char s[MAX+1];
			int i=0, z=0;
			memset(s, '\0', MAX);
			printf("Upisi oktalni broj:");
			gets(s);
			for(i=0;i<strlen(s);++i){
								if((s[i]<'0') || (s[i]>'7')){
														printf("\nUcitani niz nije ispravno zadan.");
														return 0;
								}
			}
			for(i=0;i<strlen(s);++i){
									if(s[i]=='4') z+=1;
			}
			printf("\nZnamenka 4 se u ucitanom broju pojavljuje %d puta.", z);
			return 0;
}