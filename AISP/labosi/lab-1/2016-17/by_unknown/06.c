#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <stdlib.h>

char *ostaviSlova(char *niz);

int main(void) {
	int n;
	char *p, *r, c;
	
	printf("Duljina niza: ");
	scanf("%d%c", &n, &c);
	p = (char *)malloc(sizeof(char) * (n+1));
	if (!p) {
		printf("Nema dovoljno memorije!\n");
		exit(1);
	}
	
	fgets(p, n+1, stdin);
	
	r = ostaviSlova(p);
	
	printf("%s\n", r);
	
	free(p);
	free(r);
	return 0;
}

char *ostaviSlova(char *niz) {
	int n = 0, i, indeks = 0;
	char *rez;
	
	for (i = 0; *(niz + i) != '\0'; i++) {
		if (isalpha((int)(*(niz + i)))) n++;
	}
	
	rez = (char *)malloc(sizeof(char) * (n+1));
	if(!rez) {
		printf("Nema dovoljno memorije!\n");
		exit(2);
	}
	
	for (i = 0; i < n; i++) {
		for(; !isalpha(*(niz+indeks)); indeks++);
		*(rez + i) = *(niz + indeks++);
	}
	*(rez + n) = '\0';
	
	return rez;
}