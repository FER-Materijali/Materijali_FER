#include <iostream>
#include <string>
#include <utility>

size_t index{ 0 };

bool produkcija_S(const std::string &);
bool produkcija_A(const std::string &);
bool produkcija_B(const std::string &);
bool produkcija_C(const std::string &);

int main()
{
	std::string input;
	std::getline(std::cin, input);
	std::cout << ((produkcija_S(input) && index == input.size()) ? "\nDA\n" : "\nNE\n");
	return 0;
}

bool produkcija_S(const std::string &input)
{
	std::cout << "S";
	if(input[index] == 'a')
	{
		++index;
		return produkcija_A(input) && produkcija_B(input);
	}
	else if(input[index] == 'b')
	{
		++index;
		return produkcija_B(input) && produkcija_A(input);
	}
	return false;
}

bool produkcija_A(const std::string &input)
{
	std::cout << "A";
	if(input[index] == 'b')
	{
		++index;
		return produkcija_C(input);
	}
	else if(input[index] == 'a')
	{
		++index;
		return true;
	}
	return false;
}

bool produkcija_B(const std::string &input)
{
	std::cout << "B";
	if(input[index] == 'c')
	{
		++index;
		if(input[index] == 'c')
		{
			++index;
			if(produkcija_S(input) == true)
			{
				if(input[index] == 'b')
				{
					++index;
					if(input[index] == 'c')
					{
						++index;
						return true;
					}
				}
			}
		}
		return false;
	}
	return true;
}

bool produkcija_C(const std::string &input)
{
	std::cout << "C";
	return produkcija_A(input) && produkcija_A(input);
}