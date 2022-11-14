#include"funkcije.h"
#include<stdio.h>

char *prviZnak(char *niz1, char *niz2, int a, int *b){
													int i=0, j=0, pom=*b;
													for(i=0;i<a;++i){
														for(j=0;j<*b;++j){
																		if(niz1[i]==niz2[j]){
																							if(j<pom) pom=j;
																							break;
																		}
														}
													}
													if(pom==*b) return NULL;
													else{
														*b=*b-pom;
														return &niz2[pom];
													}
}

int brojRecenica(char *niz2, char *niz1){
										char *a=NULL;
										int d1=0, d2=0, i=0, n=0;
										for(i=0;niz1[i]!='\0';++i) d1+=1;
										for(i=0;niz2[i]!='\0';++i) d2+=1;
										a=niz2;
										while(1){
												a=prviZnak(niz1,a,d1,&d2);
												if(a!=NULL) n+=1;
												else break;
												a+=1;
										}
										return n;
}