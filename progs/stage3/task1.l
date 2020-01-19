%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include "y.tab.h"
    #include "task1.h"
    #define num_node 1
    #define var_node 2
    #define bool_type 17
    #define int_type 18

    int n;
    char *str;
%}

num [0-9]+
asgg [a-z][ \t]*[=]

%%
"begin" {return START;}
"end"   {return END;}
"read"  {return READ;}
"write" {return WRITE;}
"if"    {return IF;}
"then"  {return THEN;}
"else"  {return ELSE;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do"    {return DO;}
"endwhile"  {return ENDWHILE;}
[a-z]   { str = strdup(yytext);  yylval.node = createTree(0,var_node,int_type,str,(tnode*)NULL,(tnode*)NULL,(tnode*)NULL); return ID;  }
{num}   {n = atoi(yytext); yylval.node = createTree(n,num_node,int_type,(char*)NULL,(tnode*)NULL,(tnode*)NULL,(tnode*)NULL); return NUM;}
"+"     {return PLUS;}
"-"     {return MINUS;}
"*"     {return MUL;}
"/"     {return DIV;}
"="     {return ASSIGN;}
"<"     {return LT;}
">"     {return GT;}
"=="    {return EQ;}
"!="    {return NEQ;}
"<="    {return LTE;}
">="    {return GTE;}
[();]   {return *yytext;}
[\n]    {}
[\t]    {}
.       {}
%%

int yywrap()
{
    return 1;
}