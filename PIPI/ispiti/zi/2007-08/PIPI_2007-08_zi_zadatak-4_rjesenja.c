#include <stdio.h>
#include <string.h>
#define MAXDIM 20

void razdijeli(char *ulaz, char *razdjelnik, char *prvi, char *drugi){
	
	char *p1 = ulaz; 
	char *p2 = strstr(ulaz, razdjelnik);
	int brojac = 0;

	while(*(p1++) != *razdjelnik)
		brojac++;

	strncpy(prvi, ulaz, brojac);
	strcpy(drugi, p2 + strlen(razdjelnik));
}

int main(){

	char prvi[MAXDIM + 1] = {0}, drugi[MAXDIM + 1] = {0};
	
	razdijeli("http://ahyco.fer.hr/", "://", prvi, drugi);
	
	printf("%s %s", prvi, drugi);
	
	return 0;
}