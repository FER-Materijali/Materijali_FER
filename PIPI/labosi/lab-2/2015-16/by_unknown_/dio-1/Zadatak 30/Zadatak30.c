#include <stdio.h>

int main(void){
	int Ulaz, Ostatak, Brojac = 0, Najveci = 0, Najveci2 = 0, PrvaDva = 0;
	do{
		scanf("%d", &Ulaz);
		if((Ulaz < 0 || Ulaz > 100) && (Brojac <= 1)){
			PrvaDva = 1;
			break;
		}else if(Ulaz < 0 || Ulaz > 100){
			break;
		}else if(Ulaz >= Najveci){
			Najveci2 = Najveci;
			Najveci = Ulaz;
		}else if(Ulaz >= Najveci2){
			Najveci2 = Ulaz;
		}
		Brojac++;
	}while(Ulaz >= 0 && Ulaz <= 100);
	if(PrvaDva == 1){
		printf("Nije uneseno dovoljno brojeva iz trazenog intervala.");
	}else{
		Ostatak = Najveci % Najveci2;
		printf("Ostatak pri dijeljenju %d sa %d je %d.", Najveci, Najveci2, Ostatak);
	}
	return 0;
}