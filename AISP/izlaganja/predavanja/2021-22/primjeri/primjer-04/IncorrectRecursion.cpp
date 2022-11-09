#include <iostream>

// Incorrect recursion
int failed (int n, int& depth) {
	int r;
	++depth;
	std::cout << "n = " << n << " depth = " << depth << std::endl;
	if (n == 0) {
		r = 0;
	}
	else {
		r = failed(n / 3 + 1, depth) + n - 1;
	}
	return r;
}

int main(void) {
	int depth, n;
	while (true) {
		depth = 0;
		std::cout << "Enter an integer: ";
		std::cin >> n;
		std::cout << failed(n, depth);
	}
	std::cin.ignore();
}
