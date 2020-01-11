%{
	#include <stdio.h>
	#include <stdlib.h>
	int flag;
	FILE *file;
%}

number [0-9]+
digit [0-9]
%%

{digit} {printf("dig");}
{number} {printf("number\n");}


%%
int yywrap()
{
	if(flag == 0){
		flag = 1;
		yyin = stdin;
		return 0;
	}
	else
		return 1;
}

int main()
{
	flag = 0;
	file = fopen("input.txt","r");
	yyin = file;
	yylex();
	return 0;	
}
