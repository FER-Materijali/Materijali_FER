#include <stdio.h>

char *odrediExt(char *ime) {
	char *pom = NULL;
	if(ime == NULL)
		return NULL;
	do {
		if(*ime == '.')
			pom = ime + 1;
		ime++;
	} while(*ime != '\0');
	return pom;
}

int main (void){
	int i;
	char *ext, polje[100+1];
	gets(polje);
	ext=odrediExt(polje);
	if(ext!=NULL)
		puts(ext);
	else
		printf("dat nema ext");
	return 0;
}