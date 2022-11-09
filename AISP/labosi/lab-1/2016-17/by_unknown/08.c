#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char *trim(char *p);

int main(void) {
	int n;
	char *p, c, *rez;
	
	printf("Duljina niza:\n(moze biti veca od stvarne duljine)\n");
	scanf("%d%c", &n, &c);
	
	p = (char *)malloc(sizeof(char) * (n+1));
	if (!p) {
		printf("Nema dovoljno memorije!\n");
		exit(1);
	}
	
	fgets(p, (n+1), stdin);
	
	rez = trim(p);
	printf("%s", rez);
	
	free(p);
	free(rez);
	return 0;
}

char *trim(char *p) {
	char *rez;
	int n, i, indeks = 0;
	
	for(i = 0; *(p + i) != '\0'; i++);
	n = i;
	rez = (char *)malloc(sizeof(char) * (n+1));
	if (!rez) {
		printf("Nema dovoljno memorije!\n");
		exit(2);
	}
	
	for(i = 0; i < n; i++) {
		if (*(p + i) != ' ') {
			*(rez + indeks++) = *(p + i);
		} else {
			*(rez + indeks++) = ' ';
			while(*(p + i + 1) == ' ') {
				i++;
				
			}
		}
	}
	*(rez + indeks++) = '\0';
	rez = (char *)realloc(rez, sizeof(char) * indeks);
	
	return rez;
}