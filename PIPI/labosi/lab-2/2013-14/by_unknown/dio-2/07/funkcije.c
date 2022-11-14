#include"funkcije.h"
#include<stdio.h>
#include<string.h>

int br_odlomaka(char *tekst){
							int i=0, n=1;
							for(i=0;i<strlen(tekst);++i){
														if(tekst[i+1]=='\n'){
																		if((tekst[i]=='.') || (tekst[i]=='!') || (tekst[i]=='?')) n+=1;
														}
							}
							return n;
}

int br_rijeci(char *tekst){
						int i=0, n=0;
						if(tekst[0]=='\0') return 0;
						for(i=0;i<strlen(tekst);++i){
													if((((tekst[i]>='A') && (tekst[i]<='Z')) || ((tekst[i]>='a') && (tekst[i]<='z')) || ((tekst[i]>='0') && (tekst[i]<='9')) || ((tekst[i]>='"') && (tekst[i]<='+')) || (tekst[i]=='-') || (tekst[i]=='/') || ((tekst[i]>=':') && (tekst[i]<='>')) || ((tekst[i]>='[') && (tekst[i]<='`')) || ((tekst[i]>='{') && (tekst[i]<='~'))) && ((tekst[i+1]=='.') || (tekst[i+1]=='!') || (tekst[i+1]=='?') || (tekst[i+1]==' ') || (tekst[i+1]==','))) n+=1; 
						}
						return n;
}