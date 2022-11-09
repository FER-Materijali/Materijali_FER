#include <array>
#include <iostream>
#include <stdexcept>

struct RetValFibonacci {
   int Fn;
   int numCalls; // number of function calls needed to compute Fn

   RetValFibonacci() : Fn(1), numCalls(1) {}
   RetValFibonacci(int newFn) : Fn(newFn), numCalls(1) {}
   RetValFibonacci(int newFn, int newNumCalls)
       : Fn(newFn), numCalls(newNumCalls) {}

   // using canonical form for operator+; see
   // https://en.cppreference.com/w/cpp/language/operators friends defined
   // inside class body are inline and are hidden from non-ADL lookup
   // (ADL-Argument Dependent Lookup) friends must be used if they access
   // private members
   friend RetValFibonacci operator+(
       RetValFibonacci lhs, // passing lhs by value helps optimize chained a+b+c
       const RetValFibonacci
           &rhs) { // otherwise, both parameters may be const references
      lhs.Fn += rhs.Fn;
      lhs.numCalls += rhs.numCalls + 1; // + 1 for the current function call
      return lhs; // return the result by value (uses move constructor)
   }
};

class IFibonacci {
 public:
   virtual RetValFibonacci F(int n) = 0; // computes the n-th Fibonacci number
};

class FibonacciRec : public IFibonacci {
 public:
   RetValFibonacci F(int n) override {
      if (n <= 1) {
         return RetValFibonacci{1};
      } else {
         return F(n - 2) + F(n - 1);
      }
   };
};

class FibonacciDPTopDown : public IFibonacci {
 private:
   int *arrF;
   RetValFibonacci FibonacciTopDown(int n) {
      if (arrF[n] > 0)
         return RetValFibonacci{arrF[n]}; // F[n] already known
      RetValFibonacci r{1};
      if (n > 1) {
         r = FibonacciTopDown(n - 1) + FibonacciTopDown(n - 2);
      }
      arrF[n] = r.Fn;
      return r;
   }

 public:
   RetValFibonacci F(int n) override { // top-down approach in O(n) space
      arrF = new int[n + 1];
      for (auto i = 0; i <= n; i++)
         arrF[i] = 0;
      RetValFibonacci r = FibonacciTopDown(n);
      delete[] arrF;
      return r;
   };
};

class FibonacciDPBottomUp1 : public IFibonacci {
 public:
   RetValFibonacci F(int n) override { // bottom-up approach in O(n) space
      int *F = new int[std::max(2, n + 1)];
      F[0] = 1;
      F[1] = 1;
      for (int i = 2; i <= n; i++) {
         F[i] = F[i - 1] + F[i - 2];
      }
      int Fn = F[n];
      delete[] F;
      return RetValFibonacci{Fn};
   };
};

class FibonacciDPBottomUp2 : public IFibonacci {
 public:
   RetValFibonacci F(int n) override { // bottom-up approach in O(1) space
      int F0 = 1, F1 = 1, Fn;
      if (n <= 1)
         return (Fn = 1);
      for (int i = 2; i <= n; i++) {
         Fn = F0 + F1;
         F0 = F1;
         F1 = Fn;
      }
      return RetValFibonacci{Fn};
   };
};

class ContextFibonacci {
 public:
   enum StrategyType { Recursive = 1, TopDown, BottomUp1, BottomUp2 };

   ContextFibonacci() { // set default Fibonacci algorithm
      strategy = new FibonacciRec();
   }

   void setStrategy(int type) {
      // set new strategy
      if (strategy) {
         deleteStrategy();
         if (type == Recursive) {
            strategy = new FibonacciRec();
         } else if (type == TopDown) {
            strategy = new FibonacciDPTopDown();
         } else if (type == BottomUp1) {
            strategy = new FibonacciDPBottomUp1();
         } else if (type == BottomUp2) {
            strategy = new FibonacciDPBottomUp2();
         } else {
            throw std::invalid_argument("Error: Invalid mode.");
         }
      }
   }

   RetValFibonacci F(int n) {
      if (!strategy) {
         throw std::runtime_error("Strategy not set!");
      }
      return strategy->F(n);
   }

   ~ContextFibonacci() {
      if (strategy) {
         deleteStrategy();
      }
   }

 private:
   IFibonacci *strategy;

   void deleteStrategy() {
      delete strategy;
      strategy = nullptr;
   }
};

int main(void) {
   ContextFibonacci cs;

   try {
      while (true) {
         int n;
         std::cout << "Enter n: ";
         std::cin >> n;
         if (n < 0) {
            throw std::invalid_argument(
                "Error: n should be a non-negative number.");
         } else {
            std::cout << "Enter an approach to compute the n-th Fibonacci "
                         "number (1-4):\n"
                         "\t(1) Recursive approach (O(1) space)\n"
                         "\t(2) Top-down approach (O(n) space)\n"
                         "\t(3) Bottom-up approach (O(n) space)\n"
                         "\t(4) Bottom-up approach (O(1) space)\n > ";

            int type;
            std::cin >> type;
            if (std::cin.fail()) {
               throw std::invalid_argument("Error: Invalid approach.");
            }
            cs.setStrategy(type);
            RetValFibonacci fib = cs.F(n);
            if (fib.Fn < 0) {
               throw std::overflow_error("Error: Overflow.");
            }
            std::cout << "F" << n << " = " << fib.Fn
                      << ". Number of function calls: " << fib.numCalls
                      << ".\n";
         }
      }
   } catch (std::exception &e) {
      std::cerr << e.what();
   }
   return 0;
}
