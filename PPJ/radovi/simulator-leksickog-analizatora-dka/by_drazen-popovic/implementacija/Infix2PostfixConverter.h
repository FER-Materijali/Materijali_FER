#pragma once

class Infix2PostfixConverter
{
public:
	Infix2PostfixConverter(void);
	void convert(char* infixString, char* postfixString);
	~Infix2PostfixConverter(void);
		
private:
	char *pregex;
	char *regex;  /* regular expression being parsed */
	int c;        /* look-ahead char for parse */
	void fatal(char *msg);
	void parse(void);
	void E();
	void T();
	void F();
	void G();
};
