#include <iostream>


// Euclid's algorithm for computing the greatest commmon divisor (GCD)
int gcd(int a, int b) {
	std::cout << "gcd(" << a << ", " << b << ") = ";
	if (b == 0) {
		std::cout << a << "\n";
		return a;
	}
	return gcd(b, a % b);
}

// Non-recursive computation of the greatest commmon divisor (GCD)
int gcd2(int a, int b) {
	int t;
	while (b != 0) {
		std::cout << "gcd(" << a << ", " << b << ") = ";
		t = b;
		b = a % b;
		a = t;
	}
	std::cout << "gcd(" << a << ", " << b << ") = " << a << "\n";
	return a;
}

int main(void) {
	int a, b;	
   try {
      while (true) {
         std::cout << "Enter two non-negative numbers: ";
         std::cin >> a >> b;
         if ((a < 0 || b < 0) || (a == 0 && b == 0)) {
            throw std::runtime_error("Invalid input values.");
         }
         else {
            std::cout << "Recursive solution: " << gcd(a, b) << "\n\n";
            std::cout << "Non-recursive solution: " << gcd2(a, b) << std::endl;
         }
      }
   }
   catch(std::exception& e) {
      std::cerr << e.what() << "\n";
   }
   std::cin.get();
	return 0;
}
