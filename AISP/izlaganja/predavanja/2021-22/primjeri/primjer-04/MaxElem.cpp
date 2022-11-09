#include <iostream>
#include <random>

// Recursively find location of maximum value in A
template<typename T>
int maxClan(T A[], int i, int n) {
	int imax;
	if (i >= n - 1) {
		return n - 1;
	}
	imax = maxClan(A, i + 1, n);
	if (A[i] > A[imax]) {
		return i;
	}
	return imax;
}

int main() {		
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 100);
	
	constexpr int MAX = 20;
	int A[MAX];
	// construct array of MAX elements; elements are randomly chosen from the interval [1, 100]; 
	for (int i = 0; i < MAX; ++i) {
		std::cout << (A[i] = dist(mt)) << " ";
	}
	std::cout << std::endl << "The maximum element (recursively): " << A[maxClan<int>(A, 0, MAX)];
	
	int *max = std::max_element(std::begin(A), std::end(A));
	std::cout << std::endl << "The maximum element (using std::max_element): " << *max;
	std::cin.ignore();
	return 0;
}
