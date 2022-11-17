D			[0-9]
L			[a-zA-Z_]
%{
#include <stdio.h>
#include <string.h>
int main()
{
	  yylex();
}
FILE * kros;
FILE * iden;
FILE * kons;
FILE * unif;
int br=1;

%}
%option noyywrap

%%
  		  	{iden = fopen ("iden.txt","w"); fclose(iden); kons = fopen ("kons.txt","w"); fclose(kons); kros = fopen("kros.txt","w"); iden = fopen ("iden.txt","a+"); kons = fopen ("kons.txt","a+"); unif = fopen ("unif.txt","w"); upiskros(kros);}
"<!--"				{ comment(); }

"description"			{ fprintf(unif,"KROS 1\n"); }
"service"			{ fprintf(unif,"KROS 2\n"); }
"endpoint"			{ fprintf(unif,"KROS 3\n"); }
"binding"			{ fprintf(unif,"KROS 4\n"); }
"operation"			{ fprintf(unif,"KROS 5\n"); }
"xml"				{ fprintf(unif,"KROS 6\n"); }
"schema"			{ fprintf(unif,"KROS 7\n"); }
"element"			{ fprintf(unif,"KROS 8\n"); }
"complexType"			{ fprintf(unif,"KROS 9\n"); }
"choice"			{ fprintf(unif,"KROS 10\n"); }
"any"				{ fprintf(unif,"KROS 11\n"); }
"anyAttribute"			{ fprintf(unif,"KROS 12\n"); }
"sequence"			{ fprintf(unif,"KROS 13\n"); }
"annotation"			{ fprintf(unif,"KROS 14\n"); }
"documentation"			{ fprintf(unif,"KROS 15\n"); }
"key"				{ fprintf(unif,"KROS 16\n"); }
"selector"			{ fprintf(unif,"KROS 17\n"); }
"field"				{ fprintf(unif,"KROS 18\n"); }
"extension"			{ fprintf(unif,"KROS 19\n"); }
"attribute"			{ fprintf(unif,"KROS 20\n"); }
"unique"			{ fprintf(unif,"KROS 21\n"); }
"complexContent"		{ fprintf(unif,"KROS 22\n"); }
"group"				{ fprintf(unif,"KROS 23\n"); }
"port"				{ fprintf(unif,"KROS 24\n"); }
"types"				{ fprintf(unif,"KROS 25\n"); }
"message"			{ fprintf(unif,"KROS 26\n"); }
"portType"			{ fprintf(unif,"KROS 27\n"); }
"simpleType"			{ fprintf(unif,"KROS 28\n"); }
"enumeration"			{ fprintf(unif,"KROS 29\n"); }
"restriction"			{ fprintf(unif,"KROS 30\n"); }
"all"				{ fprintf(unif,"KROS 31\n"); }
"wsdl"				{ fprintf(unif,"KROS 32\n"); }
"input"				{ fprintf(unif,"KROS 33\n"); }
"output"			{ fprintf(unif,"KROS 34\n"); }
"fault"				{ fprintf(unif,"KROS 35\n"); }
"part"				{ fprintf(unif,"KROS 36\n"); }
"definitions"			{ fprintf(unif,"KROS 37\n"); }
"address"			{ fprintf(unif,"KROS 38\n"); }
"xsd"				{ fprintf(unif,"KROS 39\n"); }
"xs"				{ fprintf(unif,"KROS 40\n"); }
"xsi"				{ fprintf(unif,"KROS 41\n"); }
"pattern"			{ fprintf(unif,"KROS 42\n"); }
"whiteSpace"			{ fprintf(unif,"KROS 43\n"); }
"length"			{ fprintf(unif,"KROS 44\n"); }
"fractionDigits"		{ fprintf(unif,"KROS 45\n"); }
"maxExclusive"			{ fprintf(unif,"KROS 46\n"); }
"maxInclusive"			{ fprintf(unif,"KROS 47\n"); }
"maxLength"			{ fprintf(unif,"KROS 48\n"); }
"minExclusive"			{ fprintf(unif,"KROS 49\n"); }
"minInclusive"			{ fprintf(unif,"KROS 50\n"); }
"minLength"			{ fprintf(unif,"KROS 51\n"); }
"totalDigits"			{ fprintf(unif,"KROS 52\n"); }
"simpleContent"			{ fprintf(unif,"KROS 53\n"); }
"maxOccurs"			{ fprintf(unif,"KROS 54\n"); }
"minOccurs"			{ fprintf(unif,"KROS 55\n"); }
"name"				{ fprintf(unif,"KROS 56\n"); }
"attributeGroup"		{ fprintf(unif,"KROS 57\n"); }
"substitutionGroup"		{ fprintf(unif,"KROS 58\n"); }
"base"				{ fprintf(unif,"KROS 59\n"); }
"appInfo"			{ fprintf(unif,"KROS 60\n"); }
"import"			{ fprintf(unif,"KROS 61\n"); }
"include"			{ fprintf(unif,"KROS 62\n"); }
"keyref"			{ fprintf(unif,"KROS 63\n"); }
"list"				{ fprintf(unif,"KROS 64\n"); }
"notation"			{ fprintf(unif,"KROS 65\n"); }
"redefine"			{ fprintf(unif,"KROS 66\n"); }
"union"				{ fprintf(unif,"KROS 67\n"); }
"body"				{ fprintf(unif,"KROS 68\n"); }
"type"				{ fprintf(unif,"KROS 69\n"); }
"</"				{ fprintf(unif,"KROS 70\n"); }
"<?"				{ fprintf(unif,"KROS 71\n"); }
"<"				{ fprintf(unif,"KROS 72\n"); }
"="				{ fprintf(unif,"KROS 73\n"); }
"/>"				{ fprintf(unif,"KROS 74\n"); }
"?>"				{ fprintf(unif,"KROS 75\n"); }
">"				{ fprintf(unif,"KROS 76\n"); }
":"				{ fprintf(unif,"KROS 77\n"); }
"/"				{ fprintf(unif,"KROS 78\n"); }


{L}({L}|{D})*			{ idn(unif, iden); }

L?'(\\.|[^\\'])+'		{ konstanta(unif, kons); }

L?\"(\\.|[^\\"])*\"		{ konstanta(unif, kons); }

[ \t\v\f]				{ ; /*brisanje praznina*/ }
[ \n]					{ br++; /*preskakanje novog reda i brojanje zbog javljanja greske*/}
.					{ printf("greska(%d): %s\n",br, yytext); /*oporavak od greske*/ }

%%

upiskros(FILE * kros)
{
 fprintf(kros,"description\n");
 fprintf(kros,"service\n");
 fprintf(kros,"endpoint\n");
 fprintf(kros,"binding\n");
 fprintf(kros,"operation\n");
 fprintf(kros,"xml\n");
 fprintf(kros,"schema\n");
 fprintf(kros,"element\n");
 fprintf(kros,"complexType\n");
 fprintf(kros,"choice\n");
 fprintf(kros,"any\n");
 fprintf(kros,"anyAttribute\n");
 fprintf(kros,"sequence\n");
 fprintf(kros,"annotation\n");
 fprintf(kros,"documentation\n");
 fprintf(kros,"key\n");
 fprintf(kros,"selector\n");
 fprintf(kros,"field\n");
 fprintf(kros,"extension\n");
 fprintf(kros,"attribute\n");
 fprintf(kros,"unique\n");
 fprintf(kros,"complexContent\n");
 fprintf(kros,"group\n");
 fprintf(kros,"port\n");
 fprintf(kros,"types\n");
 fprintf(kros,"message\n");
 fprintf(kros,"portType\n");
 fprintf(kros,"simpleType\n");
 fprintf(kros,"enumeration\n");
 fprintf(kros,"restriction\n");
 fprintf(kros,"all\n");
 fprintf(kros,"wsdl\n");
 fprintf(kros,"input\n");
 fprintf(kros,"output\n");
 fprintf(kros,"fault\n");
 fprintf(kros,"part\n");
 fprintf(kros,"definitions\n");
 fprintf(kros,"address\n");
 fprintf(kros,"xsd\n");
 fprintf(kros,"xs\n");
 fprintf(kros,"xsi\n");
 fprintf(kros,"pattern\n");
 fprintf(kros,"whiteSpace\n");
 fprintf(kros,"length\n");
 fprintf(kros,"fractionDigits\n");
 fprintf(kros,"maxExclusive\n");
 fprintf(kros,"maxInclusive\n");
 fprintf(kros,"maxLength\n");
 fprintf(kros,"minExclusive\n");
 fprintf(kros,"minInclusive\n");
 fprintf(kros,"minLength\n");
 fprintf(kros,"totalDigits\n");
 fprintf(kros,"simpleContent\n");
 fprintf(kros,"maxOccurs\n");
 fprintf(kros,"minOccurs\n");
 fprintf(kros,"name\n");
 fprintf(kros,"attributeGroup\n");
 fprintf(kros,"substitutionGroup\n");
 fprintf(kros,"base\n");
 fprintf(kros,"appInfo\n");
 fprintf(kros,"import\n");
 fprintf(kros,"include\n");
 fprintf(kros,"keyref\n");
 fprintf(kros,"list\n");
 fprintf(kros,"notation\n");
 fprintf(kros,"redifine\n");
 fprintf(kros,"union\n");
 fprintf(kros,"body\n");
 fprintf(kros,"type\n");
 fprintf(kros,"</\n");
 fprintf(kros,"<?\n");
 fprintf(kros,"<\n");
 fprintf(kros,"=\n");
 fprintf(kros,"/>\n");
 fprintf(kros,"?>\n");
 fprintf(kros,">\n");
 fprintf(kros,":\n");
 fprintf(kros,"/\n");
}

idn(FILE * unif, FILE * iden)
{
	 char tmp[50];
	 int flag = 0;
	 int count = 1;
	 rewind(iden);
	 while(fgets(tmp,49,iden)!=NULL)
	 {
		tmp[strlen(tmp)-1]='\0';
		if (strcmp(tmp,yytext)==0) flag=1;
		if (flag==0) count++;
	 }
	 if (flag==0) fprintf(iden,"%s\n",yytext);
	 fprintf(unif, "IDN %d\n", count);
}

konstanta(FILE * unif, FILE * kons)
{
	 char tmp[50];
	 int flag = 0;
	 int count = 1;
	 rewind(kons);
	 while(fgets(tmp,49,kons)!=NULL)
	 {
		tmp[strlen(tmp)-1]='\0';
		if (strcmp(tmp,yytext)==0) flag=1;
		if (flag==0) count++;
	 }
	 if (flag==0) fprintf(kons,"%s\n",yytext);
	 fprintf(unif, "KON %d\n", count);
}


comment()
{
	char c, c1, c2;
loop:
	while ((c = input()) != '-' && c != 0)
		//putchar(c);
	c1 = input();
	c2 = input();
	if (((c != '-') || (c1 != '-') || (c2 != '>')) && (c != 0))
	{
		unput(c2);
		unput(c1);
		//putchar(c);
		goto loop;
	}	
}

