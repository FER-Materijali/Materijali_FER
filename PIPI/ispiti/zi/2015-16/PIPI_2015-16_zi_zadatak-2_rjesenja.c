#include <stdio.h>
#include <string.h>

void zamijeni(char *znak1, char *znak2){
	char pom;
	pom=*znak1;
	*znak1=*znak2;
	*znak2=pom;
	return;
}

char *trazisamoglas(char *niz){
	return strpbrk(niz, "aeiouAEIOU");
}

int main (void){
	char niz[80+1], *znak1, *znak2;
	gets(niz);
	znak1=trazisamoglas(niz);
	if(znak1!=NULL)
		znak2=trazisamoglas(znak1+1);
	if(znak1!=NULL && znak2!=NULL){
		zamijeni(znak1, znak2);
		printf("rez: %s", niz);
	}
	else
		printf("nema dovoljno samoglasnika");
	return 0;
}