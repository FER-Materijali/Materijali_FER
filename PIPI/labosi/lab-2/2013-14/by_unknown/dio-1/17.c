#include<stdio.h>
#include<string.h>
#define MAX 30
							
int main(void){

			char s1[MAX+1], s2[MAX+1];
			int i=0, l1=0, br=0;
			memset(s1, '\0', MAX);
			memset(s2, '\0', MAX);
			printf("Upisi prvi niz:");
			gets(s1);
			printf("\nUpisi drugi niz:");
			gets(s2);
			l1=strlen(s1);
			for(i=0;i<l1;++i){
							if(((i%2)==0) && (s2[i]!='\0')){
															s1[i]=s2[i];
															br+=1;
							}
			}
			printf("\nPromijenjeni niz: %s\nPromijenjeno znakova:%2d", s1, br);
			return 0;
}