#include"funkcije.h"
#include<stdio.h>
						
int main(void){

			unsigned int seed=0, l=0, i=0;
			while(1){
					printf("Upisite sjeme:");
					scanf("%u", &seed);
					if(seed==0) break;
					setSeed(seed);
					l=getRand();
					while(l!=0){
								l-=1;
								while(1){
										i=getRand();
										if(((i>='A') && (i<='Z')) || ((i>='a') && (i<='z')) || (i==' ') || (i==',')){
																													printf("%c", i);
																													break;
										}
								}
					}
					printf(".\n");
			}
			return 0;
}