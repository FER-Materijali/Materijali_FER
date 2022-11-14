#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef void const* (*PTRFUN)(void);

typedef enum {false, true} bool;

/* ==============================================
   RAZRED Unary_Function
   ============================================== */
   
typedef struct{
	PTRFUN *vtable;
	int lower_bound;
	int upper_bound;
} Unary_Function;

typedef double (*funptrDFD)(Unary_Function*, double);

double negative_value_at(Unary_Function* obj, double x){
    funptrDFD pfun = (funptrDFD)obj->vtable[0];
	return -pfun(obj, x);
}

void tabulate(Unary_Function *obj){
      int x = obj->lower_bound;
      funptrDFD pfun = (funptrDFD)obj->vtable[0];
      for(x; x <= obj->upper_bound; x++){
        printf("f(%d)=%lf\n", x, pfun(obj, x));
      }
}

bool same_functions_for_ints(Unary_Function* f1, Unary_Function* f2, double tolerance){
      if(f1->lower_bound != f2->lower_bound){
            return false;
        }
      if(f1->upper_bound != f2->upper_bound){
            return false;
		}
      int x = f1->lower_bound;
      funptrDFD pfun1 = (funptrDFD)f1->vtable[0];
      funptrDFD pfun2 = (funptrDFD)f2->vtable[0];
      for(x; x <= f1->upper_bound; x++){
        	double delta = pfun1(f1, x) - pfun2(f2,x);
        	if(delta < 0){
            delta = -delta;
        	}
        	if(delta > tolerance){
            return false;
        	}
      }
      return true;
}


PTRFUN UnaryVT[2]={
	(funptrDFD)NULL,
	(funptrDFD)negative_value_at
};

Unary_Function* createUnary(int lb, int ub){
	Unary_Function* obj = (Unary_Function*)malloc(sizeof(Unary_Function));
	obj->vtable = UnaryVT;
	obj->lower_bound = lb;
	obj->upper_bound =ub;
	return obj;
}

/* ==============================================
   RAZRED Square
   ============================================== */
   
typedef struct{
	PTRFUN *vtable;
	int lower_bound;
	int upper_bound;
} Square;

double Square_value_at(Square* obj, double x){
	return x*x;
}

PTRFUN SquareVT[2]={
	(funptrDFD)Square_value_at,
	(funptrDFD)negative_value_at
};


Square* createSquare(int lb, int ub){
	Square* obj = (Square*)malloc(sizeof(Square));
	obj->vtable = SquareVT;
	obj->lower_bound = lb;
	obj->upper_bound =ub;
	return obj;
}

/* ==============================================
   RAZRED Linear
   ============================================== */
   
typedef struct{
	PTRFUN *vtable;
	int lower_bound;
	int upper_bound;
	double a;
	double b;
} Linear;


double Linear_value_at(Linear* obj, double x){
	printf("LIN");
	return (obj->a)*x + obj->b;
}

PTRFUN LinearVT[2]={
	(funptrDFD)Linear_value_at,
	(funptrDFD)negative_value_at
};


Linear* createLinear(int lb, int ub, double a_coef, double b_coef){
	Linear* obj = (Linear*)malloc(sizeof(Linear));
	obj->vtable = LinearVT;
	obj->lower_bound = lb;
	obj->upper_bound = ub;
	obj->a = a_coef;
	obj->b = b_coef;
	return obj;
}

/* ==============================================
   RAZRED Main
   ============================================== */

int main(){

  Unary_Function* f1 = createSquare(-2, 2);
  tabulate(f1);
  Unary_Function* f2 = createLinear(-2, 2, 5, -2);
  tabulate(f2);

  printf("f1==f2: %s\n", same_functions_for_ints(f1, f2, 1E-6) ? "DA" : "NE");
  funptrDFD pfun = (funptrDFD)f2->vtable[1];
  printf("neg_val f2(1) = %lf\n", pfun(f2,1.0));
  free(f1);
  free (f2);
  return 0;
}
