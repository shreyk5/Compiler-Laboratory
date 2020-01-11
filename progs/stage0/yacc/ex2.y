%{
    #include<stdio.h>
    int valid = 0;
%}

%token CHAR NUM NEWLINE

%%
start : var NEWLINE {valid = 1;};
var : CHAR var2;
var : CHAR;

var2 : NUM;
var2 : CHAR;
var2 : var2 CHAR;
var2 : var2 NUM;
%%

void yyerror(char *S)
{
    printf("%s\n",S);
}

int main()
{
    yyparse();
    if(valid)
        printf("Valid variable declaration");
    else
        printf("Invalid variable declaration");
    return 0;
}