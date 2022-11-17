#ifndef Generator_h
#define Generator_H
#include <vector>
#include "D:\Projekt_Zavrsni\bladyjoker\SSP\RegExp.h"
#include "State.h"
#include "NKA.h"
using namespace std;


class GeneratorLexAnal
{
public:
	GeneratorLexAnal(void);
	NKA* genPart(StateP nullState, int* i, char* regex);
	void error(char* str);
	//Svi regularni izrazi!!
	vector<RegExpP> regExps;
	//Abeceda izvucena iz regExpsa
	vector<char> alphabet;
	int isAlphabet(char alpha);
	void generate();
	//kad zavrsi algoritam generiranja u outputNKAS se nalaze NKA od svih regexp-a
	vector<NKA*> outputNKAS;
	~GeneratorLexAnal(void);
};

#endif