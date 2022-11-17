import lex
import re

tokens = (
    # rezervirane rijeci
    'AUTO',
    'BREAK',
    'CASE',
    'CHAR',
    'CONST',
    'CONTINUE',
    'DEFAULT',    
    'DO',
    'DOUBLE',
    'ELSE',
    'ENUM',
    'EXTERN',
    'FLOAT',
    'FOR',
    'GOTO',
    'IF',
    'INT',
    'LONG',
    'REGISTER',
    'RETURN',
    'SHORT',
    'SIGNED',
    'SIZEOF',
    'STATIC',
    'STRUCT',
    'SWITCH',
    'TYPEDEF',
    'UNION',
    'UNSIGNED',
    'VOID',
    'VOLATILE',
    'WHILE',

    # specijalni znakovi
    'COMMA',
    'COLON',
    'SEMICOLON',
    'LPAREN',
    'RPAREN',
    'LBRACKET',
    'RBRACKET',
    'LBRACE',
    'RBRACE',
    'ASSIGN',
    'GREATER',
    'LESS',
    'EQ',
    'NOT_EQ',
    'GREATER_EQ',
    'LESS_EQ',
    'DOUBLE_PLUS',
    'DOUBLE_MINUS',
    'PLUS',
    'MINUS',
    'TIMES',
    'DIV',
    'MODULO',
    'DOUBLE_AMPERSAND',
    'DOUBLE_PIPE',
    'EXCLAMATION',
    'AMPERSAND',
    'PIPE',
    'CARET',
    'ASTERISK',
    'QUESTION',
    'TILDE',
    'POUND',
    'DOT',
    'ELLIPSIS',
    'ARROW',
    'SHIFT_LEFT',
    'SHIFT_RIGHT',
    'EQ_PLUS',
    'EQ_MINUS',
    'EQ_TIMES',
    'EQ_DIV',
    'EQ_MODULO',
    'EQ_PIPE',
    'EQ_AMPERSAND',
    'EQ_CARET',
    'EQ_SHIFT_LEFT',
    'EQ_SHIFT_RIGHT',

    # tokeni za kasniju definiciju
    'ID',
    'FNUMBER',    
    'INUMBER',
    'STRING',
    'CHARACTER',
    )

#rezervirane rijeci

rezervirane_rijeci = {
    'auto' : 'AUTO',
    'break' : 'BREAK',
    'case' : 'CASE',
    'char' : 'CHAR',
    'const' : 'CONST',
    'continue' : 'CONTINUE',
    'default' : 'DEFAULT',    
    'do' : 'DO',
    'double' : 'DOUBLE',
    'else' : 'ELSE',
    'enum' : 'ENUM',
    'extern' : 'EXTERN',
    'float' : 'FLOAT',
    'for' : 'FOR',
    'goto' : 'GOTO',
    'if' : 'IF',
    'int' : 'INT',
    'long' : 'LONG',
    'register' : 'REGISTER',
    'return' : 'RETURN',
    'short' : 'SHORT',
    'signed' : 'SIGNED',
    'sizeof' : 'SIZEOF',
    'static' : 'STATIC',
    'struct' : 'STRUCT',
    'switch' : 'SWITCH',
    'typedef' : 'TYPEDEF',
    'union' : 'UNION',
    'unsigned' : 'UNSIGNED',
    'void' : 'VOID',
    'volatile' : 'VOLATILE',
    'while' : 'WHILE'
}

#specijalni znakovi

t_COMMA = r','
t_COLON = r':'
t_SEMICOLON = r';'
t_LPAREN = r'\('
t_RPAREN = r'\)'
t_LBRACKET = r'\['
t_RBRACKET = r'\]'
t_LBRACE = r'{'
t_RBRACE = r'}'
t_ASSIGN = r'='
t_GREATER = r'>'
t_LESS = r'<'
t_EQ = r'=='
t_NOT_EQ = r'!='
t_GREATER_EQ = r'>='
t_LESS_EQ = r'<='
t_DOUBLE_PLUS = r'\+\+'
t_DOUBLE_MINUS = r'--'
t_PLUS = r'\+'
t_MINUS = r'-'
t_TIMES = r'\*'
t_DIV = r'/(?!\*)'
t_MODULO = r'%'
t_DOUBLE_AMPERSAND = r'&&'
t_DOUBLE_PIPE = r'\|\|'
t_EXCLAMATION = r'!'
t_AMPERSAND = r'&'
t_PIPE = r'\|'
t_CARET = r'^'
t_ASTERISK = r'\*'
t_QUESTION = r'\?'
t_TILDE = r'~'
t_POUND = r'\#'
t_ELLIPSIS = r'\.\.\.'
t_DOT = r'\.'
t_ARROW = r'->'
t_SHIFT_LEFT = r'<<'
t_SHIFT_RIGHT = r'>>'
t_EQ_PLUS = r'\+='
t_EQ_MINUS = r'-='
t_EQ_TIMES = r'\*='
t_EQ_DIV = r'/='
t_EQ_MODULO = r'%='
t_EQ_PIPE = r'\|='
t_EQ_AMPERSAND = r'&='
t_EQ_CARET = r'\^='
t_EQ_SHIFT_LEFT = r'<<='
t_EQ_SHIFT_RIGHT = r'>>='

#definicija slozenih tokena

def t_ID(t):
    r'[A-Za-z_][\w]*'
    if rezervirane_rijeci.has_key(t.value):
        t.type = rezervirane_rijeci[t.value]
    return t

def t_FNUMBER(t):
    r'((0(?!\d))|([1-9]\d*))((\.\d+(e[+-]?\d+)?)|(e[+-]?\d+))'
    return t


def t_INUMBER(t):
    r'0(?!\d)|([1-9]\d*)'
    return t

def t_CHARACTER(t):
    r"'\w'"
    return t

def t_STRING(t):
    r'"[^\n]*?(?<!\\)"'
    temp_str = t.value.replace(r'\\', '')
    return t

#tokeni koji se ignoriraju

def t_WHITESPACE(t):
    r'[ \t]+'
    pass

def t_NEWLINE(t):
    r'\n+'
    pass

def t_COMMENT(t):
    r'/\*[\w\W]*?\*/'
    pass

#holder za error-handling bez kojeg se javlja upozorenje

def t_error(t):
    pass


def run_lexer():
    
    import sys
    file = open(sys.argv[1])
    #file = open("IME_DATOTEKE")
    lines = file.readlines()
    file.close()
    strings = ""
    KROS = {}
    konst = []
    iden = []
    linije = 0
    for i in lines:
        strings += i
        linije += 1
    lex.input(strings)
    
    
    while True:     
        token = lex.token()
        if not token: break
        if token.value not in KROS.keys():
            KROS[token.value] = 0
          
        if token.type == 'ID':
			iden.append(token.value)
        if token.type in ['CHARACTER', 'INUMBER', 'FNUMBER', 'STRING']:
            konst.append(token.value)
        
        if token.type not in ['CHARACTER', 'INUMBER', 'FNUMBER', 'STRING', 'ID']:
			KROS[token.value] += 1
	
        
    izlaz = open("izlaz.txt", "w")
        
    izlaz.write("Broj razlicitih identifikatora: %d\n" % (len(set(iden))))
    izlaz.write("Broj razlicitih konstanti: %d\n" % (len(set(konst))))
    izlaz.write("Broj linija: %d\n" % linije)
    izlaz.write("Broj pojavljivanja raznih kljucnih rijeci, operatora i specijalnih znakova:\n")
    for k,v in KROS.iteritems():
		if v > 0:
			izlaz.write("'%s': %d\n" % (k,v))
    izlaz.close()

lex.lex()

if __name__ == '__main__':
    run_lexer()

