%{
	#include <stdio.h>
	#include <stdlib.h>
	int flag,cntw,cntl,cntc;
	FILE *file;
%}

number [0-9]+
tab [ \t]
newline [\n]
char [A-Za-z0-9]
%%

{tab} {cntw++;}
{newline} {cntw++; cntl++;}
{char} {cntc++;}
{number} {printf("number\n");}

%%
int yywrap()
{
	return 1;
}

int main()
{
	cntw = cntl = cntc = 0 ;
	file = fopen("input.txt","r");
	yyin = file;
	yylex();
	printf("Words : %d, Characters : %d, Lines : %d",cntw,cntc,cntl);
	return 0;	
}
