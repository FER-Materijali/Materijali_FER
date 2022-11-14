#include"funkcije.h"
#include<stdio.h>
#include<string.h>

int sazetak(char *ulaz){
						int i=0, s=0, d=0;
						if((ulaz[0]=='\0') || (ulaz[0]==' ')) return 0;
						for(i=0;i<strlen(ulaz);++i){
													if((ulaz[i]=='\0') || (ulaz[i]==' ')) break;
													d+=1;
						}
						for(i=0;i<d;++i) if(ulaz[i]!=' ') s+=(int)ulaz[i];
						return (s%128);
}

void dodajZnak(char *ulaz, int broj){
									*ulaz=(char)broj;
}