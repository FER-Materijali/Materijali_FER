#include <stdio.h>
#include <iostream>
#include "RegExParser.h"
#include "InputParser.h"
#include "State.h"
#include "GeneratorLexAnal.h"
#include "Infix2PostfixConverter.h"
#include "DKA.h"
#include "Simulator.h"
using namespace std;
void error( char* errString )
{
	printf("%s\n", errString);
	exit(-1);
}

int main(int argc, char** argv)
{
	FILE *regexFile, *inFile, *outFile;

	regexFile = fopen("in.regex", "r");
	inFile = fopen("primjer.in", "r");
	
	if(regexFile == NULL) error("regex");
	if(inFile == NULL) error("in");

	RegExParser* regexParser = new RegExParser();
	regexParser->setFile(regexFile);
	regexParser->print();
	regexParser->printAlphabet();	
	
	
	InputParser* inputParser = new InputParser();
	inputParser->setFile( inFile );
	inputParser->print();
	
	GeneratorLexAnal* generator = new GeneratorLexAnal();
	generator->regExps = regexParser->postfixRegs;
	generator->alphabet = regexParser->alphabet;
	generator->generate();

	DKA* dka = new DKA();
	dka->determinate( generator->outputNKAS );

	Simulator* simulator = new Simulator();
	simulator->baseDKA = dka;
	simulator->input = inputParser->source;
	simulator->alphabet = regexParser->alphabet;
	simulator->easy = true;
	simulator->run();
	simulator->printUniTab();
		
	
	delete simulator, dka, generator, inputParser, regexParser;
	fclose(regexFile);
	fclose(inFile);
	return 0;
}

/*
Ulazi su datoteke: *.regex, *.in a izlazi su datoteke *.out. U *.regex datoteci 
se nalaze retci koji predstavljaju regularne izraze za pojedine leksicke jedinke.
Format zapisa u toj datoteci jest:
OZNAKA REG_IZRAZ

npr.,
INT_KONST (0+1+2+3+4+5+6+7+8+9)*

Koristenje: .\LexAnalyzerSimulator *.regex *.in *.out

Dvije ulazne datoteke moraju postojati dok se izlazna datoteka naknadno stvori.
*/

/*
StateP nullState = new State();
	nullState->alphabet = regexParser->alphabet;
	nullState->regDes = "NULL";

	StateP state = new State(nullState);
	cout<<state->transitions[regexParser->alphabet.at(0)].at(0)->regDes<<endl;
*/