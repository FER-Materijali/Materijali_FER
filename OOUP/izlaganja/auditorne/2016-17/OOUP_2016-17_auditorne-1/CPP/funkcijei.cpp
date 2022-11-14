#include <iostream>
#include <math.h>

/* ==============================================
   RAZRED Function
   ============================================== */

class Function {
  public:
    Function();
    virtual void hello();
    virtual int value(int x) = 0;
    void tabulate(int k);
    void greet();
};

Function::Function() {
  this->greet();
}

void Function::hello() {
  std::cout << "Pozdrav iz razreda Function" << std::endl;
}

void Function::tabulate(int k) {
  for(int i = 0; i < k; i++) {
    int x = i;
    std::cout << "f(" << x << ")=" << this->value(x) << std::endl;
  }
}

void Function::greet() {
  this->hello();
}

/* ==============================================
   RAZRED Addition
   ============================================== */

class Addition : public Function {
  private:
    int _n;
  public:
    Addition(int n);
    virtual void hello();
    virtual int value(int x);
};

Addition::Addition(int n) : Function(), _n(n) {
  this->greet();
}

void Addition::hello() {
  std::cout << "Pozdrav iz razreda Addition" << std::endl;
}

int Addition::value(int x) {
  return x + this->_n;
}

/* ==============================================
   RAZRED AdditionPower
   ============================================== */

class AdditionPower : public Addition {
  private:
    int _p;
  public:
    AdditionPower(int n, int p);
    virtual void hello();
    virtual int value(int x);
};

AdditionPower::AdditionPower(int n, int p) : Addition(n), _p(p) {
  this->greet();
}

void AdditionPower::hello() {
  std::cout << "Pozdrav iz razreda AdditionPower" << std::endl;
}

int AdditionPower::value(int x) {
  return (int)pow(this->Addition::value(x), _p);
}

/* ==============================================
   Metoda main()
   ============================================== */

int main() {
  Function* a = new AdditionPower(5, 2);
  a->tabulate(10);
  a->hello();
  // Trebalo bi jo�:
  // delete a;
  
  AdditionPower b(1,3);
  b.tabulate(5);
  b.hello();

  int x;
  std::cin >> x;

  return 0;
}
