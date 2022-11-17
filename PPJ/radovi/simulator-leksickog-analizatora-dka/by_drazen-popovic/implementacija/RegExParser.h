#ifndef RegExParser_h
#define RegExParser_h
#include "Parser.h"
#include <vector>
#include "RegExp.h"
#define MAX_DES_CHAR 10
#define MAX_REG_CHAR 100
using namespace std;
class RegExParser :
	public Parser
{
public:
	RegExParser(void);
	~RegExParser(void);
	void Parse();
	void print();
	void printAlphabet();
	int isAlphabet(char alpha);
	vector <RegExpP> infixRegs;
	vector <RegExpP> postfixRegs;
	vector<char> alphabet;

};

#endif