#include <iostream>
#include <iomanip> // setw
#include <vector>
#include <set>

using Solution = std::vector<int> ;

class NQueens {
public:
	NQueens(int n) : n(n), numOfSolutions(0), solutions({}) {}
	void printSolutions(); // prints all solutions

private:
	// Checks whether two queens (row1, col1) and (row2, col2) attack each other
	bool threatens(int row1, int col1, int row2, int col2) {
		return (row1 == row2 || col1 == col2
			|| std::abs(row1 - row2) == std::abs(col1 - col2)); // diagonal
	}

	
	// Computes a set of solutions
	void solve(int currCol, Solution& s) {
		if (currCol == n) { // currCol is out of range; ending recursive calls
			++numOfSolutions;
			solutions.emplace(s);
		}
		// Placing a queen in the first column
		// creating a new solution starting with each row
		else if (currCol == 0) { 
			for (auto row = 0; row < n; row++) {
				s.clear(); 
				s.push_back(row); // add row index to the first colummn
				solve(currCol + 1, s);
				if (s.size() == currCol + 1) { // couldn't extend solution after currCol
					s.pop_back();
				}
			}
		}
		// Placing queens in columns other than the first one
		else { 			
			// For a queen in the current column (currCol) and a candidate row (row) check whether it attacks previously placed queens
			for (auto row = 0; row < n; row++) {
				bool attacksPrevPlacedQueens = false;
				for (auto col = 0; col < currCol; col++) {
					if (threatens(row, currCol, s[col], col)) {
						attacksPrevPlacedQueens = true;
						break;
					}
				}
				if (!attacksPrevPlacedQueens) {
					s.push_back(row);
					solve(currCol + 1, s);
					if (s.size() == currCol + 1) { // couldn't extend solution after currCol
						s.pop_back();
					}
				}
			}
		}
	}

	// Prints a solution
	void printSolution(Solution& solution) {
		constexpr int width = 3;
		
		// Print table header, i.e. column names: 'a' - 'h'
		std::cout << std::setw(width) << " ";
		for (auto i = 0; i < n; i++) {
			std::cout << std::setw(width) << char('a' + i);
		}
		std::cout << "\n";

		// Transpose solution vector, since the solution will be printed by rows
		Solution solutionT(solution.size());
		for (int i : solution) {
			solutionT[solution[i]] = i;
		}

		// Print queens' positions on the board;
		// print rows' numbers at the beginning of each row
		for (auto row = 0; row < n; row++) {
			std::cout << std::setw(width) << row + 1;
			std::cout << std::setw(width * (solutionT[row] + 1)) << "K";
			std::cout << "\n";
		}
		std::cout << "\n\n";
	}

	// Data members
	int n;							// number of queens
	int numOfSolutions;        // number of solutions
	std::set<Solution> solutions;	// set of all solutions; each solution is a vector of integers representing rows' indexes
									// using set to ensure uniqueness of the elements in the set
};

// Prints all solutions
void NQueens::printSolutions() {
	Solution s;
	int cnt = 0;

	solve(0, s);
	if (numOfSolutions) {
		for (auto sol : solutions) {
			std::cout << "------------ Solution " << ++cnt << " ------------\n";
			printSolution(sol);
		}
	}
	else {
		std::cout << "There is no solution for n = " << n << ".\n";
	}
}


int main() {
	int n;
	std::cout << "Enter a number of queens: ";
	std::cin >> n;
	//if (n == 2 || n == 3) {
	if (n == 0) {
		std::cout << "There is no solution for n = " << n << "\n";
	}
	else {
		NQueens queens{ n };
		queens.printSolutions();
	}
	std::cin.get();
	std::cin.get();
	return 0;
}
