#include "Infix2PostfixConverter.h"
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
Infix2PostfixConverter::Infix2PostfixConverter(void)
{
}

Infix2PostfixConverter::~Infix2PostfixConverter(void)
{
}
void Infix2PostfixConverter::convert(char *infixString, char *postfixString)
{
  int i, endanchor, j = 0;
  
  regex = infixString;
  pregex = postfixString;
  if (*regex == '^') {
    //printf("^");
	*pregex = '^';
	pregex++;
    regex++;
  }
  i = strlen(regex)-1;
  endanchor = i >= 0 && regex[i] == '$' && (i == 0 || regex[i-1] != '\\');
  if (endanchor) regex[i] = '\0';
  parse();
  *pregex = 0;
  //if (endanchor) printf("$");
  //printf("\n");
}




void Infix2PostfixConverter::fatal(char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(-1);
}


void Infix2PostfixConverter::parse(void) {
  c = *(regex++);
  E();
  if (c != '\0') fatal("bogus char beyond end of expression!");
}


void Infix2PostfixConverter::E(void) {
  T();
  while (c == '|') {
    c = *(regex++);
    T();
    //printf("|");
	*pregex = '|';
	pregex++;
  }
}


void Infix2PostfixConverter::T(void) {
  F();
  while (strchr(")|*+?", c) == NULL) {  /* '(' or LITERAL */
    F();
    //printf("&");
	*pregex = '&';
	pregex++;
  }
}

void Infix2PostfixConverter::F(void) {
  G();
  while (c != '\0' && strchr("*+?",c) != NULL) {
    //printf("%c", c);
	*pregex = c;
	pregex++;
    c = *(regex++);
  }
}

void Infix2PostfixConverter::G(void) {
  if (c == '\0') fatal("unexpected end of expression!");
  if (c == '\\') {  /* escape */
    c = *(regex++);
    if (c == '\0') fatal("escape at end of string");
   // printf("\\%c", c);
	*pregex = c;
	pregex++;
    c = *(regex++);
  } else if (strchr("()|*+?", c) == NULL) {  /* non-meta chacter */
	  if (c == '&') 
	  {
		 //printf("\\&");
		*pregex = '&';
		pregex++;
	  }
	  else 
	  {
		//  printf("%c", c);
		*pregex = c;
		pregex++;
	  }
    c = *(regex++);
  } else if (c == '(') {
    c = *(regex++);
    E();
    if (c != ')') fatal("mismatched parantheses!");
    c = *(regex++);
  } else
    fatal("bogus expression!");
}

