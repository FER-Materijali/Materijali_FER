#include <stdio.h>
int main(){
char polje[8][8];
int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(i % 2 != j % 2)
                polje[i][j] = 'X';
                else
					polje[i][j] = ' ';
		}
	}
	for(i = 0; i < 8; i++)
		polje[6][i] = 'P';
	for(i = 0; i < 8; i++){
		printf("%d", 8 - i);
		for(j = 0; j < 8; j++)
			printf("%c", polje[i][j]);
		printf("\n");
	}
	printf(" ");
	for(i = 0; i < 8; i++)
		printf("%c", i + 65);
	return 0;
}