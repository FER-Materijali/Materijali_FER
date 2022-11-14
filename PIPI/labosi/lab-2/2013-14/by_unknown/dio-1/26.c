#include<stdio.h>
#include<string.h>
#define MAX 5
							
int main(void){

			char s[MAX+1];
			int i=0;
			memset(s, '\0', MAX);
			printf("Upisi heksadekadski broj:");
			gets(s);
			for(i=0;i<strlen(s);++i){
								if(((s[i]<'0') || (s[i]>'9')) && ((s[i]<'A') || (s[i]>'F')) && ((s[i]<'a') || (s[i]>'f'))){
																														printf("\nUcitani niz nije ispravno zadan.");
																														return 0;
								}
			}
			for(i=0;i<strlen(s);++i){
									if(s[i]>=s[0]) s[0]=s[i];
			}
			printf("\nNajveca heksadekadska znamenka u ucitanom broju je %c.", s[0]);
			return 0;
}