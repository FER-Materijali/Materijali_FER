#include <stdlib.h>

typedef char const* (*PTRFUN)();

struct Parrot {
	PTRFUN *vtable;
	char const* name;
};

char const *name(void *this) {
	return ((struct Parrot*)this)->name;
}

char const *greet() {
	return "Sto mu gromova!";
}

char const *menu() {
	return "brazilske orahe";
}

PTRFUN ParrotVTable[3] = {
	(PTRFUN) name,
	(PTRFUN) greet,
	(PTRFUN) menu
};

void *create(char const *name) {
	struct Parrot *parrot = malloc(sizeof(struct Parrot));
	parrot->vtable = ParrotVTable;
	parrot->name = name;
	return parrot;
}
