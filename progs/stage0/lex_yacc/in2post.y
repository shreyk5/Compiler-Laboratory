%{
	#include<stdio.h>
%}

%token DIGIT NEWLINE

%%
start : expr NEWLINE { printf("Done\n");};
expr : expr '+' expr { printf("+ ");};
expr : expr '-' expr { printf("- ");};
expr : '(' expr ')' ;
expr : DIGIT         {printf("%d ",$1);};
%%

void yyerror(char *S)
{
	printf("%s\n",S);
}

int main()
{
	yyparse();
	return 1;
}
