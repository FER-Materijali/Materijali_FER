#include<stdio.h>
#include<string.h>
#define MAX 30
							
int main(void){

			char s[MAX+1];
			int i=0, l=0;
			memset(s, '\0', MAX);
			printf("Upisi niz:");
			gets(s);
			l=strlen(s);
			for(i=0;i<l;++i){
							if(((s[i]<'0') || (s[i]>'9')) && ((s[i]<'A') || (s[i]>'Z')) && ((s[i]<'a') || (s[i]>'z'))){
																													printf("\nUcitani niz nije ispravno zadan.");
																													return 0;
																													}
			}
			printf("\nOriginalni niz:  %s", s);
			for(i=0;i<l;++i){
							if(s[i]=='a') s[i]='9';
							else if(s[i]=='e') s[i]='8';
							else if(s[i]=='i') s[i]='7';
							else if(s[i]=='o') s[i]='6'; /* linija 24 dodana zato sto je u zadatku primijeceno da se 'o' mijenja u '6' */
			}
			printf("\nIzmijenjeni niz: %s", s);
			return 0;
}