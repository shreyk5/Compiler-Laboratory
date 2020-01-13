%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include "task1.h"
    FILE *fp;
    #include "task2.c"
    
    int yylex(void); 
%}

%union
{
    struct tnode* node;
};


%token START END NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV
%type<node> program SLIST stmt asgStmt inputStmt outputStmt expr START END NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV
%left PLUS MINUS
%left MUL DIV 


%%
program : START SLIST END   {GenerateCode($2);}
        | START END         {}
        ;

SLIST : stmt        {$$ = $1;}
    | SLIST stmt    {$$ = createTree(0,connector_node,NULL,$1,$2);}
    ;

stmt : asgStmt      {$$ = $1;}
    | inputStmt     {$$ = $1;}
    | outputStmt    {$$ = $1;}
    ;

asgStmt : ASSIGN expr               {$$ = createTree(0,assign_node,NULL,$1,$2);};
asgStmt : '(' ID ')' ASSIGN expr    {$$ = createTree(0,assign_node,NULL,$2,$5);};
inputStmt : READ '(' ID ')'         {$$ = createTree(0,read_node,NULL,$3,NULL);};
outputStmt : WRITE '(' expr ')'     {$$ = createTree(0,write_node,NULL,$3,NULL);};

expr : expr PLUS expr   {$$ = createTree(0,plus_node,NULL,$1,$3);}
    |  expr MINUS expr  {$$ = createTree(0,minus_node,NULL,$1,$3);}
    |  expr MUL expr    {$$ = createTree(0,mul_node,NULL,$1,$3);}
    |  expr DIV expr    {$$ = createTree(0,div_node,NULL,$1,$3);}
    | '(' expr ')'      {$$ = $2;}
    |  ID               {$$ = $1;}
    |  NUM              {$$ = $1;}
    ;
%%

void yyerror(char *S)
{
    printf("\n%s",S);
}

int main()
{
    fp = fopen("/home/shrey/xsm_expl/xsm_progs/task2.xsm","w");
    yyparse();

    return 0;
}