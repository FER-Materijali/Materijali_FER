#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* ==============================================
   RAZRED Function
   ============================================== */
 
typedef void (*funptr)(void);

typedef struct {
  funptr *vtable;
} Function;

typedef int (*funptrIFI)(Function*, int);
typedef void (*funptrVF)(Function*);

void FunctionHello(Function *obj) {
  printf("Pozdrav iz razreda Function.\n");
}

void FunctionGreet(Function *obj) {
  // Sljedeca dva retka cine polimorfni poziv funkcije...
  // 1) Dohvati pointer na implementaciju funkcije:
  funptrVF pfun=(funptrVF)obj->vtable[0];
  // 2) Pozovi funkciju na koju pointer pokazuje:
  pfun(obj);
}

void FunctionTabulate(Function *obj, int k) {
  int i;
  for(i=0; i < k; i++) {
    int x = i;
    printf(
      "f(%d)=%d\n", 
      x, 
      ((funptrIFI)obj->vtable[1])(obj, x)  // polimorfni poziv!
    );
  }
}

funptr FunctionVTable[2] = {
  (funptr)FunctionHello,
  (funptr)NULL
};

FunctionInit(Function* obj) {
  obj->vtable = FunctionVTable;
  FunctionGreet(obj);
}

/* ==============================================
   RAZRED Addition
   ============================================== */

typedef struct {
  funptr *vtable;
  int n;
} Addition;

void AdditionHello(Addition *obj) {
  printf("Pozdrav iz razreda Addition.\n");
}

int AdditionValue(Addition *obj, int x) {
  return x + obj->n;
}

funptr AdditionVTable[2] = {
  (funptr)AdditionHello,
  (funptr)AdditionValue
};

AdditionInit(Addition* obj, int n) {
  FunctionInit((Function*)obj);
  obj->vtable = AdditionVTable;
  obj->n = n;
  FunctionGreet((Function*)obj);
}

/* ==============================================
   RAZRED AdditionPower
   ============================================== */

typedef struct {
  funptr *vtable;
  int n;
  int p;
} AdditionPower;

void AdditionPowerHello(AdditionPower *obj) {
  printf("Pozdrav iz razreda AdditionPower.\n");
}

int AdditionPowerValue(AdditionPower *obj, int x) {
  return pow(
    AdditionValue((Addition*)obj, x), // Ovo nije polimorfni poziv!
    obj->p
  );
}

funptr AdditionPowerVTable[2] = {
  (funptr)AdditionPowerHello,
  (funptr)AdditionPowerValue
};

AdditionPowerInit(AdditionPower* obj, int n, int p) {
  AdditionInit((Addition*)obj, n);
  obj->vtable = AdditionPowerVTable;
  obj->p = p;
  FunctionGreet((Function*)obj);
}

/* ==============================================
   Metoda main()
   ============================================== */

int main() {
  Function *a = (Function*)malloc(
     sizeof(AdditionPower)
  );
  AdditionPowerInit((AdditionPower*)a, 5, 2);
  FunctionTabulate(a, 10);
  ((funptrVF)a->vtable[0])(a); // Polimorfni poziv...
  // Trebalo bi jos (uz emuliranje izvodenje destruktora):
  // AdditionPowerDestruct(a);
  // free(a);
  // Ali buduci da samo ilustriramo ideju, to preskacemo...

  AdditionPower b;
  AdditionPowerInit(&b, 1, 3);
  FunctionTabulate((Function*)&b, 5);
  ((funptrVF)b.vtable[0])((Function*)&b); // Polimorfni poziv...

  return 0;
}
