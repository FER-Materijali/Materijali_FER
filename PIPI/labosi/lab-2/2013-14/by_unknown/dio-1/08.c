#include<stdio.h>
#include<string.h>
#define MAX 30
				
int main(void){

			char s[MAX+1];
			int i=0, p[2]={0};
			memset(s, '\0', MAX);
			printf("Upisi niz znakova:");
			gets(s);
			for(i=0;i<=strlen(s);++i){
									if((s[i]>='a') && (s[i]<='z')) p[0]+=1;
									if((s[i]>='0') && (s[i]<='9')) p[1]+=1;
			}
			if((p[0]>=7) && (p[1]>=2)){
										printf("\nZadovoljava uvjete.");
			}else{
				printf("\nNe zadovoljava uvjete.");
			}
			return 0;
}