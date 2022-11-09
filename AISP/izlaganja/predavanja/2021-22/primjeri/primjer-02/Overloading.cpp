#include <iostream>
using namespace std;
int kvadrat(int arg) {
   cout << "int ";
   return arg * arg;
}
double kvadrat(double arg) {
   cout << "double ";
   return arg * arg;
}
int main(void) {
   cout << kvadrat(2) << " " << kvadrat(2.) << " " << kvadrat('A') << endl;
   return 0;
}