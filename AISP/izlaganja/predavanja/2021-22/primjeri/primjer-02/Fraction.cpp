#include <iostream>
using namespace std;
class Fraction {
 public:
   int numerator;
   int denominator;
   Fraction(){};
   Fraction(int numerator, int denominator)
       : numerator(numerator), denominator(denominator) {}
#if 0       
   Fraction operator+(Fraction &other) {
      Fraction r;
      r.denominator = denominator * other.denominator;
      r.numerator =
          denominator * other.numerator + other.denominator * numerator;
      return r;
   }
   bool operator==(Fraction &other) {
      return denominator == other.denominator && numerator == other.numerator;
   }
#else
   friend Fraction operator+(Fraction &left, Fraction &right) {
      Fraction r;
      r.denominator = left.denominator * right.denominator;
      r.numerator = left.denominator * right.numerator +
                    right.denominator * left.numerator;
      return r;
   }
   friend bool operator==(Fraction &left, Fraction &right) {
      return left.denominator == right.denominator &&
             left.numerator == right.numerator;
   }
#endif

   friend ostream &operator<<(ostream &os, const Fraction &r) {
      os << r.numerator << "/" << r.denominator;
      return os;
   };

   friend istream &operator>>(istream &is, Fraction &r) {
      is >> r.numerator >> r.denominator;
      return is;
   };
};

int main(void) {
   Fraction a(1, 2), b(2, 3), c(1, 2);
   cout << a << " " << b << " " << a + b << endl;
   cout << (a == b) << " " << (a == c) << endl;
   a = b;
   cout << a << " " << b << " " << (a == b) << " " << (a == c) << endl;
   cin >> c;
   cout << c << endl;
   return 0;
}