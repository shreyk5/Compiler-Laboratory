%{
	#include<stdio.h>
	#include"y.tab.h"
%}

charac [a-zA-Z]

%%
{charac} {yylval.ch = *strdup(yytext); return CHAR;}
"+"  {return *yytext;}
"-"  {return *yytext;}
"*"  {return *yytext;}
[\n] {return NEWLINE;}
.    {return *yytext;}
%%

int yywrap()
{
	return 1;
}
