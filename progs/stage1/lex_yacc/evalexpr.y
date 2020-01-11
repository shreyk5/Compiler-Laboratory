%{
	#include<stdio.h>
%}

%token DIGIT NEWLINE
%left '+'
%left '-'
%left '*'

%%
start : expr NEWLINE {printf("Value = %d",$1);};
expr : expr '+' expr {$$ = $1 + $3;};
expr : expr '*' expr {$$ = $1 * $3;};
expr : expr '-' expr {$$ = $1 - $3;};
expr : '(' expr ')'  {$$ = $2;};
expr : DIGIT 		 {$$ = $1;};
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
