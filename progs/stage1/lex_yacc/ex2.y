%{
	#include<stdio.h>
%}

%union
{
    char* str;
}

%token STRING NEWLINE
%left '+'
%left '-'
%left '*'

%type<str>STRING

%%
start : expr NEWLINE {};
expr : expr '+' expr {printf("+");};
expr : expr '*' expr {printf("*");};
expr : expr '-' expr {printf("-");};
expr : '(' expr ')'  {};
expr : STRING		 {printf("%s ",$1);};
%%

void yyerror(char *S)
{
	printf("%s",S);
}

int main()
{
	yyparse();
	return 1;
}
