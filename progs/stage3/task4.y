%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include "task4.h"
    FILE *fp;
   	FILE *fp_read;
    
    #include "task4.c"
    extern FILE* yyin;
    int yylex(void); 
%}

%union
{
    struct tnode* node;
};


%token START END NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV IF THEN ELSE ENDIF LT GT EQ NEQ GTE LTE DO WHILE ENDWHILE BREAK CONTINUE

%type<node> program SLIST stmt asgStmt inputStmt outputStmt BoolStmt IfStmt expr START END NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV WhileStmt BREAK CONTINUE

%left PLUS MINUS
%left MUL DIV 
%nonassoc LT GT EQ NEQ GTE LTE

%%
program : START SLIST END   {GenerateCode($2);}
        | START END         {}
        ;

SLIST : stmt        {$$ = $1;}
    | SLIST stmt    {$$ = createTree(0,connector_node,-1,NULL,$1,$2,NULL);}
    ;

stmt : asgStmt      {$$ = $1;}
    | inputStmt     {$$ = $1;}
    | outputStmt    {$$ = $1;}
    | IfStmt		{$$ = $1;}
    | WhileStmt 	{$$ = $1;}
    | BREAK  ';'    {$$ = $1;}
    | CONTINUE ';'  {$$ = $1;}
    ;

asgStmt : ID ASSIGN expr ';'      {CheckType($1,$2);
									$$ = createTree(0,assign_node,int_type,NULL,$1,$3,NULL);};

inputStmt : READ '(' ID ')' ';'     {$$ = createTree(0,read_node,-1,NULL,$3,NULL,NULL);};
outputStmt : WRITE '(' expr ')' ';' {$$ = createTree(0,write_node,-1,NULL,$3,NULL,NULL);};

IfStmt : 	IF '(' BoolStmt ')' THEN SLIST ENDIF ';'	{$$ = createTree(0,if_node,-1,NULL,$3,$6,NULL);}

		|	IF '(' BoolStmt ')' THEN SLIST ELSE SLIST ENDIF	';' {$$ = createTree(0,ifElse_node,-1,NULL,$3,$6,$8);}
		;

WhileStmt : WHILE '(' BoolStmt ')' DO SLIST ENDWHILE ';'	{$$ = createTree(0,while_node,-1,NULL,$3,$6,NULL);}

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

BoolStmt : 	   expr LT expr     {CheckType($1,$3);
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

int main(int argc,char* argv[])
{
    if(argc<2)
    {
        printf("No test program\n");
        exit(1);
    }
    fp = fopen("/home/shrey/xsm_expl/progs/stage3/input.xsm","w");
    fp_read = fopen(argv[1],"r");
    yyin = fp_read; 
    yyparse();

    return 0;
}