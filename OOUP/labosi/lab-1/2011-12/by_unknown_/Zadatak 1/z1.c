#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char const* (*PTRFUN)();

typedef struct 
{
    char* ime;
    PTRFUN* animalTable;
} 
Animal;

char const* dogGreet(void)
{
    return "vau!";
}

char const* dogMenu(void)
{
    return "kuhanu govedinu";
}

char const* catGreet(void)
{
    return "mijau!";
}

char const* catMenu(void)
{
    return "konzerviranu tunjevinu";
}

PTRFUN dogTable[2] = { dogGreet, dogMenu };
PTRFUN catTable[2] = { catGreet, catMenu };

Animal* createDog(char* ime)
{
    Animal* dog = (Animal *)malloc(sizeof(Animal));

    dog->ime = ime;
    dog->animalTable = dogTable;

    return dog;
}

Animal* createCat(char* ime)
{
    Animal* cat = (Animal *)malloc(sizeof(Animal));

    cat->ime = ime;
    cat->animalTable = catTable;

    return cat;
}

void animalPrintGreeting(Animal* animal)
{
    printf("%s pozdravlja: %s\n", animal->ime, animal->animalTable[0]());
}

void animalPrintMenu(Animal* animal)
{
    printf("%s voli %s\n", animal->ime, animal->animalTable[1]());
}

void testAnimals(void)
{
    Animal* p1 = createDog("Hamlet");
    Animal* p2 = createCat("Ofelija");
    Animal* p3 = createDog("Polonije");

    animalPrintGreeting(p1);
    animalPrintGreeting(p2);
    animalPrintGreeting(p3);

    animalPrintMenu(p1);
    animalPrintMenu(p2);
    animalPrintMenu(p3);

    free(p1); free(p2); free(p3);
}

int main()
{
    testAnimals();
    getchar();
    return 0;
}