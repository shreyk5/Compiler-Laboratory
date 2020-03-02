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

%%
"begin" {return START;}
"end"   {return END;}
"decl"	{return DECL;}
"type"  {return TYPE;}
"endtype"   {return ENDTYPE;}
"alloc" {return ALLOC;}
"free"  {return FREE;}
"initialize"    {yylval.node = createTree(0,NULL,init_node,TLookup("void"),NULL,NULL,NULL,NULL); return INITIALIZE;}
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
"break" {yylval.node = createTree(0,NULL,break_node,TLookup("void"),NULL,NULL,NULL,NULL); return BREAK;}
"continue" {yylval.node = createTree(0,NULL,continue_node,TLookup("void"),NULL,NULL,NULL,NULL); return CONTINUE;}

[_a-zA-Z][_a-zA-Z0-9]* { 
                            str = strdup(yytext); 
                            yylval.node = createTree(0,NULL,var_node,TLookup("int"),str,(tnode*)NULL,(tnode*)NULL,(tnode*)NULL);                                                                                                                     
                            return ID;      
                       }

{num}   {n = atoi(yytext); yylval.node = createTree(n,NULL,num_node,TLookup("int"),(char*)NULL,(tnode*)NULL,(tnode*)NULL,(tnode*)NULL); return NUM;}

[\"](.)*[\"] {

	//printf("%s\n",yytext);
	str = (char*)malloc(sizeof(char)*(yyleng));
	str = strdup(yytext);
	yylval.node = createTree(-1,str,str_node,TLookup("string"),NULL,(tnode*)NULL,(tnode*)NULL,(tnode*)NULL); 
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