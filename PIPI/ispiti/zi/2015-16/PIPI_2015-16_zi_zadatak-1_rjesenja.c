#include <stdio.h>

void funkcija(char *polje, int red, int stup, int brred, int brstup){
	int i, j, dokudred, dokudstup;
	for(i=0; i<brred; ++i)
		for(j=0; j<brstup; ++j)
			*(polje+i * brstup + j)='-';
	for(i=0; i<red; ++i)
		for(j=0; j<stup; ++j)
			*(polje+i * brstup + j)='#';
	dokudred=red+1;
	dokudstup=stup+1;
	for(i=dokudred; i<brred; ++i)
		for(j=dokudstup; j<brstup; ++j)
			*(polje+i * brstup + j)='#';
	*(polje+red * brstup + stup)='X';
}

int main (void){
	char polje[8][8], i, j;
	funkcija(polje, 5, 4, 8, 8);
	for(i=0; i<8; ++i){
		for(j=0; j<8; ++j)
			printf("%d ", polje[i][j]);
		printf("\n");
	}
	return 0;
}