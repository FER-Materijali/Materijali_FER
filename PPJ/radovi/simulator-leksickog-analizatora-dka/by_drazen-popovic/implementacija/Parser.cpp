#include "Parser.h"

Parser::Parser(void)
{
}

void Parser::setFile(FILE *pFile)
{
	fileToParse_ = pFile;
	Parse();
}
Parser::~Parser(void)
{
}
