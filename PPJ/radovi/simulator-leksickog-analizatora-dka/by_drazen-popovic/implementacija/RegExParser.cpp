#include "RegExParser.h"
#include <stdio.h>
#include "Infix2PostfixConverter.h"
RegExParser::RegExParser(void)
{
}

RegExParser::~RegExParser(void)
{
}

void RegExParser::Parse()
{
	Infix2PostfixConverter* converter = new Infix2PostfixConverter();
	char* des = new char[MAX_DES_CHAR];
	char* regex = new char[MAX_REG_CHAR];
	char* postRegex = new char[MAX_REG_CHAR];
	int priority = 0;
	while( fscanf(fileToParse_, "%s %s", des, regex) != EOF )
	{
		
		infixRegs.push_back( new RegExp(des, regex, priority ));
		converter->convert( regex, postRegex );
		postfixRegs.push_back( new RegExp(des, postRegex, priority++));

		for(int i = 0; i < strlen( regex ); i++)
		{
			if( regex[i] == '(' || regex[i] == ')' || regex[i] == '+' || regex[i] == '*' || regex[i] == '|')
			{
				continue;
			}
			else if( regex[i] == '\\')
			{
				i++;
				if( !isAlphabet( regex[i] ) )
				{
				alphabet.push_back( regex[i] );
				}
			}
			else
			{
				if( !isAlphabet( regex[i] ) )
				{
					alphabet.push_back( regex[i] );
				}
			}
		}
	}
}
void RegExParser::print()
{
	for(int i = 0; i < infixRegs.size(); i++)
	{
		printf("OZNAKA: %s\tIZRAZ: %s\tPOST:%s\n", infixRegs.at(i)->designation, infixRegs.at(i)->regex, postfixRegs.at(i)->regex);
	}
}

int RegExParser::isAlphabet( char alpha )
{
	for(int i = 0; i < alphabet.size(); i++)
	{
		if( alphabet.at(i) == alpha ) return 1;
	}
	return 0;
}

void RegExParser::printAlphabet()
{
	printf("ABECEDA:\n");
	for(int i = 0; i < alphabet.size(); i++)
	{
		printf("%c,",alphabet.at(i));
	}
	printf("\n");
}