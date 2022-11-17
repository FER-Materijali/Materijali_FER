#include "InputParser.h"
#include <stdio.h>
InputParser::InputParser(void)
{
}

InputParser::~InputParser(void)
{
}
void InputParser::Parse()
{
	char in[MAX_IN];
	int flagDouble = 0, flagSingle = 0;

	int i = 0, inChar;
	while( fscanf(fileToParse_, "%c", &inChar) != EOF ) 
	{
		if( inChar != '\r')
			in[i++] = inChar; 
	}
	in[i] = 0;
	
	for(int j = 0, size = strlen( in ); j < size; j++)
	{
		if( flagDouble == 0 && flagSingle == 0)
		{
			if( in[j] != ' ' && in[j] != '\n' && in[j] != '\t')
			{
				
				if( in[j] == '"' )
				{
					source.push_back( in[j] );
					flagDouble = 1;
					continue;
				}
				else if( in[j] == '\'')
				{				
					source.push_back( in[j] );
					flagSingle = 1;
					continue;
				}
				else source.push_back( in[j] );
			}
		}
		else if( flagDouble == 1)
		{
			if( in[j] == '\\' && in[j+1] == '"' )
			{
				source.push_back( in[j++] );
				source.push_back( in[j] );
				continue;
			}
			else if( in[j] == 34 )
			{
				source.push_back( in[j] );
				flagDouble = 0;
				continue;
			}
			else
			{
				source.push_back( in[j] );
			}
		}
		
	}
		
	
}

void InputParser::print()
{
	printf("\nPOCETAK:\n");
	for(int i = 0; i < source.size(); i++)
	{
		printf("%c", source.at(i));
	}
	printf("\nKRAJ\n");
}