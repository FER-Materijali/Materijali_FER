#include<stdio.h>
#include<string.h>
#define MAX 20
#define MIN 8
				
int main(void){

			char s[MAX+1];
			int i=0;
			memset(s, '\0', MAX);
			printf("Upisi niz znakova:");
			gets(s);
			for(i=0;i<=strlen(s);++i){
									if(((s[i]>='A') && (s[i]<='Z')) || ((s[i]>='a') && (s[i]<='z'))){
																									i=1;
																									break;
									}
			}
			if(strlen(s)<MIN){
							printf("\nPrekratak.");
							return 0;
			}else if(i==1){
						printf("\nZadovoljava uvjete.");
						return 0;
			}else{
				printf("\nNe sadrzi slovo.");
			}
			return 0;
}