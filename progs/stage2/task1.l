%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include "y.tab.h"
    #include "task1.h"
    #define num_node 1
    #define var_node 2

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
[a-z]   { str = strdup(yytext);  yylval.node = createTree(0,var_node,str,(tnode*)NULL,(tnode*)NULL); return ID;  }
{num}   {n = atoi(yytext); yylval.node = createTree(n,num_node,(char*)NULL,(tnode*)NULL,(tnode*)NULL); return NUM;}
{asgg}  {str = (char*)malloc(2 * sizeof(char)); str[0]= *yytext; str[1] = '\0'; yylval.node = createTree(0,var_node,str,(tnode*)NULL,(tnode*)NULL); return ASSIGN;}
"+"     {return PLUS;}
"-"     {return MINUS;}
"*"     {return MUL;}
"/"     {return DIV;}
"="     {return ASSIGN;}
[()]    {return *yytext;}
[\n]    {}
[\t]    {}
.       {}
%%

int yywrap()
{
    return 1;
}