#include <stdio.h>  // iz C-a
#include <iostream> // iz c++
#include <cmath>

using namespace std;

namespace ns1 {
    double pi = 3.14;
}

namespace ns2 {
    double pi = 3.1415926353;
}

//using namespace ns1;
//using namespace ns2;

int kvadrat (int arg) {
    cout << "int ";
    return arg * arg;
}

double kvadrat (double arg) {
    cout << "double ";
    return arg * arg;
}

void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap2(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap3(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    int br = 5;
    printf("Hello world\n"); // Java - System.out.print... 
    std::cout << "Hello wolrd" << endl; // Javin System.out == cout u C++

    cout << "Imam " << br << " jabuka" << endl; // "konkateniranje" ispisa... Može i izraz, npr. (br+1) ili sl.

    int input;
    cout << "Upisi broj: ";
    cin >> input;

    cout << "Upisali smo broj " << input << "." << endl;
    cout << "Korijen od " << input << " je " << sqrt(input) << endl; // može i funkcija... sqrt je iz cmath

    cout << ns1::pi << endl;
    cout << ns2::pi << endl;

    //što ako dodam using namespace ns1 i using namespace ns2?
    //cout << pi;

    //overloading
    cout << kvadrat(2) << endl;
    cout << kvadrat(3.0) << endl;
    cout << fixed << kvadrat(3.0) << endl;

    //Reference
    // U C++ - oznaka & kod stvarana

    int a = 5;
    int &b = a;  // b je referenca na a
    //dalje koristim a i b kao obične varijable, tj. b je iz moje perspektive samo drugo ime (alias) za a
    // interno je b ustvari neka vrsta pokazivača ali to se nas ne tiče...

    cout << a << " " << b << endl;

    a++;
    cout << a << " " << b << endl;

    b++;
    cout << a << " " << b << endl;

    // s pokazivačima je ružnija sintaksa, ali rezultat je isti
    int *c = &a;
    (*c)++;
    cout << a << " " << b <<  " "  << (*c) << endl;

    int x = 5;
    int y = 8;
    swap(x,y);
    cout << x << " " << y << endl;

    swap2(&x,&y);
    cout << x << " " << y << endl;

    swap3(x,y);
    cout << x << " " << y << endl;

    return 0;
}