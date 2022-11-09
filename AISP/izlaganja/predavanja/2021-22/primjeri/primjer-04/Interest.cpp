#include <iostream>
#include <string>

// Recursively compute the total repayment sum (1st approach)
float interest(float c, int n, float p) {
	// c – the capital
	// n – the number of years
	// p – the annual interest rate (%)
	if (n <= 0) {
		return c;
	}
	else {
		return (1 + p / 100) * interest(c, n - 1, p);
	}
}

// Recursively compute the total repayment sum (2nd approach)
float interest2(float c, int n, float p) {
	// c – the capital
	// n – the number of years
	// p – the annual interest rate (%)
	if (n <= 0) {
		return c;
	}
	else {
		return interest2(c * (1 + p / 100), n - 1, p);
	}
}

int main(void) {
	float c, p, total1, total2;
	int n;
	while (true) {
		std::cout << "Enter the capital, the number of years and the annual interest rate: ";
		std::cin >> c >> n >> p;
		if (n <= 0 || c <= 0 || p <= 0) {
			break;
		}
		total1 = interest(c, n, p);
		total2 = interest2(c, n, p);
		std::cout << "Recursion 1: The total amount (the capital + the total interest) after " << n << " year(s): " << total1 << "\n";
		std::cout << "Recursion 2: The total amount (the capital + the total interest) after " << n << " year(s): " << total2 << std::endl;
	}
	return 0;
}
