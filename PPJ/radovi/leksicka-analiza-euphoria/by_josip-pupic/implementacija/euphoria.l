nista  ([" "\t\n]+)
real ([0-9]+"."[0-9]*)|([0-9]+"."[0-9]*E("+"|"-")?[0-9]+)
brojka [0-9]+
idn [a-zA-Z][a-zA-Z0-9_]* 
string "\""[^\"\n]*"\""
komentar([-][-]+[ _a-zA-Z][ _0-9a-zA-Z]*[\n])
hex ([#][0-9A-F]+)

%{
int brKROS=1;
int brKON=1;
int brIDN=1;

void dodaj(char *tip, int br);
void dodajKROS(char *s);
void dodajIDN(char *s);
void dodajKON(char *s);
void pretraziKROS(char *s);
void pretraziIDN(char *s);



int yywrap(void){
  return 1;
}
int main(int argc, char *argv[])
{
if((yyin=fopen(argv[1],"r"))==NULL) {
printf("Nemogu otvoriti ulaznu datoteku.\n");
exit(1);}
yylex();
fclose(yyin);
return 0;
}

%}


%%

"and"          |
"as"            |
"break"		|
"by"		|
"case"		|
"constant"	|
"continue"	|
"do"		|
"else"		|
"elsedef"	|
"elsif"		|
"elsifdef"	|
"end"		|
"entry"		|
"enum"		|
"exit"		|
"export"	|
"for"		|
"function"	|
"global"	|
"goto"		|
if		|
"ifdef"		|
"include"	|
"label"		|
"loop"		|
"not"		|
"or"		|
"override"	|
"procedure"	|
"public"	|
"retry"		|
"return"	|
"switch"	|
"then"		|
"to"		|
"type"		|
"until"		|
"while"		|
"with"		|
"without"	|
"xor"		|
"abort"		|
"and_bits"	|
"append"	|
"arctan"	|
"atom"		|
"c_func"	|
"c_proc"	|
"call"		|
"call_func"	|
"call_proc"	|
"clear_screen"	|
"close"		|
"command_line"	|
"compare"	|
"cos"		|
"date"		|
"equal"		|
"find"		|
"find_from"	|
"floor"		|
"get_key"	|
"get_pixel"	|
"getc"		|
"getenv"	|
"gets"		|	
"hash"		|
"head"		|
"include_paths"	|
"insert"	|
"integer"	|
"length"	|
"log"		|
"machine_func"	|
"machine_proc"	|
"match"		|
"match_from"	|
"mem_copy"	|
"mem_set"	|
"not_bits"	|
"object"	|
"open"		|
"option_switches" |
"or_bits"	|
"peek"		|
"peek_sting"	|
"peek2s"        |
"peek3u"        |
"peek4s"	|
"peek4u"	|
"pixel"		|
"platform"	|
poke		|
"poke2"		|
"poke4"		|
"position"	|
"power"		|
"prepend"	|
print |
"printf" |
"profile"       |
"puts" |
"rand" |
"remainder" |
"remove" |
"repeat" |
"replace" |
"routine_id" |
"sequence" |
"sin" |
"splice" |
"sprintf" |
"sqrt" |
"system" |
"system_exec" |
"tan" |
"tail" |
"task_clock_start" |
"task_clock_stop" |
"task_create" |
"task_list" |
"task_schedule" |
"task_self" |
"task_status" |
"task_suspend" |
"task_yield" |
"time" |
"trace" |
"warning" |
"xor_bits" |
"<=" |
">=" |
= |
"!=" |
"+" |
"-" |
"*" |
"/" |
"<" |
">" |
"{" |
"}" |
";" |
"("  | 
")"  |
"," |
"!" |
":" |
"." pretraziKROS(yytext);   


{nista}        {; }
{komentar}        {; }
{hex} |
{real} |
{brojka} |
{string}  {dodaj("KON   ",brKON++);dodajKON(yytext);}
{idn} pretraziIDN(yytext);
%%

void pretraziKROS(char *s){
 int x;
 char pom[20];
 int flag=0;
FILE *dat;
dat=fopen("tablicaKROS.txt","r");
if(dat!=NULL)
{
while (fscanf(dat,"%d %s\n",&x,&pom)!=EOF){
 if(strcmp(s,pom)==0){
   flag=1;
   break;}}

fclose(dat);}

if (flag==1) {dodaj("KROS   ",x); }

else {dodaj("KROS   ",brKROS++);dodajKROS(yytext);}

}

void pretraziIDN(char *s){
 int x;
 char pom[100];
 int flag=0;
FILE *dat;
dat=fopen("tablicaIDN.txt","r");
if(dat!=NULL)
{
while (fscanf(dat,"%d %s\n",&x,&pom)!=EOF){
 if(strcmp(s,pom)==0){
   flag=1;
   break;}}

fclose(dat);}

if (flag==1) {dodaj("IDN   ",x); }

else {dodaj("IDN   ",brIDN++);dodajIDN(yytext);}

}






void dodaj(char *tip, int br)
{
FILE *dat;

dat=fopen("izlaz.txt","a");
fputs(tip,dat);
fprintf (dat, "%d\n", br);

fclose(dat);

}


void dodajIDN(char *s)
{
FILE *dat;
char *pom="\n";
dat=fopen("tablicaIDN.txt","a");
fprintf (dat, "%d   ", brIDN-1);
fputs(s,dat);
fputs(pom,dat);
fclose(dat);

}

void dodajKON(char *s)
{
FILE *dat;
char *pom="\n";
dat=fopen("tablicaKON.txt","a");
fprintf (dat, "%d   ", brKON-1);
fputs(s,dat);
fputs(pom,dat);
fclose(dat);

}

void dodajKROS(char *s)
{
FILE *dat;
char *pom="\n";
dat=fopen("tablicaKROS.txt","a");
fprintf (dat, "%d   ", brKROS-1);
fputs(s,dat);
fputs(pom,dat);
fclose(dat);

}








