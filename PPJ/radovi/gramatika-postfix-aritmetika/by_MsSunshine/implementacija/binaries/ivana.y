%{
    int[] regs = new int[26];
    int _base=10;
%}

%start list

%token DIGIT 


%left '+' '-'
%left '*' '/' '%'
%left UMINUS

%%

list    :   /*empty */
        |   list stat '\n'
        |   list error '\n'
                {
                    yyerrok();
                }
        ;

stat    :   expr
                {
                    
                }
       
        ;

expr   :
           expr expr '*'
                {
			
			System.Console.WriteLine("MUL R"+($1-10)+" , R"+($2-10)+" , R"+(_base-10));
			
                    $$ = _base++;
                }
        |   expr  expr '/'
                {
			
			System.Console.WriteLine("DIV R"+($1-10)+" , R"+($2-10)+" , R"+(_base-10));
			
                    $$ = _base++;
                }
        
        |   expr  expr '+'
                {
			
		System.Console.WriteLine("ADD R"+($1-10)+" , R"+($2-10)+" , R"+(_base-10));
			
                    $$ = _base++;
                }
        |   expr '-'
                {
			
			System.Console.WriteLine("SUB "+ 0 +" , R"+($1-10)+" , R"+(_base-10));
			
                    $$ = _base++;
                }
           
        |   number
        ;

number  :   DIGIT

                {
			System.Console.WriteLine("MOVE "+$1+" R"+(_base-10));
			
                    $$ = _base++;
                   
                }
       
        ;

%%

    Parser() : base(null) { }

    static void Main(string[] args)
    {
        Parser parser = new Parser();
        
        System.IO.TextReader reader;
        if (args.Length > 0)
            reader = new System.IO.StreamReader(args[0]);
        else
            reader = System.Console.In;
            
        parser.Scanner = new Lexer(reader);
        //parser.Trace = true;
        
        parser.Parse();
    }


    /*
     * Copied from GPPG documentation.
     */
    class Lexer: QUT.Gppg.AbstractScanner<int,LexLocation>
    {
         private System.IO.TextReader reader;
    
         //
         // Version 1.2.0 needed the following code.
         // In V1.2.1 the base class provides this empty default.
         //
         // public override LexLocation yylloc { 
         //     get { return null; } 
         //     set { /* skip */; }
         // }
         //
    
         public Lexer(System.IO.TextReader reader)
         {
             this.reader = reader;
         }
    
         public override int yylex()
         {
             char a;
             int ord = reader.Read();
             //
             // Must check for EOF
             //
             if (ord == -1)
                 return (int)Tokens.EOF;
             else
                 a = (char)ord;
    
             if (a == '\n')
                return a;
             else if (char.IsWhiteSpace(a))
                 return yylex();
             else if (char.IsDigit(a))
             {
                 yylval = a - '0';
                 return (int)Tokens.DIGIT;
             }
             
             else
                 switch (a)
                 {
                     case '+':
                     case '-':
                     case '*':
                     case '/':
		     
                    
                         return a;
                     default:
                         Console.Error.WriteLine("neispravan unos za: '{0}'", a);
                         return yylex();
                 }
         }
    
         public override void yyerror(string format, params object[] args)
         {
             Console.Error.WriteLine(format, args);
         }
    }
