%{
    #include<stdio.h>
    #include"y.tab.h"
%}

char [a-zA-Z]+
num  [0-9]+
%%
{char} {return CHAR;}
{num}  {return NUM;}
[\n] {return NEWLINE;}
.    {return *yytext;} 
%%

int yywrap()
{
    return 1;
}