%namespace ListCollection

%{
%}

%start program

%token KONST IDENT
%token WHILE DO IF ELSE FOR
%token RETURN CONTINUE BREAK DEFAULT
%token VAR NEW THIS FUNCTION
%token SWITCH CASE
%token OR AND LE GE EQ NEQ

%nonassoc IFX
%nonassoc ELSE

%left '>' '<' LE GE EQ NEQ
%left '+' '-'
%left '*' '/'



%%

program				:	osnovni_elementi
					;

osnovni_elementi    :	osnovni_element
					| 	osnovni_elementi osnovni_element
					;
					
osnovni_element 	:	naredba
					|	funkcija
					;					
											
naredba 			:	'{' '}'
					|	'{' naredbe '}'
					|	VAR deklaracija_var ';'
					|	';'
					|	pridruzivanje ';'
					|	IF '(' izraz ')' naredba ELSE naredba
					|	IF '(' izraz ')' naredba %prec IFX
					|	DO naredba WHILE '(' izraz ')'
					|	WHILE '(' izraz ')' naredba
					|	FOR '(' izraz ';' izraz ';' izraz ')' naredba
					|	FOR '(' VAR deklaracija_var ';' izraz ';' izraz ')' naredba
					|	CONTINUE IDENT ';'
					|	CONTINUE ';'
					|	BREAK IDENT ';'
					|	BREAK ';'
					|	RETURN izraz ';'
					|   SWITCH '(' izraz ')' '{' case '}'	
					;
					
naredbe				:	naredba
					|	naredbe naredba
					;

izraz				:	lijeva_strana '=' or
					|	or
					;

izraz_zagrade		: 	izraz
					|	izraz_zagrade ',' izraz
					|
					;

pridruzivanje		:	lijeva_strana '=' or
					|	lijeva_strana 
					;

or					:	and
					|	or OR and
					;
					
and					:	jednakost
					|	and AND jednakost
					;
			
jednakost 			:  	usporedbe
					|	jednakost EQ usporedbe
					|	jednakost NEQ usporedbe
					;
			
usporedbe			:	arit_nize
					|	usporedbe '<' arit_nize
					|	usporedbe '>' arit_nize
					|	usporedbe LE arit_nize
					|	usporedbe GE arit_nize
					;
			
arit_nize 			: 	arit_vise
					|	arit_nize '+' arit_vise
					| 	arit_nize '-' arit_vise
					;
					
arit_vise			:	unarni
					|	unarni '*' arit_vise
					|	unarni '/' arit_vise
					;
					
unarni				:	lijeva_strana
					| 	'+' unarni 
					| 	'-' unarni 
					| 	'!' unarni 
					;
			
lijeva_strana 		:	NEW poziv
					|	poziv	
					;
					
osnovni_izraz		:	THIS
					|   IDENT
					|	KONST
					| 	'(' izraz ')'
					|	funkcija_izraz					
					;
			
poziv 				: 	osnovni_izraz
		            |	poziv argumenti
		            | 	poziv '[' izraz_zagrade ']'
		            |	poziv '.' IDENT
					;

argumenti 			:	'(' ')'
					| 	'(' argumenti_lista ')'
					;

argumenti_lista 	:	izraz
					| 	argumenti_lista ',' izraz
					;
							
funkcija			:	FUNCTION IDENT '(' parametri_fun ')' '{' tijelo_fun '}'
					|   FUNCTION IDENT '(' ')' '{' tijelo_fun '}'
					;
				
funkcija_izraz		:	FUNCTION '(' parametri_fun ')' '{' tijelo_fun '}'
					|   FUNCTION '(' ')' '{' tijelo_fun '}'
					;
			
parametri_fun		:	IDENT
					|	parametri_fun ',' IDENT
					;

tijelo_fun			:	osnovni_elementi
					|
					;
											
deklaracija_var 	:	varijabla
					|	deklaracija_var ',' varijabla
					;
					
varijabla			:	IDENT
					|	IDENT '=' or	
					;
					
case 				:	case_izrazi
					|	case_izrazi default_izraz
					|	case_izrazi default_izraz case_izrazi
					|	default_izraz case_izrazi
					|	default_izraz 
					;

case_izrazi    		:	case_izraz
					|	case_izrazi case_izraz
					;
				
case_izraz			:   CASE IDENT ':' naredbe
					|   CASE IDENT ':' 
					|   CASE KONST ':' naredbe
					|   CASE KONST ':' 
					;
				
default_izraz		:	DEFAULT ':'
					|	DEFAULT ':' naredbe
					;
				
				
%%
		
 
        public void Parsiraj()
        {
            Parser parser = new Parser();

            parser.scanner = new Scanner();

            parser.Parse();
        }

      
        class Scanner : gppg.IScanner<int, LexLocation>
        {

            public override int yylex()
            {
                string unznak = Glavni.mojaForma.mojSkener.Tabl_unif_znak.SljedZnak();
                if (unznak.Length > 1)
                {
                    foreach (string str in Enum.GetNames(typeof(Tokens)))
                    {
                        if (str == unznak) return (int)Enum.Parse(typeof(Tokens), unznak);
                    }
                    Glavni.Ispisi("GRESKA U DIZAJNU PROGRAMA!!!!! - VISEZNAKOVNI TOKEN NIJE PREPOZNAT");
                }
                else
                {
                    return Convert.ToChar(unznak);
                    Glavni.Ispisi("GRESKA U DIZAJNU PROGRAMA!!!!! - JEDNOZNAKOVNI TOKEN NIJE PREPOZNAT");
                }
                return 0;
            }

            public override void yyerror(string format, params object[] args)
            {
                Glavni.Ispisi(format);
            }
        
		}