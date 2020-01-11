%{
	#include<stdio.h>
%}

%union
{
    char ch;
}

%token CHAR NEWLINE
%left '+'
%left '-'
%left '*'

%type<ch>CHAR

%%
start : expr NEWLINE {};
expr : expr '+' expr {printf("+");};
expr : expr '*' expr {printf("*");};
expr : expr '-' expr {printf("-");};
expr : '(' expr ')'  {};
expr : CHAR		 {printf("%c",$1);};
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
