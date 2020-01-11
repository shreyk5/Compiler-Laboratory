%{
	#include<stdio.h>
	#include"y.tab.h"
%}

charac [a-zA-Z]+

%%
{charac} {yylval.str = strdup(yytext); return STRING;}
"+"  {yylval.str = strdup(yytext); return *yytext;}
"-"  {yylval.str = strdup(yytext); return *yytext;}
"*"  {yylval.str = strdup(yytext); return *yytext;}
[\n] {return NEWLINE;}
.    {return *yytext;}
%%

int yywrap()
{
	return 1;
}
