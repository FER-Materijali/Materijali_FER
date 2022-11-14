#include <stdio.h>
#include <math.h>
#include <complex.h>

#define ZAVOJNICA 0
#define KONDENZATOR 1

#define M_PI 3.14159265358979323846

int main(void){
	int imag = -1;
	double Imaks, alphaI, Umaks, alphaU, omega, R, C, L;
	double complex fZ, fI, fU, fIr, fU12, fU21; /*fazori*/
	
	printf("Upisite I_maks: ");
	scanf("%lf", &Imaks);
	printf("Upisite alpha_I: ");
	scanf("%lf", &alphaI);
	printf("Upisite U_maks: ");
	scanf("%lf", &Umaks);
	printf("Upisite alpha_U: ");
	scanf("%lf", &alphaU);
	printf("Upisite R: ");
	scanf("%lf", &R);
	printf("Upisite kruznu frekvenciju (pise u sinusoidnoj jednadzbi, ne u znanstvenom obliku!): ");
	scanf("%lf", &omega);
	printf("Upisite 0 ako je zavojnica spojena u donjoj grani, ili 1 ako je kondenzator: ");
	scanf("%d", &imag);
	
	/* Racunanje imaginarnog dijela impedancije */
	if (imag == ZAVOJNICA) {		
		printf("Upisite L (u miliH): ");
		scanf("%lf", &L);
		fZ = omega * L * I * 1e-3;
	}
	else {		
		printf("Upisite C (u mikroF): ");
		scanf("%lf", &C);
		fZ = -I * 1/(omega * C * 1e-6);
	}
	
	/* Racunanje efektivnih vrijednosti */
	Imaks = Imaks / sqrt(2);
	Umaks = Umaks / sqrt(2);
	
	/* Prebacivanje iz stupnjeva u radijane */
	alphaI = alphaI * M_PI / 180;
	alphaU = alphaU * M_PI / 180;
	
	/* Odredivanje fazora zadanih vrijednosti */
	fI = Imaks * (cos(alphaI) + I * sin(alphaI));
	fU = Umaks * (cos(alphaU) + I * sin(alphaU));
	
	/* Odredivanje fazora struje kroz otpornik */
	fIr = fI + fU / fZ;
	printf("\nStruja kroz otpornik: Modul: %lf, kut: %lf", cabs(fIr), carg(fIr) * 180 / M_PI);
	
	/* Određivanje fazora U12 i U21 */
	fU21 = fU + fIr * R;
	fU12 = -fU21;
	
	printf("\nU12: Modul: %lf, kut: %lf", cabs(fU12), carg(fU12) * 180 / M_PI);
	printf("\nU21: Modul: %lf, kut: %lf", cabs(fU21), carg(fU21) * 180 / M_PI);
	
	return 0;
}