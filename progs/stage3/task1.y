%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include "task1.h"
    FILE *fp;
    FILE *fp_read;
    #include "task2.c"
    extern FILE* yyin;
    int yylex(void); 
%}

%union
{
    struct tnode* node;
};


%token START END NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV IF THEN ELSE ENDIF LT GT EQ NEQ GTE LTE
%type<node> program SLIST stmt asgStmt inputStmt outputStmt expr START END NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV
%left PLUS MINUS
%left MUL DIV 


%%
program : START SLIST END   {GenerateCode($2); Interpret($2);}
        | START END         {}
        ;

SLIST : stmt        {$$ = $1;}
    | SLIST stmt    {$$ = createTree(0,connector_node,-1,NULL,$1,$2,NULL);}
    ;

stmt : asgStmt      {$$ = $1;}
    | inputStmt     {$$ = $1;}
    | outputStmt    {$$ = $1;}
    | IfStmt		{$$ = $1;}
    ;

asgStmt : ASSIGN expr ';'           {CheckType($1,$2);
									$$ = createTree(0,assign_node,int_type,NULL,$1,$2);};

inputStmt : READ '(' ID ')' ';'     {$$ = createTree(0,read_node,NULL,$3,NULL,NULL);};
outputStmt : WRITE '(' expr ')' ';' {$$ = createTree(0,write_node,NULL,$3,NULL,NULL);};

IfStmt : 	IF '(' BoolStmt ')' THEN SLIST ENDIF	{$$ = createTree(0,if_node,-1,NULL,$3,$6,NULL);}

		|	IF '(' BoolStmt ')' THEN SLIST ELSE SLIST ENDIF	{$$ = createTree(0,if_node,-1,NULL,$3,$6,$8);}
		;

expr : expr PLUS expr   {CheckType($1,$3);
						$$ = createTree(0,plus_node,int_type,NULL,$1,$3,NULL);}

    |  expr MINUS expr  {CheckType($1,$3);
    					$$ = createTree(0,minus_node,int_type,NULL,$1,$3,NULL);}

    |  expr MUL expr    {CheckType($1,$3);
    					$$ = createTree(0,mul_node,int_type,NULL,$1,$3,NULL);}

    |  expr DIV expr    {CheckType($1,$3);
    					$$ = createTree(0,div_node,int_type,NULL,$1,$3,NULL);}

    | '(' expr ')'      {$$ = $2;}
    |  ID               {$$ = $1;}
    |  NUM              {$$ = $1;}
    ;

BoolStmt :  |  expr LT expr     {CheckType($1,$3);
    							$$ = createTree(0,lt_node,bool_type,NULL,$1,$3,NULL);}

    		|  expr GT expr     {CheckType($1,$3);
    							$$ = createTree(0,gt_node,bool_type,NULL,$1,$3,NULL);}

    		|  expr EQ expr     {CheckType($1,$3);
    							$$ = createTree(0,eq_node,bool_type,NULL,$1,$3,NULL);}

    		|  expr NEQ expr    {CheckType($1,$3);
    							$$ = createTree(0,neq_node,bool_type,NULL,$1,$3,NULL);}

    		|  expr LTE expr    {CheckType($1,$3);
    							$$ = createTree(0,lte_node,bool_type,NULL,$1,$3,NULL);}

    		|  expr GTE expr    {CheckType($1,$3);
    							$$ = createTree(0,gte_node,bool_type,NULL,$1,$3,NULL);}
    		;

%%

void yyerror(char *S)
{
    printf("\n%s",S);
}

int main()
{
    fp = fopen("/home/shrey/xsm_expl/xsm_progs/task2.xsm","w");
    fp_read = fopen("input.txt","r");
    yyin = fp_read; 
    yyparse();

    return 0;
}