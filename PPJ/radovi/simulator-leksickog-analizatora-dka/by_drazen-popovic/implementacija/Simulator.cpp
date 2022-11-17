#include "Simulator.h"
#include <iostream>
using namespace std;

Simulator::Simulator(void)
{
	pocetak = 0;
	zavrsetak = -1; //posljedni procitani znak
	posljedni = 0;
	izraz="NULL";
	easy = false;
}

Simulator::~Simulator(void)
{
}

void Simulator::run()
{
	char trigger;
	baseDKA->reset();
	int size = input.size();
	for(;;)
	{
		
		
		
		if(baseDKA->empty == false)
		{
			if(baseDKA->acc == false)
			{
				zavrsetak++;
				printStat();
				if(zavrsetak == size)
				{
					cout<<"Kraj ulaznog spremnika!!!\n";
					baseDKA->reset();
					trigger = 0;
					baseDKA->next(trigger);
					continue;
				}
				trigger = input[zavrsetak];
				
				if( !isAlphabet(trigger) ) error("Nedozovoljeni znak!!!");
				
				if(easy == true) cin.get();
				//cout<<endl<<"->"<<trigger<<endl;
				baseDKA->next(trigger);
				continue;
			}
			else if(baseDKA->acc == true)
			{
				getStrongestReg( baseDKA->currentState, izraz);
				posljedni = zavrsetak++;
				printStat();
				if(zavrsetak == size) {
					cout<<"Kraj ulaznog spremnika!!!\n";
					baseDKA->reset();
					trigger = 0;
					baseDKA->next(trigger);
					continue;
					}

				trigger = input[zavrsetak];
				if( !isAlphabet(trigger) ) error("Nedozovoljeni znak!!!");
				
				if(easy == true) cin.get();
				//cout<<endl<<"->"<<trigger<<endl;
				baseDKA->next(trigger);
				continue;
				
			}
		}else
		{
			//ovdje moramo dodati uni row u uniTab
			char* jedinka = new char[posljedni - pocetak + 2];
			for(int ii = pocetak, iJed = 0; ii <= posljedni; ii++ ) 
			{
				jedinka[iJed++] = input[ii];
				jedinka[iJed] = 0;
			}
			
			uniTab.add(izraz, jedinka);
			delete jedinka;
			if( !strcmp(izraz, "NULL") )
			{
				zavrsetak = pocetak++;
				baseDKA->reset();
			}else
			{
			izraz = "NULL";
			pocetak = posljedni + 1;
			zavrsetak = posljedni;
			baseDKA->reset();//resetiramo i krecemo iz pocetka
			}
			if(trigger == 0) break;
		}
	}
}

void Simulator::printStat()
{
	cout.clear();
	vector<char> stog;
	//printam input koji analiziram
	cout<<"\nULAZ:";
	for(int i = 0; i < input.size(); i++) 
	{
		
		if(i == pocetak) 
		{
			stog.push_back('>');
			
		}
		if( i == zavrsetak)
		{
			stog.push_back('_');
		}
		stog.push_back(input[i]);
		if( i == zavrsetak)
		{
			stog.push_back('_');
		}
		if( i == posljedni)
		{
			stog.push_back('<');
		}
	}
	for(int i = 0; i < stog.size(); i++) cout<<stog[i];
	cout<<endl;
	
	//printam kazaljke
	cout<<"Pocetak: "<<pocetak<<'\t'<<"Zavrsetak: "<<zavrsetak<<'\t'<<"Posljedni: "<<posljedni<<endl;
	
	//printam vrijedece izraze
	cout<<"Izraz: "<<izraz<<endl;
	
}

void Simulator::getStrongestReg(std::vector<StateP> states, char *des)
{
	char* strongest;
	int priority = 255; //broj regularnih izraza->TODO: povezati sa datotekom
	//mana: 255 regularnih
	for(int i = 0; i < states.size(); i++)
	{	
		//u turnir ulaze samo acc stanja :D
		if(states[i]->acc == false) continue;
		if(states[i]->regex->priority < priority)
		{
			strongest = states[i]->regex->designation;
			priority = states[i]->regex->priority;
		}
	}
	izraz = strongest;
}

int Simulator::isAlphabet( char alpha )
{
	for(int i = 0; i < alphabet.size(); i++)
	{
		if( alphabet.at(i) == alpha ) return 1;
	}
	return 0;
}

void Simulator::error(char *msg)
{
	std::cout<<msg<<std::endl;
	exit(-1);
}

void uniformTab::add(char *class_, char *ind_)
{
	char* lexicClass = new char[ strlen(class_) ];
	char* lexicInd = new char[ strlen(ind_) ];
	strcpy(lexicClass, class_);
	strcpy(lexicInd, ind_);
	lexicClasses.push_back( lexicClass );
	lexicInds.push_back( lexicInd );
}

void Simulator::printUniTab()
{
	cout<<"Tablica Uniformnih Znakova: \n"<<"Klasa"<<'\t'<<"Jedinka"<<endl;
	for(int i = 0; i < uniTab.lexicClasses.size(); i++) cout<<uniTab.lexicClasses[i]<<'\t'<<uniTab.lexicInds[i]<<endl;
}