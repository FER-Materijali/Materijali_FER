#include <stdio.h>
#include <stdlib.h>
#include "myfactory.h"

typedef char const* (*PTRFUN)();

struct Animal {
	PTRFUN *vtable;
	//vtable entries:
	// 0: char const* name(void* this);
	// 1: char const* greet();
	// 2: char const* menu();
};
	
 // parrots and tigers defined in respective dynamic libraries

void animalPrintGreeting(struct Animal *p) {
	printf("%s pozdravlja: %s\n", (p->vtable[0])(p), (p->vtable[1])());
}

void animalPrintMenu(struct Animal *p) {
	printf("%s voli: %s\n", (p->vtable[0])(p), (p->vtable[2])());
}

 
int main(void){
	struct Animal* p1=(struct Animal*)myfactory("./parrot.so", "Modrobradi");
	struct Animal* p2=(struct Animal*)myfactory("./tiger.so", "Straško");
	
	if (!p1 || !p2){
		printf("Creation of plug-in objects failed.\n");
		exit(1);
	}

	animalPrintGreeting(p1);//"Sto mu gromova!"
	animalPrintGreeting(p2);//"Mijau!"

	animalPrintMenu(p1);//"brazilske orahe"
	animalPrintMenu(p2);//"mlako mlijeko"

	free(p1); free(p2); 
}
