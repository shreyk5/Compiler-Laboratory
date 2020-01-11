%{
	#include <stdio.h>
	#include <stdlib.h>
	int flag,cntw,cntl,cntc;
	FILE *file;
%}

special_word [A-Z][a-zA-Z][a-zA-Z][\n \t]

%%

{special_word} {cntw++;}

%%
int yywrap()
{
	return 1;
}

int main()
{
	cntw = 0 ;
	file = fopen("input.txt","r");
	yyin = file;
	yylex();
	printf("Words : %d",cntw);
	return 0;	
}
