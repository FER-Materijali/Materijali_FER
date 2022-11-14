#include<stdio.h>
#include"funkcije.h"
int main(void) {
	int sekunde, h, m, s;
	char vrijeme[9]={'\0'}, tmp[4]={'\0'};
	scanf("%d", &sekunde);
	hms(sekunde, &h, &m, &s);
	intUNiz(h, tmp);
	dodajNiz(tmp, ":");
	dodajNiz(vrijeme, tmp);
	intUNiz(m, tmp);
	dodajNiz(tmp, ":");
	dodajNiz(vrijeme, tmp);
	intUNiz(s, tmp);
	dodajNiz(vrijeme, tmp);
	printf("%s\n", vrijeme);
	return 0;
}