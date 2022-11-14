#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef enum {false, true} bool;

/////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
///virtualne metode
//inače može virtualna tablica djeteta biti drugačija ako u njoj definiramo
//nove virtualne metode
//i apstraktne klase moraju imati virtualne tablice, jer iako se samo ne mogu
//kreirati, kada kreiramo klasu dijete, onda pozivamo i konstruktor matične klase
//koja može unutar konstruktora pozivati virt metodu
///5. zad ostali jezici ne definiraju prvo bazičnu virt tablicu, nego virt tablicu
///te klase (opasnost da u konstruktoru bazičnom poziva overridanu metodu koja koristi
///atribute ili poziva metode koje ne postoje u bazičnoj klasi)

struct vt_Unary_Function
{
    double (*value_at)(struct Unary_Function*, double);
    double (*negative_value_at)(struct Unary_Function*, double) ;
};
struct vt_Linear
{
    double (*value_at)(struct Unary_Function*, double);
    double (*negative_value_at)(struct Unary_Function*, double) ;
};
struct vt_Square
{
    double (*value_at)(struct Unary_Function*, double);
    double (*negative_value_at)(struct Unary_Function*, double) ;
};







///svaka klasa dijete mora imati isti memorijski otisak kao i matična klasa
///i na to nadodano vlastito (može se pointer kastati u matičnu klasu i radilo bude)
//koristim struktove za virtualne tablice da ih mogu imenom pozivati, a ne brojem

struct Unary_Function
{
    int _lower_bound;
    int _upper_bound;
    struct vt_Unary_Function *virtual;
};

struct Linear
{
    int _lower_bound;
    int _upper_bound;
    struct vt_Linear *virtual;
    double a;
    double b;
};

struct Square
{
    int _lower_bound;
    int _upper_bound;
    struct vt_Square *virtual;
};

///////////////////////////////////////////////////////////////
///////////////////UNARY_FUNCTION CLASS///////////////////////
///////////////////////////////////////////////////////////////

double negative_value_at(struct Unary_Function *this, double x)
{
    return -this->virtual->value_at(this,x);
}

void tabulate(struct Unary_Function *this)
{
      int x = this->_lower_bound;
      for(x; x <= this->_upper_bound; x++)
        {
        printf("f(%d)=%lf\n", x, this->virtual->value_at(this, x));
      }
};

bool same_functions_for_ints(struct Unary_Function *f1,struct Unary_Function *f2, double tolerance)
{
      if(f1->_lower_bound != f2->_lower_bound)
            return false;
      if(f1->_upper_bound != f2->_upper_bound)
            return false;

      int x = f1->_lower_bound;
      for(x; x <= f1->_upper_bound; x++)
      {
        double delta = f1->virtual->value_at(f1, x) - f2->virtual->value_at(f2,x);
        if(delta < 0)
            delta = -delta;
        if(delta > tolerance)
            return false;
      }
      return true;

}


//////////////////////////////////////////////////////////////////
///////////////SQUARE CLASS////////////////////////////////////
//////////////////////////////////////////////////////////////////



double sq_value_at(struct Unary_Function *this, double x)
{
    //inače bi bilo potrebno ovde unary_Function kastati, ali ovde bi bilo bezveze
    return x*x;
}


/////////////////////////////////////////////////////////////////////
//////////////////LINEAR CLASS//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////


//mora primati unary_function, ali overidana je u linear klasi
//stoga, znamo da će dobiti linear objekt, pa mozemo kastati unary_function u linary
//jer unary_function pointer pokazuje na dio objekta lineary
double lin_value_at(struct Unary_Function *this, double x)
{
    struct Linear *lin=(struct Linear*)this;
    return lin->a*x+lin->b;
};


//////////////////////////////////////////////////////////////////////////////
///tablica virtualnih funkcijA//////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

struct vt_Unary_Function *virt_UF={NULL, &negative_value_at};
struct vt_Linear *virt_L={&lin_value_at,&negative_value_at};
struct vt_Square *virt_SQ={&sq_value_at,&negative_value_at};


////////////////////////////////////////////////////////////////////////
///konstruktori/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


///Unary_Function konstruktor
//ovo je new za Unary_Function
struct Unary_Function* allocate_Unary_Function()
{
    struct Unary_Function *this = (struct Unary_Function*)malloc(sizeof(struct Unary_Function));
    return this;
};

//Ovo je zapravo konstruktor, i OBAVEZNO se prvo postavlja virtualna tablica,
//jer konstruktor može pozivati virtualne metode
void init_Unary_Function(struct Unary_Function *this, int lb, int ub)
{
    this->virtual                     = &virt_UF;
    this->_lower_bound                = lb;
    this->_upper_bound                = ub;

};
struct Unary_Function* create_Unary_Function(int lb, int ub)
{
    struct Unary_Function *this     = allocate_Unary_Function();
    init_Unary_Function(this, lb, ub);
    return this;
};

///Square konstruktor

struct Square* allocate_Square()
{
    struct Square* this = (struct Square*)malloc(sizeof(struct Square));
    return this;
};
void init_Square(struct Square* this, int lb, int ub)
{
    init_Unary_Function((struct Unary_Function*)this, lb, ub);
    this->virtual=&virt_SQ;
};
struct Unary_Function* create_Square(int lb, int ub)
{
    struct Square *this = (struct Square*)allocate_Square();
    init_Square(this, lb, ub);
    return (struct Unary_Function*)this;
};

///Linear konstruktor

struct Linear* allocate_Linear()
{
    struct Linear* this = (struct Linear*)malloc(sizeof(struct Linear));
    return this;
};
void init_Linear(struct Linear* this, int lb, int ub, double a_coef, double b_coef)
{
    init_Unary_Function((struct Unary_Function*)this, lb, ub);
    this->virtual=&virt_L;
    this->a=a_coef;
    this->b=b_coef;
};
struct Unary_Function* create_Linear(int lb, int ub, double a_coef, double b_coef)
{
    struct Linear *this = allocate_Linear();
    init_Linear(this, lb, ub, a_coef, b_coef);
    return (struct Unary_Function*)this;
};

////////////////////////////////////////////////////////////////////////////////////
///destruktori idu analogno ovome/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///ima greška kod negative_value_at za Linear/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////
////////////////////////MAIN////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
int main()
{

  struct Unary_Function *f1 = create_Square(-2, 2);
  tabulate(f1);
  struct Unary_Function *f2 = create_Linear(-2, 2, 5, -2);
  tabulate(f2);

  printf("f1==f2: %s\n", same_functions_for_ints(f1, f2, 1E-6) ? "DA" : "NE");
  printf("neg_val f2(1) = %lf\n", f2->virtual->negative_value_at(f2,1.0));
  free(f1);
  free (f2);
  return 0;



}
