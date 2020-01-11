%{
	#include <stdio.h>
	#include <stdlib.h>
	int flag,cntw,cntl,cntc;
	FILE *file;
%}

single_line_comm [\/][\/][^\n]*
mult_comm [/][*][a-zA-Z0-9 \t\n]*[*][/]
new_line [\n]
%%

{single_line_comm} {printf("%s\n",yytext);}
{mult_comm} {printf("%s\n",yytext);}
(.) {}
{new_line} {}

%%
int yywrap()
{
	return 1;
}

int main()
{
	cntw = 0 ;
	file = fopen("input.txt","r");
	yyin = file;
	yylex();
	return 0;	
}
