#include<stdio.h>
#include<string.h>
#define MAX 20
							
int main(void){

			char s[MAX+1], c='\0';
			int i=0, l=0;
			memset(s, '\0', MAX);
			printf("Upisi niz:");
			gets(s);
			l=strlen(s);
			for(i=0;i<l;++i){
							if(((s[i]<'0') || (s[i]>'9')) && ((s[i]<'A') || (s[i]>'Z')) && ((s[i]<'a') || (s[i]>'z'))) c=s[i];
			}
			for(i=0;i<l;++i){
							if((s[i]>='a') && (s[i]<='z')){
														s[l-1]=s[i];
														s[i]=c;
														break;
							}
			}
			printf("\n");
			puts(s);
			return 0;
}