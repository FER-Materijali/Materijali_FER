#include"funkcije.h"
#include<stdio.h>
#include<string.h>

int intUNiz(int broj, char *niz){
								if((broj<0) || (broj>59)) return 0;
								niz[0]=(broj/10)+'0';
								niz[1]=(broj%10)+'0';
								niz[2]=':';
								return 1;
}

char *dodajNiz(char *prvi, char *drugi){
										int i=0, l1=strlen(prvi);
										for(i=0;i<=strlen(drugi);++i) prvi[i+l1]=drugi[i];
										return &prvi[0];
}

void hms(int sekunde, int *h, int *m, int *s){
											*h=sekunde/3600;
											*m=(sekunde/60)%60;
											*s=sekunde%60;
}