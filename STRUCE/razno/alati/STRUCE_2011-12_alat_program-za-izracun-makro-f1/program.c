#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
	
	int broj = atoi(argv[1]); //kolko ih je
	printf("broj= %d\n",broj);
	
	double brojevi[broj*2];
	
	int i=0;
	for (i=0; i<broj*2; i++){
		sscanf(argv[i+2],"%lf",&brojevi[i]);
		printf("in%d= %lf\n",i+1,brojevi[i]);
	}
	
	double rez = 0;
	for (i=0; i<broj; i++){
		rez += (brojevi[2*i]*brojevi[2*i+1])/(brojevi[2*i]+brojevi[2*i+1]);
	}
	
	rez = (2.0/broj)*rez;
	
	printf("rezultat= %0.4lf\n",rez);
	
	return 0;
}