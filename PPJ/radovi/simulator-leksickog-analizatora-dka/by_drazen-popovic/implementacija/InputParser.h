#ifndef InputParser_h
#define InputParser_h
#include "Parser.h"
#include <vector>
#define MAX_IN 500
using namespace std;
class InputParser : public Parser
{
public:
	InputParser(void);
	void Parse();
	void print();
	~InputParser(void);
	vector <char> source;
};

#endif