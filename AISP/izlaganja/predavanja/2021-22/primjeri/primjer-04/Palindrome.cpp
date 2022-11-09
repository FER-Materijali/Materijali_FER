#include <iostream>
#include <string>
#include <cctype>

// Recursively check whether the string is a palindrome;
// Ignore whitespaces;
// Uppercase and lowercase letters are treated equally
bool palindrome(const std::string& str) {
	bool retValue = false;

	// skip leading whitespaces
	auto start = 0;
	while (std::isspace(str[start])) start++;

	// skip trailing whitespaces
	auto end = str.length() - 1;
	while (end && std::isspace(str[end])) --end;

	if (end >= start) {
		if (std::toupper(str[start]) == std::toupper(str[end])) {
			// check base case (i.e. a string whose length is <= 1)
			if (end - start <= 1) {
				retValue = true;
			}
			// recursive call
			else {
				retValue = palindrome(str.substr(start + 1, end - start - 1));
			}
		}
	}
	else {
		retValue = true; // only spaces left in str
	}
	return retValue;
}

int main(void) {	
	while (true) {
		std::string str;
		std::cout << "Enter a string: ";
		std::getline(std::cin, str);
		if (str.length()) {
			std::string str2 = palindrome(str) ? " is " : " isn't ";
			std::cout << "\"" << str << "\"" << str2 << "a palindrome." << std::endl;
		}
		else { // Finish when an empty string is entered
			break;
		}
	}
	return 0;
}
