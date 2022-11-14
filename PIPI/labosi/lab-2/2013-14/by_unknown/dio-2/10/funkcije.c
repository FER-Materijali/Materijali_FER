#include"funkcije.h"
#include<stdio.h>
#include<string.h>

int brojPonavljanja(char niz[], char znak){
										int i=0, br=0;
										for(i=0;i<strlen(niz);++i){
																if(niz[i]==znak) break;
										}
										while(niz[i]==znak){
															br+=1;
															i+=1;
										}
										return br;
}

void kodiraj(char src[], char dest[]){
									int i=0, j=0, n=0;
									for(i=0;i<strlen(src);i+=n){
															n=brojPonavljanja(&src[i], src[i]);
															dest[j++]=src[i];
															dest[j++]=n+'0';
									}
}