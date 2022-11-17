%{
/****************************************************************************
YACCparser.y
ParserWizard generated YACC file.

Date: 17. prosinac 2008
****************************************************************************/
%}

%token IDENTIFIKATOR /* svi završni znakovi koji sadrže više od jednog simbola, pošto završne znakove koji sadrže samo jedan simbol 
nije potrebno definirati, te svi nezavršni znakovi */
%token POC_IDENTIFIKATOR /* nezavršni znakovi kojima zapoèinju produkcije gramatike */

%token TOKEN START PREC UNION LEFT RIGHT NONASSOC TYPE /* kljuène rijeèi */

%token POZ /* Postotak Otvorena Zagrada -> %{ */
%token PZZ /* Postotak Zatvorena Zagrada -> %} */
%token DP  /* Dvostruki Postotak -> %% */

%left IDENTIFIKATOR
%left '{'

%start cjeline

%%
cjeline : deklaracije DP pravila_prevodenja c_procedure
	    ;
deklaracije	: /* epsilon produkcija */
            | c_deklaracije unija poc_produkcija dzzp
            ;    
c_deklaracije : /* epsilon produkcija */
			  | POZ { kopiraj C kod u izlaznu datoteku } PZZ
			  ;
unija : /* epsilon produkcija */
      | UNION { kopiraj sve definirano u izlaznu datoteku }
      ;
poc_produkcija : /* epsilon produkcija */
			   | START IDENTIFIKATOR
			   ;
dzzp : ponavljaj kljucne_rijeci oznaka niz
     ;
ponavljaj : /* epsilon produkcija */
          | dzzp
          ;
kljucne_rijeci : TOKEN
               | TYPE
               | LEFT
               | RIGHT
               | NONASSOC
               ;
oznaka : /* epsilon produkcija */
       | '<' IDENTIFIKATOR '>'
       ;
niz : izraz
    | niz izraz
    ;
izraz : IDENTIFIKATOR /* napomena: završni znakovi se ne mogu definirati s %type */
      ;
pravila_prevodenja : POC_IDENTIFIKATOR ':' dsp prednost
                   | pravila_prevodenja produkcija
                   ;
produkcija : POC_IDENTIFIKATOR ':' dsp prednost
           | '|' dsp prednost
           ;
dsp : /* epsilon produkcija */
    | IDENTIFIKATOR dsp
    | dsp akcija %prec IDENTIFIKATOR
    ;
akcija : '{' { izvrsi neku radnju s obzirom na kod akcije } '}' 
       ;
prednost : /* epsilon produkcija */
         | PREC IDENTIFIKATOR
         | PREC IDENTIFIKATOR akcija
         | prednost ';'
         ;
c_procedure : /* epsilon produkcija */
            | DP { ovom akcijom prodi ostatak specifikacije te kopiraj kod u izlaznu datoteku }
            ;
%%



