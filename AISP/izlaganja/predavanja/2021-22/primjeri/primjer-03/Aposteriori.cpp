//#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

// The same function for all running times;
// numOfSteps is n, log(n) or sqrt(n)
void f(int numOfSteps) {
   for (auto i = 0; i < numOfSteps; i++)
      ;
}

class StopWatch {
 private:
   chrono::time_point<chrono::steady_clock> start;

 public:
   void reset() { start = chrono::steady_clock::now(); }
   StopWatch() { reset(); }
   double elapsedSeconds() {
      chrono::duration<double> d = chrono::steady_clock::now() - start;
      return chrono::duration_cast<chrono::microseconds>(d).count() / 1000000.;
   }
};

// Measure the running time of a function
void measureTime(int n, int numOfSteps, string functionName) {
   constexpr int repeat = 1000;

   StopWatch s;

   for (volatile auto i = 0; i < repeat; i++) {
      f(numOfSteps);
   }

   cout << " " << s.elapsedSeconds() << "s\n";
}

int main(void) {
   for (int i = 5; i < 8; i++) { // different orders of magnitude
      auto n = pow(10, i);
      cout << "n = " << n << "\n";
      measureTime(n, log(n), "log"); // ln(10) = 2,3
      measureTime(n, sqrt(n), "squareRoot");
      measureTime(n, n, "linear");
   }
   cin.get();
   return 0;
}
