#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char const* (*PTRFUN)();

char const* dogGreet(void){
  return "vau!";
}
char const* dogMenu(void){
  return "kuhanu govedinu";
}
char const* catGreet(void){
  return "mijau!";
}
char const* catMenu(void){
  return "konzerviranu tunjevinu";
}

PTRFUN afpd[2]={&dogGreet, &dogMenu}; //niz pokazivaca na funkcije za psa
PTRFUN afpc[2]={&catGreet, &catMenu}; //niz pokazivaca na funkcije za macku

struct Animal{
    char *name;
    PTRFUN *ptf; //pokazivac na tablicu funkcija (na niz pokazivaca)
};

void animalPrintGreeting(struct Animal *pAnimal){
    printf("%s pozdravlja: %s\n", pAnimal->name, pAnimal->ptf[0]());
}

void animalPrintMenu(struct Animal *pAnimal){
    printf("%s voli %s\n", pAnimal->name, pAnimal->ptf[1]());
}

struct Animal* createDog(char* initName){
    struct Animal *p=(struct Animal*)malloc(sizeof(struct Animal));
    p->name=initName;
    p->ptf=afpd;
    return p;
}

struct Animal* createCat(char* initName){
    struct Animal *p=(struct Animal*)malloc(sizeof(struct Animal));
    p->name=initName;
    p->ptf=afpc;
    return p;
}

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

int main(){
    testAnimals();
    return 0;
}

