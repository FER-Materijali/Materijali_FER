#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "myfactory.h"

typedef struct Animal* (*FUNPTR_AC)(char const*); 

void *myfactory(char const* libname, char const* ctorarg) {
	void *handle;
	char *error;
	FUNPTR_AC create;
	struct Animal* animal;

	handle = dlopen(libname, RTLD_LAZY);
	if(!handle) {
		fprintf(stderr, "%s\n", dlerror());
		return NULL;
	}

	dlerror();//clear any existing errors

	create = (FUNPTR_AC)dlsym(handle, "create");

	if((error = dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
		return NULL;
	}

	return create(ctorarg);
}
