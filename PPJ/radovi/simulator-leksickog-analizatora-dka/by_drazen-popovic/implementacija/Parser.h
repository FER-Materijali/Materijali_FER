#ifndef Parser_h
#define Parser_h
#include <stdio.h>

class Parser
{
public:
	Parser(void);
	void setFile( FILE* pFile);
	virtual void Parse()= 0;
	virtual void print() = 0;
	~Parser(void);
protected:
	FILE* fileToParse_;
};

#endif