#include<stdio.h>
#include<string.h>
#define MAX 10
							
int main(void){

			char s[MAX+1];
			int i=0;
			memset(s, '\0', MAX);
			printf("Upisi binarni broj:");
			gets(s);
			for(i=0;i<strlen(s);++i){
								if((s[i]<'0') || (s[i]>'1')){
														printf("\nUcitani niz nije ispravno zadan.");
														return 0;
								}
			}
			for(i=0;i<strlen(s);++i){
									if((s[i]=='0') && (s[i+1]=='0')){
																	printf("\nUcitani binarni broj sadrzi dvije ili vise uzastopnih znamenki 0.");
																	return 0;
									}
			}
			printf("\nUcitani binarni broj ne sadrzi dvije ili vise uzastopnih znamenki 0.");
			return 0;
}