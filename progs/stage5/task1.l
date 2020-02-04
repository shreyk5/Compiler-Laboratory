%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include "y.tab.h"
    #include "task1.h"

    int n;
    char *str;
%}

num [0-9]+
char [a-z]*
asgg [a-z][ \t]*[=]

%%
"begin" {return START;}
"end"   {return END;}
"decl"	{return DECL;}
"int"	{return INT;}
"str" 	{return STR;}
"enddecl"	{return ENDDECL;}
"main"	{return MAIN;}
"return" {return RETURN;}
"read"  {return READ;}
"write" {return WRITE;}
"if"    {return IF;}
"then"  {return THEN;}
"else"  {return ELSE;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do"    {return DO;}
"repeat" {return REPEAT;}
"until"	{return UNTIL;}
"endwhile"  {return ENDWHILE;}
"break" {yylval.node = createTree(0,NULL,break_node,-1,NULL,NULL,NULL,NULL); return BREAK;}
"continue" {yylval.node = createTree(0,NULL,continue_node,-1,NULL,NULL,NULL,NULL); return CONTINUE;}
[a-zA-Z][a-zA-Z0-9]*   { 
                            str = strdup(yytext); yylval.node = createTree(0,NULL,var_node,-1,str,(tnode*)NULL,(tnode*)NULL,(tnode*)NULL); 
                            if(LocalLookup(str)){yylval.node = createTree(0,NULL,var_node,LocalLookup(str)->type,str,(tnode*)NULL,(tnode*)NULL,(tnode*)NULL);} 
                            else if(ParamLookup(str)){yylval.node = createTree(0,NULL,var_node,ParamLookup(str)->type,str,(tnode*)NULL,(tnode*)NULL,(tnode*)NULL);} 
                            else if(Lookup2(str)){yylval.node = createTree(0,NULL,var_node,Lookup2(str)->type,str,(tnode*)NULL,(tnode*)NULL,(tnode*)NULL);} 
                            
                            return ID;      
                       }
{num}   {n = atoi(yytext); yylval.node = createTree(n,NULL,num_node,int_type,(char*)NULL,(tnode*)NULL,(tnode*)NULL,(tnode*)NULL); return NUM;}
[\"](.)*[\"] {

	//printf("%s\n",yytext);
	str = (char*)malloc(sizeof(char)*(yyleng));
	str = strdup(yytext);
	yylval.node = createTree(-1,str,str_node,str_type,NULL,(tnode*)NULL,(tnode*)NULL,(tnode*)NULL); 
	return STRING;
}
"+"     {return PLUS;}
"-"     {return MINUS;}
"*"     {return MUL;}
"/"     {return DIV;}
"%"     {return MOD;}
"="     {return ASSIGN;}
"<"     {return LT;}
">"     {return GT;}
"=="    {return EQ;}
"!="    {return NEQ;}
"<="    {return LTE;}
">="    {return GTE;}
[{}();,\[\]]   {return *yytext;}
[\n]    {line++;}
[\t]    {}
.       {}
%%

int yywrap()
{
    return 1;
}