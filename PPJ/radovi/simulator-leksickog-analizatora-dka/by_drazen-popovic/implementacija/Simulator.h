#ifndef Sim_h
#define Sim_h
#include "DKA.h"
#include <vector>
using namespace std;

class uniformTab
{
public:
	vector<char*> lexicClasses;
	vector<char*> lexicInds;
	void add(char *class_, char *ind_);
};
class Simulator
{
public:
	Simulator(void);
	bool easy;
	//DKA po kojemu nas simulator radi!
	DKA* baseDKA;
	uniformTab uniTab;
	vector<char> input;
	vector<char> alphabet;
	//algoritam, oznake
	int pocetak;
	int zavrsetak;
	int posljedni;
	char* izraz;
	//najvaznije
	void run();
	void printUniTab();
	~Simulator(void);
private:
	void printStat();
	void getStrongestReg(vector<StateP> states, char* designation);
	int isAlphabet(char);
	void error(char*);
};


#endif