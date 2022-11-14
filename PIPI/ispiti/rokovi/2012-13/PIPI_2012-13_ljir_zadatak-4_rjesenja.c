#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define BRZAD 6
#define BRODG 4

void ocijeni(char *odg, int brstud, int max, int zad, char *tocan, float *rez){
	int i, j;
	float suma=0;
	char odgovor='\0';
	for(i=0; i<brstud; i++){
		suma=0;
		for(j=0; j<zad; j++){
		    odgovor = odg[i * max + j];
			if(odgovor==tocan[j])
				suma+=1;
			else if(odgovor!=tocan[j] && odgovor!='-')
				suma-=0.5f;	
		}
	rez[i]=suma;
	}
}

int main (void){
	FILE *ul;
	char odg[MAX][BRZAD]={'\0'}, tocan[BRZAD]={'D', 'B', 'C', 'A', 'A', 'C'};
	float rez[MAX]={0.0f};
	int i=0, j;
	ul=fopen("rezultati.txt", "r");
	while(fscanf(ul, "%c %c %c %c %c %c", &odg[i][0], &odg[i][1], &odg[i][2], &odg[i][3], &odg[i][4], &odg[i][5])==6)
		i++;
	fclose(ul);
	ocijeni(&odg[0][0], i, BRZAD, BRZAD, tocan, rez);
	for(j=0; j<i; j++)
		printf("ostvareni rezultat %d. studenda je %g\n", j+1, rez[j]);
	return 0;
}