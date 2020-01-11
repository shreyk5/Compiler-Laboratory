%{
	#include <stdio.h>
	#include <stdlib.h>
	int flag,cntf,cnti;
	FILE *file;
%}

number [0-9]+
float [0-9]+[/.][0-9]+
int [0-9]+
newline [\n]
char [A-Za-z0-9]
%%

{float} {cntf++;}
{int} {cnti++;}
{number} {printf("number\n");}

%%
int yywrap()
{
	return 1;
}

int main()
{
	cnti = cntf = 0 ;
	file = fopen("input.txt","r");
	yyin = file;
	yylex();
	printf("Number of floating pt : %d, Number of int :%d",cntf,cnti);
	return 0;	
}
