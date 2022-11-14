#include <stdio.h>

int main(void){
	int Ulaz, Izlaz = 0, PomVarijabla;
	do{
		scanf("%d", &Ulaz);
	}while(Ulaz < 100 || Ulaz > 999);
	PomVarijabla = Ulaz;
	while(Ulaz){
		Izlaz = (Izlaz * 10) + (Ulaz % 10);
		Ulaz /= 10;
	}
	if(PomVarijabla < Izlaz){
		printf("Broj %d veci je od ucitanog broja.", Izlaz);
	}else if(PomVarijabla == Izlaz){
		printf("Broj %d jednak je ucitanom broju.", Izlaz);
	}else{
		printf("Broj %d manji je od ucitanog broja", Izlaz);
	}
	return 0;
}