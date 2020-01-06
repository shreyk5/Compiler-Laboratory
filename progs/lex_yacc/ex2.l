%{
	#include<stdio.h>
	#include"y.tab.h"
%}

charac [a-zA-Z]+

%%
{charac} {yylval.str = strdup(yytext); return STRING;}
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
