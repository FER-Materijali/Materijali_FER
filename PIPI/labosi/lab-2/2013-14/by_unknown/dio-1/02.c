#include<stdio.h>
#include<string.h>
#define MAX 60
#define MIN 10

int main(void){

			char x[MAX+1];
			int i=0;
			memset(x, '\0', MAX);
			printf("Upisi niz:");
			gets(x);
			if(x[MIN-1]=='\0'){
							printf("\nPrekratak niz.");
							return 0;
			}
			while(x[i]!='\0'){
							if((x[i]>='a') && (x[i]<='z')){
															printf("\n%c", x[i]);
							}
			i+=2;
			}
			return 0;
}