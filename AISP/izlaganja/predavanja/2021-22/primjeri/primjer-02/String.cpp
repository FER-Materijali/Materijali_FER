#include "string.h"
#include <iostream>
using namespace std;

class String {
 private:
   char *p;
   size_t size;

 public:
   String() { // pretpostavljeni konstruktor
      size = 0;
      p = (char *)malloc(size + 1);
      *p = '\0';
   }

   String(
       const char *s) { // konstruktor na temelju C niza npr. String s("FER");
      size = strlen(s);
      p = (char *)malloc(size + 1);
      strcpy(p, s);
   }

   String(String &s) { // konstruktor kopiranjem
      p = (char *)malloc(s.size + 1);
      size = s.size;
      strcpy(p, s.p);
   }

   ~String() { free(p); } // destruktor

   friend ostream &operator<<(ostream &os, String s) {
      return os << s.p;
   } // ispis

   String &operator=(const char *s) { // operator pridruživanja od C niza npr
                                      // String s = "FER";
      size = strlen(s);
      p = (char *)realloc(p, size + 1);
      strcpy(p, s);
      return *this;
   }

   String &operator=(const String &s) { // operator pridruživanja
      size = s.size;
      p = (char *)realloc(p, size + 1);
      strcpy(p, s.p);
      return *this;
   }

   size_t getSize() { return size; } // dohvat duljine

   String &operator+=(const char *s) { // konkatenacija C niza npr. s += "FER";
      size = size + strlen(s);
      p = (char *)realloc(p, size + 1);
      strcat(p, s);
      return *this;
   }

   String &operator+=(const String &s) { // konkatenacija
      size = size + s.size;
      p = (char *)realloc(p, size + 1);
      strcat(p, s.p);
      return *this;
   }

   String operator+(const char *s) { // spajanje s C nizom npr a = b + "FER";
      String ret(*this);
      ret += s;
      return ret;
   }

   friend String operator+(const char *s,
                           String &r) { // spajanje s C nizom npr a = "FER" + b;
      String ret(s);
      ret += r;
      return ret;
   }

   String operator+(const String &s) { // spajanje
      String ret(*this);
      ret += s;
      return ret;
   }

   bool operator==(String &s) {
      return strcmp(p, s.p) == 0 ? true : false;
   } // jednakost

   bool operator!=(String &s) { return !(*this == s); } // različitost
};

void f(String s) { // call by value s konstruktorom kopiranjem
   cout << "U funkciji pri ulasku: " << s << endl;
   s = "Nova vrijednost";
   cout << "U funkciji prije izlaska: " << s << endl;
}

int main(void) {
   String a, b("ETF"), c("FER");
   cout << a << " " << b << endl;
   a = b;
   cout << (a == b) << " " << (a != b) << endl;
   a = b + " " + c;
   cout << a << endl;
   a = "FER3" + c;
   cout << a << endl;
   a += " program";
   cout << a << endl;
   f(a);
   cout << "Nakon povratka: " << a << endl;
   return 0;
}