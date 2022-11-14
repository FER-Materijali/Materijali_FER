#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winbase.h>
#include <windef.h>
#include "myfactory.h"

typedef struct Animal* (*FUNPTR_AC)(char const*); 

void *myfactory(char const* libname, char const* ctorarg) {
   FUNPTR_AC create;

   HMODULE hModule = LoadLibrary(libname);

   create = (FUNPTR_AC)GetProcAddress(hModule,"create");
   return create(ctorarg);
}