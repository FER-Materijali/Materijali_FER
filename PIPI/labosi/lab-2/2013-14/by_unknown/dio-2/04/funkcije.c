#include"funkcije.h"
#include<stdio.h>
#include<string.h>

void generirajNiz(char *znakovi, int duljinaNiza, char *genNiz){
																int i=0, lzn=0;
																memset(genNiz, '\0', duljinaNiza);
																lzn=strlen(znakovi);
																if(duljinaNiza<=lzn){
																					for(i=(lzn-duljinaNiza);i<lzn;++i){
																													genNiz[i-(lzn-duljinaNiza)]=znakovi[i];
																					}
																}else{
																	for(i=0;i<duljinaNiza;++i){
																							genNiz[i]=znakovi[i%lzn];
																	}
																}
}

int dobarNiz(char *niz){
						int i=0, j=0, l=0;
						l=strlen(niz);
						for(i=0;i<l;++i){
							for(j=i+1;j<l;++j){
											if(niz[i]==niz[j]) return 0;
							}
						}
						return 1;
}