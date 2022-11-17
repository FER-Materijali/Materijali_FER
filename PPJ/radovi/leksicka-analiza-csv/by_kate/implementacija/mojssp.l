broj				[0-9]+
predznak			[-+]
integer				{predznak}?{broj}
float				{predznak}?{broj}\.{broj}
znak				[^,\n"]+
znakUNavodnicima	\"[^"]*\"
praznina			[ \t]+


%{
#include <stdio.h>
#include <string.h>

int brKROS=1;
int brKON=1;
int brIDN=1;
int maxCijeliBroj = 0;


void dodajUniformni(char *tip, int rBr);
void pretraziKROS(char *s);
void dodajKROS(char *s);
void dodajKON(char *s);
void cijeliBroj(char *s, int brZnamenki);


int yywrap(void){
	return 1;
}

int main(int argc, char *argv[]){
	if((yyin=fopen("ulazna.txt","r")) == NULL) {
		printf("Ne mogu otvoriti ulaznu datoteku.\n");
		exit(1);
	}
	yylex();
	fclose(yyin);
	printf("Leksicka analiza je dovrsena\n");
	printf("Nejveci dopusteni cijeli broj je: %d", maxCijeliBroj);
	return 0;
}

%}


%%

,					|
\n					pretraziKROS(yytext);

{praznina}/[\n,"]	{;}

{integer}			cijeliBroj(yytext, yyleng);
{float}				|
{znak}				|
{znakUNavodnicima}	{dodajUniformni("KON   ",brKON++);dodajKON(yytext);}


%%


void dodajUniformni(char *tip, int rBr){
	FILE *uniformni;
	uniformni=fopen("uniformni_znakovi.txt","a");	//tablica uniformnih znakova
	fputs(tip, uniformni);				/*sprema klasu znaka*/
	fprintf (uniformni, "%d\n", rBr);	/*sprema redni broj u tablici znakova*/
	fclose(uniformni);
}

void dodajKROS(char *s){
	FILE *kros;
	char *pom = "\n";
	kros = fopen("kros.txt","a");
	fprintf(kros, "%d   ", brKROS-1);
	fputs(s, kros);
	fputs(pom, kros);
	fclose(kros);
}

void pretraziKROS(char *s){
	int rBr;
	char znak[40];
	int flag = 0;
	FILE *kros;
	kros = fopen("kros.txt", "r");
	if(kros!=NULL){
		while(fscanf(kros, "%d %s\n", &rBr, &znak) != EOF){
			if(strcmp(s, znak) == 0){
				flag = 1;
				break;
			}
		}
		fclose(kros);
	}

	if(flag == 1)
		dodajUniformni("KROS   ",rBr); 
	else {
		dodajUniformni("KROS   ", brKROS++);
		dodajKROS(s);
	}
}

void dodajKON(char *s){
	FILE *kon;
	char *pom = "\n";
	kon = fopen("kon.txt","a");
	fprintf(kon, "%d   ", brKON-1);
	fputs(s, kon);
	fputs(pom, kon);
	fclose(kon);
}

void cijeliBroj(char *s, int brZnamenki){
	if (brZnamenki < 10){
		dodajUniformni("KON   ",brKON++);
		dodajKON(yytext);
		
		int broj = atoi(s);
		if (broj > maxCijeliBroj)
			maxCijeliBroj = broj;
	}
	else
		printf("Greska! Cijeli broj %s ima vise od 10 znamenki.\n", s);
}

