#include <iostream>

// Compute factorial of n recursively
long fakt(int n) {
	long nfakt;
	if (n <= 1) {	
		// 0! = 1! = 1
		nfakt = 1;
	}
	else {			
		// n! = n * (n-1)!
		nfakt = n * fakt(n - 1);
		if (nfakt <= 0) {
			throw std::overflow_error("Overflow.");
		}
	}
	return nfakt;
}

int main(void) {
	int n;
	try {
		while (true) {
			std::cout << "Enter a positive integer: "; 
			std::cin >> n;
			std::cout << n << "! = " << fakt(n) << std::endl;
		}
	}
	catch(std::exception& e) {
		std::cerr << e.what() << "\n";            
	}
	std::cin.ignore();
	return 0;
}
