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
			for(i=MAX;i>-1;--i){
								if(((x[i]>='A') && (x[i]<='Z')) || ((x[i]>='0') && (x[i]<='9'))){
																								printf("\n%c", x[i]);
								}
			}
			return 0;
}