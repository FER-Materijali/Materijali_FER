#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef void const* (*PRTFUN)(void);

/* ==============================================
   RAZRED Animal
   ============================================== */
	
typedef struct{
	PRTFUN *vtable;
	char* name;
} Animal;

void animalPrintGreeting(Animal* obj){
	printf("%s pozdravlja: %s\n", obj->name, obj->vtable[0]());
}

void animalPrintMenu(Animal* obj){
	printf("%s voli %s\n", obj->name, obj->vtable[1]());
}

PRTFUN AnimalVTable[2] = {
	(PRTFUN)NULL,
	(PRTFUN)NULL,
};

Animal* AnimalInit(){
	Animal* obj = (Animal*)malloc(sizeof(Animal));
	obj->vtable = AnimalVTable;
	return obj;
}

/* ==============================================
   RAZRED Dog
   ============================================== */

char const* dogGreet(void){
  return "vau!";
}
char const* dogMenu(void){
  return "kuhanu govedinu";
}

PRTFUN DogVTable[2] = {
	(PRTFUN)dogGreet,
	(PRTFUN)dogMenu
};

Animal* createDog(char* name){
	Animal* dog = AnimalInit();
	dog->vtable = DogVTable;
	dog->name = name;	
}
   
/* ==============================================
   RAZRED Cat
   ============================================== */

char const* catGreet(void){
  return "mijau!";
}
char const* catMenu(void){
  return "konzerviranu tunjevinu";
}

PRTFUN CatVTable[2] = {
	(PRTFUN)catGreet,
	(PRTFUN)catMenu
};

Animal* createCat(char* name){
	Animal* cat = AnimalInit();
	cat->vtable = CatVTable;
	cat->name = name;	
}

/* ==============================================
   RAZRED testAnimals
   ============================================== */

void testAnimals(void){
  struct Animal* p1=createDog("Hamlet");
  struct Animal* p2=createCat("Ofelija");
  struct Animal* p3=createDog("Polonije");

  animalPrintGreeting(p1);
  animalPrintGreeting(p2);
  animalPrintGreeting(p3);

  animalPrintMenu(p1);
  animalPrintMenu(p2);
  animalPrintMenu(p3);

  free(p1); free(p2); free(p3);
}

/* ==============================================
   RAZRED main
   ============================================== */
   
   int main(){
   	testAnimals();
   	return 0;
   }
