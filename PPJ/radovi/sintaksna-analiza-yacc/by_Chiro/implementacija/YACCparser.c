/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 5 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* YACCparser.c
* C source file generated from YACCparser.y.
* 
* Date: 12/19/08
* Time: 16:39:45
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yywpars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#line 1 ".\\YACCparser.y"

/****************************************************************************
YACCparser.y
ParserWizard generated YACC file.

Date: 17. prosinac 2008
****************************************************************************/

#line 49 "YACCparser.c"
/* repeated because of possible precompiled header */
#include <yywpars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#include ".\YACCparser.h"

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/* (state) stack */
#if (YYSTACK_SIZE) != 0
static yywstack_t YYNEAR yywstack[(YYSTACK_SIZE)];
yywstack_t YYFAR *YYNEAR YYDCDECL yywsstackptr = yywstack;
yywstack_t YYFAR *YYNEAR YYDCDECL yywstackptr = yywstack;
#else
yywstack_t YYFAR *YYNEAR YYDCDECL yywsstackptr = NULL;
yywstack_t YYFAR *YYNEAR YYDCDECL yywstackptr = NULL;
#endif

/* attribute stack */
#if (YYSTACK_SIZE) != 0
static YYSTYPE YYNEAR yywattributestack[(YYSTACK_SIZE)];
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yywsattributestackptr = yywattributestack;
void YYFAR *YYNEAR YYDCDECL yywattributestackptr = yywattributestack;
#else
char YYFAR *YYNEAR YYDCDECL yywsattributestackptr = (char YYFAR *) yywattributestack;
char YYFAR *YYNEAR YYDCDECL yywattributestackptr = (char YYFAR *) yywattributestack;
#endif
#else
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yywsattributestackptr = NULL;
void YYFAR *YYNEAR YYDCDECL yywattributestackptr = NULL;
#else
char YYFAR *YYNEAR YYDCDECL yywsattributestackptr = NULL;
char YYFAR *YYNEAR YYDCDECL yywattributestackptr = NULL;
#endif
#endif

int YYNEAR YYDCDECL yywsstack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yywstack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yywstack_max = (YYSTACK_MAX);

/* attributes */
YYSTYPE YYNEAR yywval;
YYSTYPE YYNEAR yywlval;
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yywvalptr = &yywval;
void YYFAR *YYNEAR YYDCDECL yywlvalptr = &yywlval;
#else
char YYFAR *YYNEAR YYDCDECL yywvalptr = (char *) &yywval;
char YYFAR *YYNEAR YYDCDECL yywlvalptr = (char *) &yywlval;
#endif

size_t YYNEAR YYDCDECL yywattribute_size = sizeof(YYSTYPE);

/* yywattribute */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static YYSTYPE YYFAR *yywattribute1(int index)
#else
static YYSTYPE YYFAR *yywattribute1(index)
int index;
#endif
{
	YYSTYPE YYFAR *p = &((YYSTYPE YYFAR *) yywattributestackptr)[yywtop + index];
	return p;
}
#define yywattribute(index) (*yywattribute1(index))
#else
#define yywattribute(index) (((YYSTYPE YYFAR *) yywattributestackptr)[yywtop + (index)])
#endif

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static void yywinitdebug(YYSTYPE YYFAR **p, int count)
#else
static void yywinitdebug(p, count)
YYSTYPE YYFAR **p;
int count;
#endif
{
	int i;
	yyassert(p != NULL);
	yyassert(count >= 1);

	for (i = 0; i < count; i++) {
		p[i] = &((YYSTYPE YYFAR *) yywattributestackptr)[yywtop + i - (count - 1)];
	}
}
#endif

#ifdef YYPROTOTYPE
void YYCDECL yywparseraction(int action)
#else
void YYCDECL yywparseraction(action)
int action;
#endif
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yywinitdebug(yya, 2);
#endif
			{
#line 32 ".\\YACCparser.y"
 kopiraj C kod u izlaznu datoteku 
#line 175 "YACCparser.c"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yywinitdebug(yya, 2);
#endif
			{
#line 35 ".\\YACCparser.y"
 kopiraj sve definirano u izlaznu datoteku 
#line 188 "YACCparser.c"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yywinitdebug(yya, 2);
#endif
			{
#line 69 ".\\YACCparser.y"
 izvrsi neku radnju s obzirom na kod akcije 
#line 201 "YACCparser.c"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yywinitdebug(yya, 2);
#endif
			{
#line 77 ".\\YACCparser.y"
 ovom akcijom prodi ostatak specifikacije te kopiraj kod u izlaznu datoteku 
#line 214 "YACCparser.c"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}
#ifdef YYDEBUG
YYCONST yywsymbol_t YYNEARFAR YYBASED_CODE YYDCDECL yywsymbol[] = {
	{ L"$end", 0 },
	{ L"\':\'", 58 },
	{ L"\';\'", 59 },
	{ L"\'<\'", 60 },
	{ L"\'>\'", 62 },
	{ L"\'{\'", 123 },
	{ L"\'|\'", 124 },
	{ L"\'}\'", 125 },
	{ L"error", 65536 },
	{ L"IDENTIFIKATOR", 65537 },
	{ L"POC_IDENTIFIKATOR", 65538 },
	{ L"TOKEN", 65539 },
	{ L"START", 65540 },
	{ L"PREC", 65541 },
	{ L"UNION", 65542 },
	{ L"LEFT", 65543 },
	{ L"RIGHT", 65544 },
	{ L"NONASSOC", 65545 },
	{ L"TYPE", 65546 },
	{ L"POZ", 65547 },
	{ L"PZZ", 65548 },
	{ L"DP", 65549 },
	{ NULL, 0 }
};

YYCONST wchar_t *YYCONST YYNEARFAR YYBASED_CODE YYDCDECL yywrule[] = {
	L"$accept: cjeline",
	L"cjeline: deklaracije DP pravila_prevodenja c_procedure",
	L"deklaracije:",
	L"deklaracije: c_deklaracije unija poc_produkcija dzzp",
	L"c_deklaracije:",
	L"$$1:",
	L"c_deklaracije: POZ $$1 PZZ",
	L"unija:",
	L"unija: UNION",
	L"poc_produkcija:",
	L"poc_produkcija: START IDENTIFIKATOR",
	L"dzzp: ponavljaj kljucne_rijeci oznaka niz",
	L"ponavljaj:",
	L"ponavljaj: dzzp",
	L"kljucne_rijeci: TOKEN",
	L"kljucne_rijeci: TYPE",
	L"kljucne_rijeci: LEFT",
	L"kljucne_rijeci: RIGHT",
	L"kljucne_rijeci: NONASSOC",
	L"oznaka:",
	L"oznaka: \'<\' IDENTIFIKATOR \'>\'",
	L"niz: izraz",
	L"niz: niz izraz",
	L"izraz: IDENTIFIKATOR",
	L"pravila_prevodenja: POC_IDENTIFIKATOR \':\' dsp prednost",
	L"pravila_prevodenja: pravila_prevodenja produkcija",
	L"produkcija: POC_IDENTIFIKATOR \':\' dsp prednost",
	L"produkcija: \'|\' dsp prednost",
	L"dsp:",
	L"dsp: IDENTIFIKATOR dsp",
	L"dsp: dsp akcija",
	L"$$2:",
	L"akcija: \'{\' $$2 \'}\'",
	L"prednost:",
	L"prednost: PREC IDENTIFIKATOR",
	L"prednost: PREC IDENTIFIKATOR akcija",
	L"prednost: prednost \';\'",
	L"c_procedure:",
	L"c_procedure: DP"
};
#endif

YYCONST yywreduction_t YYNEARFAR YYBASED_CODE YYDCDECL yywreduction[] = {
	{ 0, 1, -1 },
	{ 1, 4, -1 },
	{ 2, 0, -1 },
	{ 2, 4, -1 },
	{ 3, 0, -1 },
	{ 4, 0, 0 },
	{ 3, 3, -1 },
	{ 5, 0, -1 },
	{ 5, 1, 1 },
	{ 6, 0, -1 },
	{ 6, 2, -1 },
	{ 7, 4, -1 },
	{ 8, 0, -1 },
	{ 8, 1, -1 },
	{ 9, 1, -1 },
	{ 9, 1, -1 },
	{ 9, 1, -1 },
	{ 9, 1, -1 },
	{ 9, 1, -1 },
	{ 10, 0, -1 },
	{ 10, 3, -1 },
	{ 11, 1, -1 },
	{ 11, 2, -1 },
	{ 12, 1, -1 },
	{ 13, 4, -1 },
	{ 13, 2, -1 },
	{ 14, 4, -1 },
	{ 14, 3, -1 },
	{ 15, 0, -1 },
	{ 15, 2, -1 },
	{ 15, 2, -1 },
	{ 17, 0, 2 },
	{ 16, 3, -1 },
	{ 18, 0, -1 },
	{ 18, 2, -1 },
	{ 18, 3, -1 },
	{ 18, 2, -1 },
	{ 19, 0, -1 },
	{ 19, 1, 3 }
};

int YYNEAR YYDCDECL yywtokenaction_size = 42;
YYCONST yywtokenaction_t YYNEARFAR YYBASED_CODE YYDCDECL yywtokenaction[] = {
	{ 22, YYAT_SHIFT, 27 },
	{ 54, YYAT_SHIFT, 16 },
	{ 57, YYAT_SHIFT, 35 },
	{ 56, YYAT_SHIFT, 35 },
	{ 22, YYAT_SHIFT, 28 },
	{ 22, YYAT_SHIFT, 29 },
	{ 22, YYAT_SHIFT, 30 },
	{ 22, YYAT_SHIFT, 31 },
	{ 0, YYAT_SHIFT, 1 },
	{ 55, YYAT_SHIFT, 35 },
	{ 0, YYAT_REDUCE, 2 },
	{ 48, YYAT_SHIFT, 47 },
	{ 54, YYAT_SHIFT, 17 },
	{ 46, YYAT_SHIFT, 52 },
	{ 45, YYAT_SHIFT, 44 },
	{ 43, YYAT_SHIFT, 34 },
	{ 42, YYAT_SHIFT, 50 },
	{ 41, YYAT_SHIFT, 47 },
	{ 40, YYAT_SHIFT, 46 },
	{ 39, YYAT_SHIFT, 34 },
	{ 38, YYAT_SHIFT, 44 },
	{ 36, YYAT_SHIFT, 44 },
	{ 35, YYAT_SHIFT, 43 },
	{ 33, YYAT_SHIFT, 34 },
	{ 32, YYAT_SHIFT, 40 },
	{ 26, YYAT_SHIFT, 23 },
	{ 25, YYAT_SHIFT, 34 },
	{ 24, YYAT_SHIFT, 34 },
	{ 23, YYAT_SHIFT, 23 },
	{ 21, YYAT_REDUCE, 3 },
	{ 16, YYAT_SHIFT, 26 },
	{ 15, YYAT_SHIFT, 23 },
	{ 14, YYAT_SHIFT, 23 },
	{ 12, YYAT_SHIFT, 20 },
	{ 11, YYAT_SHIFT, 15 },
	{ 10, YYAT_SHIFT, 14 },
	{ 8, YYAT_SHIFT, 12 },
	{ 6, YYAT_SHIFT, 10 },
	{ 5, YYAT_SHIFT, 9 },
	{ 4, YYAT_SHIFT, 7 },
	{ 3, YYAT_SHIFT, 6 },
	{ 2, YYAT_ACCEPT, 0 }
};

YYCONST yywstateaction_t YYNEARFAR YYBASED_CODE YYDCDECL yywstateaction[] = {
	{ -65539, 1, YYAT_REDUCE, 4 },
	{ 0, 0, YYAT_REDUCE, 5 },
	{ 41, 1, YYAT_ERROR, 0 },
	{ -65509, 1, YYAT_ERROR, 0 },
	{ -65503, 1, YYAT_REDUCE, 7 },
	{ -65510, 1, YYAT_ERROR, 0 },
	{ -65501, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 8 },
	{ -65504, 1, YYAT_REDUCE, 9 },
	{ 0, 0, YYAT_REDUCE, 6 },
	{ -23, 1, YYAT_ERROR, 0 },
	{ -90, 1, YYAT_DEFAULT, 54 },
	{ -65504, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 12 },
	{ -65505, 1, YYAT_REDUCE, 28 },
	{ -65506, 1, YYAT_REDUCE, 28 },
	{ -28, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 38 },
	{ 0, 0, YYAT_REDUCE, 1 },
	{ 0, 0, YYAT_REDUCE, 25 },
	{ 0, 0, YYAT_REDUCE, 10 },
	{ -65520, 1, YYAT_REDUCE, 13 },
	{ -65539, 1, YYAT_ERROR, 0 },
	{ -65509, 1, YYAT_REDUCE, 28 },
	{ -96, 1, YYAT_DEFAULT, 55 },
	{ -97, 1, YYAT_DEFAULT, 56 },
	{ -65512, 1, YYAT_REDUCE, 28 },
	{ 0, 0, YYAT_REDUCE, 14 },
	{ 0, 0, YYAT_REDUCE, 16 },
	{ 0, 0, YYAT_REDUCE, 17 },
	{ 0, 0, YYAT_REDUCE, 18 },
	{ 0, 0, YYAT_REDUCE, 15 },
	{ -36, 1, YYAT_REDUCE, 19 },
	{ -100, 1, YYAT_REDUCE, 29 },
	{ 0, 0, YYAT_REDUCE, 31 },
	{ -65515, 1, YYAT_ERROR, 0 },
	{ -38, 1, YYAT_REDUCE, 24 },
	{ 0, 0, YYAT_REDUCE, 30 },
	{ -39, 1, YYAT_REDUCE, 27 },
	{ -104, 1, YYAT_DEFAULT, 57 },
	{ -65519, 1, YYAT_ERROR, 0 },
	{ -65520, 1, YYAT_ERROR, 0 },
	{ -109, 1, YYAT_ERROR, 0 },
	{ -108, 1, YYAT_REDUCE, 34 },
	{ 0, 0, YYAT_REDUCE, 36 },
	{ -45, 1, YYAT_REDUCE, 26 },
	{ -49, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 23 },
	{ -65526, 1, YYAT_REDUCE, 11 },
	{ 0, 0, YYAT_REDUCE, 21 },
	{ 0, 0, YYAT_REDUCE, 32 },
	{ 0, 0, YYAT_REDUCE, 35 },
	{ 0, 0, YYAT_REDUCE, 20 },
	{ 0, 0, YYAT_REDUCE, 22 },
	{ -65537, 1, YYAT_REDUCE, 37 },
	{ -65532, 1, YYAT_REDUCE, 33 },
	{ -65538, 1, YYAT_REDUCE, 33 },
	{ -65539, 1, YYAT_REDUCE, 33 }
};

int YYNEAR YYDCDECL yywnontermgoto_size = 26;

YYCONST yywnontermgoto_t YYNEARFAR YYBASED_CODE YYDCDECL yywnontermgoto[] = {
	{ 11, 19 },
	{ 0, 2 },
	{ 0, 3 },
	{ 0, 4 },
	{ 48, 53 },
	{ 11, 18 },
	{ 41, 48 },
	{ 41, 49 },
	{ 13, 21 },
	{ 13, 22 },
	{ 43, 51 },
	{ 39, 45 },
	{ 34, 42 },
	{ 33, 37 },
	{ 32, 41 },
	{ 26, 39 },
	{ 25, 38 },
	{ 24, 36 },
	{ 23, 33 },
	{ 22, 32 },
	{ 15, 25 },
	{ 14, 24 },
	{ 8, 13 },
	{ 6, 11 },
	{ 4, 8 },
	{ 1, 5 }
};

YYCONST yywstategoto_t YYNEARFAR YYBASED_CODE YYDCDECL yywstategoto[] = {
	{ 0, -1 },
	{ 21, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 19, -1 },
	{ 0, -1 },
	{ 10, -1 },
	{ 0, -1 },
	{ 16, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -14, -1 },
	{ 0, -1 },
	{ 1, -1 },
	{ 6, -1 },
	{ 5, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 10, -1 },
	{ 3, -1 },
	{ -1, 39 },
	{ -2, 39 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 4, -1 },
	{ -3, -1 },
	{ -5, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -7, 33 },
	{ 0, -1 },
	{ -5, -1 },
	{ 0, -1 },
	{ -6, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -8, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 }
};

YYCONST yywdestructor_t YYNEARFAR *YYNEAR YYDCDECL yywdestructorptr = NULL;

YYCONST yywtokendest_t YYNEARFAR *YYNEAR YYDCDECL yywtokendestptr = NULL;
int YYNEAR YYDCDECL yywtokendest_size = 0;

YYCONST yywtokendestbase_t YYNEARFAR *YYNEAR YYDCDECL yywtokendestbaseptr = NULL;
int YYNEAR YYDCDECL yywtokendestbase_size = 0;
#line 79 ".\\YACCparser.y"





