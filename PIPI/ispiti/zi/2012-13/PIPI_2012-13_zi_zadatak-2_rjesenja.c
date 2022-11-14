#include <stdio.h>
#define MAX 30

int sifriraj(char *poruka, char *otp, int r, int s, int maxstup){
	int i,j;
	for (i=0; i<r; i++)
		for (j=0; j<s; j++)
			poruka[i*maxstup+j]^=otp[i*maxstup+j];
	return 0;
}

int main (void){
	FILE *ul, *il;
	int brred, brstup, brznak;
	ul=fopen("otp.bin", "rb");
	il=fopen("poruka.bin", "rb");
	fread(&brred, sizeof(int), 1, ul);
	fread(&brstup, sizeof(int), 1, ul);
	