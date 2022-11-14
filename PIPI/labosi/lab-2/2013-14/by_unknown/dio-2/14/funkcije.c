#include"funkcije.h"
#include<stdio.h>
#include<string.h>

int nizUInt(char *niz){
					int i=0, n=0;
					for(i=0;i<strlen(niz);++i){
											if((niz[i]<'0') || (niz[i]>'9')) return -1;
					}
					for(i=0;i<strlen(niz);++i){
											n*=10;
											n+=(niz[i]-48);
					}
					return n;
}

int matemOp(char op, int a, int b, int *rez){
									if(op=='+') *rez=a+b;
									else if(op=='-') *rez=a-b;
									else return 0;
									return 1;
}