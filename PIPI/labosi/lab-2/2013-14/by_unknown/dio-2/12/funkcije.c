#include "funkcije.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int analiza(char *s){
					int i=0, j=0, p[26]={0}, l=strlen(s), n1=0, n2=0, x1=0, x2=0;
					for(i=0;i<l;++i) s[i]=toupper(s[i]);
					for(i=0;i<l;++i){
						for(j=0;j<26;++j) if(s[i]==(j+65)) p[j]+=1;
					}
					for(i=0;i<26;++i){
									if(p[i]>=n1){
												n1=p[i];
												x1=i;
									}
					}
					for(i=0;i<26;++i){
									if((p[i]>=n2) && (i!=x1)){
															n2=p[i];
															x2=i;
									}
					}
					if(((x1==0) || (x2==8)) || ((x1==8) || (x2==0))) return 1;
					else if((x1==4) || (x2==4)){
												if((x1==19) || (x2==19)) return 2;
												else if((x1==13) || (x2==13)) return 3;
					}
					return 0;
}