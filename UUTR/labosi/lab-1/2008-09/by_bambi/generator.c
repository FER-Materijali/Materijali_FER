#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int tAZmin, tAZmax, tPZmin, tPZmax, nP, nA, tACZ, tAZ, tACPC;
	int acpcp, acz, azmin, azmax, az, acpca, pzmin, pzmax;
	int i, j, brstanja, pomocna1, pomocna2, pomocna3;
	FILE *automat;
	
	if(argc!=10) {
		printf("Niste unijeli sve argumente!\n");
		exit(1);
	}
	
	tAZmin=atoi(argv[1]);
	tAZmax=atoi(argv[2]);
	tPZmin=atoi(argv[3]);
	tPZmax=atoi(argv[4]);
	nP=atoi(argv[5]);
	nA=atoi(argv[6]);
	tACZ=atoi(argv[7]);
	tAZ=atoi(argv[8]);
	tACPC=atoi(argv[9]);
	
	automat=fopen("automat.txt", "w");
	
	acpcp=tACPC*(nP+1);
	acz=tACZ*(nP+1);
	azmin=tAZmin*(nP+1);
	azmax=(tAZmax-tAZmin)*nP;
	az=tAZ*(nA+1);
	acpca=tACPC*(nA+1);
	pzmin=tPZmin*(nA+1);
	pzmax=(tPZmax-tPZmin)*nA;
	
	brstanja=acpcp+acz+azmin+azmax+az+acpca+pzmin+pzmax;
	
	for(i=1; i<=brstanja; i++) {
		
		if(i>0 && i<acpcp+acz+azmin) {
			fprintf(automat, "%d ", i);
			fprintf(automat, "%d ", i+nP+1);
			if(i%(nP+1)!=0) fprintf(automat, "%d ", i+1);
			else fprintf(automat, "%d ", i);
			fprintf(automat, "%d ", i);
			if(i<=acpcp) fprintf(automat, "ACPC\n");
			if(i>acpcp && i<=acpcp+acz) fprintf(automat, "ACZh\n");
			if(i>acpcp+acz) fprintf(automat, "AZ\n");
		}
		
		if(i==acpcp+acz+azmin) {
			fprintf(automat, "%d ", i);
			fprintf(automat, "%d ", i+(tAZmax-tAZmin)*nP+1);
			fprintf(automat, "%d %d ", i, i);
			fprintf(automat, "AZ\n");
			pomocna1=i;
		}
		
		if(i>acpcp+acz+azmin && i<=acpcp+acz+azmin+azmax) {
			fprintf(automat, "%d ", i);
			if(i<pomocna1+azmax-nP+1) {
				fprintf(automat, "%d ", i+nP);
				if((i-pomocna1)%nP!=0) fprintf(automat, "%d ", i+1);
				else fprintf(automat, "%d ", pomocna1);
				fprintf(automat, "%d ", i);
			}
			else {
				fprintf(automat, "%d ", pomocna1+azmax+1);
				if((i-pomocna1)%nP!=0) fprintf(automat, "%d ", i+1);
				else fprintf(automat, "%d ", pomocna1);
				fprintf(automat, "%d ", i);
			}
			fprintf(automat, "AZ\n");
		}
		
		pomocna2=acpcp+acz+azmin+azmax;
		
		if(i>acpcp+acz+azmin+azmax && i<acpcp+acz+azmin+azmax+az+acpca+pzmin) {
			fprintf(automat, "%d ", i);
			fprintf(automat, "%d ", i+nA+1);
			fprintf(automat, "%d ", i);
			if((i-pomocna2)%(nA+1)!=0) fprintf(automat, "%d ", i+1);
			else fprintf(automat, "%d ", i);
			if(i<=acpcp+acz+azmin+azmax+az) fprintf(automat, "AZh\n");
			if(i>acpcp+acz+azmin+azmax+az && i<=acpcp+acz+azmin+azmax+az+acpca) fprintf(automat, "ACPC\n");
			if(i>acpcp+acz+azmin+azmax+az+acpca) fprintf(automat, "PZ\n");
		}
		
		if(i==acpcp+acz+azmin+azmax+az+acpca+pzmin) {
			fprintf(automat, "%d ", i);
			fprintf(automat, "%d ", 1);
			fprintf(automat, "%d %d ", i, i);
			fprintf(automat, "PZ\n");
			pomocna3=i;
		}
		
		if(i>acpcp+acz+azmin+azmax+az+acpca+pzmin && i<=brstanja) {
			fprintf(automat, "%d ", i);
			if(i<pomocna3+pzmax-nA+1) {
				fprintf(automat, "%d ", i+nA);
				fprintf(automat, "%d ", i);
				if((i-pomocna3)%nA!=0) fprintf(automat, "%d ", i+1);
				else fprintf(automat, "%d ", pomocna3);
			}
			else {
				fprintf(automat, "%d ", 1);
				fprintf(automat, "%d ", i);
				if((i-pomocna3)%nA!=0) fprintf(automat, "%d ", i+1);
				else fprintf(automat, "%d ", pomocna3);
			}
			fprintf(automat, "PZ\n");
		}
		
	}
	
	printf("Za dane ulazne parametre izgenerirana su stanja i zapisana u datoteku.\n");
	printf("Broj stanja je %d.\n", brstanja);
	
	fclose(automat);
	
	return 0;
}
