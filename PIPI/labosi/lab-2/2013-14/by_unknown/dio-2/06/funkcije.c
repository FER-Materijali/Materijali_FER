#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 100

int brojNeSlova(char *niz){
						int i=0, n=0;
						for(i=0;i<strlen(niz);++i){
												if(((niz[i]<'A') || (niz[i]>'Z')) && ((niz[i]<'a') || (niz[i]>'z'))) n+=1;
						}
						return n;
}

void caesarEncrypt(char *nizUlaz, char *nizIzlaz, int kljucKriptiranja){
																		int i=0;
																		for(i=0;i<strlen(nizUlaz);++i){
																									if((((nizUlaz[i]+kljucKriptiranja)>'Z') && ((nizUlaz[i]+kljucKriptiranja)<'a')) && (((nizUlaz[i]+kljucKriptiranja)<'z') || ((nizUlaz[i]+kljucKriptiranja)>='z'))) nizIzlaz[i]=(nizUlaz[i]+kljucKriptiranja)-26;
																									else if((nizUlaz[i]+kljucKriptiranja)>='z') nizIzlaz[i]=(nizUlaz[i]+kljucKriptiranja)-26;
																									else nizIzlaz[i]=nizUlaz[i]+kljucKriptiranja;
																		}
}