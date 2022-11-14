#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxS 20

char *nw(char *niz){
					int i=0;
					for(i=0;i<strlen(niz);i++){ 
											if(niz[i]==' '){
															if(isalpha(niz[i+1])) return &niz[i+1];
											}
					}
					return NULL;
}

void rastavi(char *niz, int brojRijeci, int maxRijeci, int duljinaRijeci, char *polje){
																					int i=0, j=0, k=0;
																					char *p=&niz[0];
																					for(i=0;i<maxRijeci;++i){
																						for(j=0;j<duljinaRijeci;++j){
																													if((*(p+j)==' ') || (*(p+j)=='\0')) break;
																													else *(polje+i*(maxS+1)+j)=*(p+j);
																						}
																					p=nw(p+j);
																					if(p==NULL) return;
																					k+=1;
																					if(k>=brojRijeci) return;
																					}
}

int brojRijeci(char *polje){
							int br=0;
							while(*(polje+br*(maxS+1))!='\0') br+=1;
							return br;
}