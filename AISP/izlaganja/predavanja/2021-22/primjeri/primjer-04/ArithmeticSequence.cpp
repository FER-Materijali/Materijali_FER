#include <iostream>

// Computes the n-th term of the arithmetic sequence;
// the initial term: a1
// the common difference of successive members: d
int aseq(int a1, int d, int n) {
	if (n == 1) {
		return a1;
	}
	else {
		return d + aseq(a1, d, n - 1);
	}
}

int main() {
	int a1, d, n, nterm;
   try {
      while (true) {
         std::cout << "Enter a1, d, n: ";
         std::cin >> a1 >> d >> n;
         if (n <= 0) {
            throw std::runtime_error("Error: term index <= 0!");
         }
         nterm = aseq(a1, d, n);
         std::cout << "a" << n << " = " << nterm << std::endl; 
      }
   } catch(std::exception& e) {
	   std::cerr << e.what() << "\n";
   }
   std::cin.get();
	return 0;
}
