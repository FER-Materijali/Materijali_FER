#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

int main(){

	int i, n, flag = 0;
	int polje[MAX];
	
	srand((unsigned) time(NULL));
	
	for(i = 0; i < MAX; i++)
		polje[i] = rand() % 99 + 1;
		
	do{
	
		printf("Unesite jedan broj\n");
		scanf("%d", &n);
		
		for(i = 0; i < MAX; i++)
			if(polje[i] == n)
				flag = 1;
	
	}while(!flag);

	printf("Generirani su brojevi:");
	
	for(i = 0; i < MAX; i++)
		printf(" %d", polje[i]);
		
	return 0;
}