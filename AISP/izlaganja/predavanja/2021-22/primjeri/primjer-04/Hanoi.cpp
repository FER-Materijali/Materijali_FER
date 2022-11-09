#include <iostream>
#include <string>

void hanoi(const std::string& from, const std::string& to, const std::string& aux, int n) {
	if (n > 0) {
		hanoi(from, aux, to, n - 1);
		std::cout << "Move disk " << n << " from peg \"" << from << "\" to peg \"" << to << "\"\n";
		hanoi(aux, to, from, n - 1);
	}
}

int main(void) {
	int n;
	while (true) {
		std::cout << "Enter the number of disks : ";
		std::cin >> n;
		if (n <= 0) {
			break;
		}
		std::cout << "---- Hanoi tower with " << n << " disk(s) ----\n";
		hanoi("From", "To", "Aux", n);
		std::cout << std::endl;
	}	
	return 0;
}
