#include <iostream>
using namespace std;

void f(int i){
   if(i==6){
      return;
   }
   cout << i << endl;
   f(i+1);
   cout << i << endl;
}

//0! = 1
//1! = 1
//n! = n * (n-1)!

int fakt(int n){
   if(n==0) return 1;
   if(n==1) return 1;
   n*fakt(n-1);
}

int fib(int n){
   if(n<=1) return 1;
   else {
      return fib(n-1) + fib(n-2); 
   }
}

int main(){
   cout << fib(40);
   cin.get();
   cout << fib(45);
   cin.get();
   cout << fib(50);
   cin.get();
   cout << fib(55);
   cin.get();
   return 0;
}