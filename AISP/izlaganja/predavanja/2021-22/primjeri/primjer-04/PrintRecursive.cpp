#include <iostream>

// Print in ascending order from n1 to n2
void printAsc1(int n1, int n2) {
	if (n1 <= n2) {
		std::cout << n1 << ' ';
		printAsc1(n1 + 1, n2);
	}
}

// Print in ascending order from n1 to n2
void printAsc2(int n1, int n2) {
	if (n1 <= n2) {
		printAsc2(n1, n2 - 1);
		std::cout << n2 << ' ';
	}
}

// Print in ascending order from 1 to n
void printAsc3(int n) {
	if (n >= 1) {
		printAsc3(n - 1);
		std::cout << n << ' ';
	}
}

// Print in descending order from n2 to n1
void printDesc1(int n1, int n2) {
	if (n1 <= n2) {
		std::cout << n2 << ' ';
		printDesc1(n1, n2 - 1);
	}
}

// Print in descending order from n2 to n1
void printDesc2(int n1, int n2) {
	if (n1 <= n2) {
		printDesc2(n1 + 1, n2);
		std::cout << n1 << ' ';
	}
}


// Print in descending order from n to 1
void printDesc3(int n) {
	if (n >= 1) {
		std::cout << n << ' ';
		printDesc3(n - 1);
	}
}

int main(void) {
	int n;
	std::cout << "Enter a positive integer (the maximal value to be printed): ";
	std::cin >> n;
	printAsc1(1, n);
	std::cout << "\n";

	printAsc2(1, n);
	std::cout << "\n";

	printAsc3(n);
	std::cout << "\n";
	
	printDesc1(1, n);
	std::cout << "\n";

	printDesc2(1, n);
	std::cout << "\n";

	printDesc3(n);
	std::cout << "\n";
	
	std::cin.get();
	std::cin.ignore();
	return 0;
}
