%{
	#include<stdio.h>
	#include<stdlib.h>
	int lvl;
%}

%token IF

%%
expr : IF '{' expr '}' {lvl++;};
expr : IF '{''}' expr;
expr : expr IF '{''}';
expr : expr expr
expr : IF '{' '}' {lvl++;};

%%

#include"lex.yy.c"

int yyerror(char *S)
{
	printf("%s : error detected",S);
}

int main()
{
	lvl = 0;
	yyparse();
	printf("%d",lvl);
}
