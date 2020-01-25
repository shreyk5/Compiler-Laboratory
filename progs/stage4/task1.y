%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include "task1.h"
    FILE *fp;
   	FILE *fp_read;
    
    #include "task1.c"
    extern FILE* yyin;
    int yylex(void); 
%}

%union
{
    struct tnode* node;
};


%token START END DECL ENDDECL INT STR NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV IF THEN ELSE ENDIF LT GT EQ NEQ GTE LTE DO WHILE ENDWHILE BREAK CONTINUE REPEAT UNTIL STRING

%type<node> program SLIST stmt asgStmt inputStmt outputStmt BoolStmt IfStmt RepeatStmt expr START END NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV WhileStmt DoWhileStmt BREAK CONTINUE STRING

%left PLUS MINUS
%left MUL DIV 
%nonassoc LT GT EQ NEQ GTE LTE

%%
program : Declarations START SLIST END   {GenerateCode($3);}
        | Declarations START END         {}
        ;

SLIST : stmt        {$$ = $1;}
    | SLIST stmt    {$$ = createTree(0,NULL,connector_node,-1,NULL,$1,$2,NULL);}
    ;

Declarations : DECL DeclList ENDDECL {PrintSymbolTable();}
			|	DECL ENDDECL
			;

DeclList : DeclList Decl
		| Decl
		;

Decl : Type Varlist ';'

Type : INT {variable_type = int_type;}
	|  STR {variable_type = str_type;}
	;

Varlist : Varlist ',' ID  	{Install($3->varname,variable_type,1);}
		| ID 				{Install($1->varname,variable_type,1);}
		;			

stmt : asgStmt      {$$ = $1;}
    | inputStmt     {$$ = $1;}
    | outputStmt    {$$ = $1;}
    | IfStmt		{$$ = $1;}
    | WhileStmt 	{$$ = $1;}
    | DoWhileStmt   {$$ = $1;}
    | RepeatStmt    {$$ = $1;}
    | BREAK  ';'    {$$ = $1;}
    | CONTINUE ';'  {$$ = $1;}
    ;

asgStmt : ID ASSIGN expr ';'      {
									AssignCheckType($1,$3);
									$$ = createTree(0,NULL,assign_node,int_type,NULL,$1,$3,NULL);};

inputStmt : READ '(' ID ')' ';'     {$$ = createTree(0,NULL,read_node,-1,NULL,$3,NULL,NULL);};
outputStmt : WRITE '(' expr ')' ';' {$$ = createTree(0,NULL,write_node,-1,NULL,$3,NULL,NULL);};

IfStmt : 	IF '(' BoolStmt ')' THEN SLIST ENDIF ';'	{$$ = createTree(0,NULL,if_node,-1,NULL,$3,$6,NULL);}

		|	IF '(' BoolStmt ')' THEN SLIST ELSE SLIST ENDIF	';' {$$ = createTree(0,NULL,ifElse_node,-1,NULL,$3,$6,$8);}
		;

WhileStmt : WHILE '(' BoolStmt ')' DO SLIST ENDWHILE ';'	{$$ = createTree(0,NULL,while_node,-1,NULL,$3,$6,NULL);};

DoWhileStmt : DO '{' SLIST '}' WHILE '(' BoolStmt ')' ';'    {$$ = createTree(0,NULL,Dowhile_node,-1,NULL,$7,$3,NULL);};

RepeatStmt : REPEAT '{' SLIST '}' UNTIL '(' BoolStmt ')' ';'  {$$ = createTree(0,NULL,repeat_node,-1,NULL,$7,$3,NULL);};

expr : expr PLUS expr   {CheckType($1,$3);
						$$ = createTree(0,NULL,plus_node,int_type,NULL,$1,$3,NULL);}

    |  expr MINUS expr  {CheckType($1,$3);
    					$$ = createTree(0,NULL,minus_node,int_type,NULL,$1,$3,NULL);}

    |  expr MUL expr    {CheckType($1,$3);
    					$$ = createTree(0,NULL,mul_node,int_type,NULL,$1,$3,NULL);}

    |  expr DIV expr    {CheckType($1,$3);
    					$$ = createTree(0,NULL,div_node,int_type,NULL,$1,$3,NULL);}

    | '(' expr ')'      {$$ = $2;}
    |  ID               {$$ = $1;}
    |  NUM              {$$ = $1;}
    |  STRING    		{$$ = $1;}
    ;

BoolStmt : 	   expr LT expr     {CheckType($1,$3);
    							$$ = createTree(0,NULL,lt_node,bool_type,NULL,$1,$3,NULL);}

    		|  expr GT expr     {CheckType($1,$3);
    							$$ = createTree(0,NULL,gt_node,bool_type,NULL,$1,$3,NULL);}

    		|  expr EQ expr     {CheckType($1,$3);
    							$$ = createTree(0,NULL,eq_node,bool_type,NULL,$1,$3,NULL);}

    		|  expr NEQ expr    {CheckType($1,$3);
    							$$ = createTree(0,NULL,neq_node,bool_type,NULL,$1,$3,NULL);}

    		|  expr LTE expr    {CheckType($1,$3);
    							$$ = createTree(0,NULL,lte_node,bool_type,NULL,$1,$3,NULL);}

    		|  expr GTE expr    {CheckType($1,$3);
    							$$ = createTree(0,NULL,gte_node,bool_type,NULL,$1,$3,NULL);}
    		;

%%

void yyerror(char *S)
{
    printf("\n%s",S);
}

int main()
{
    fp = fopen("/home/shrey/xsm_expl/progs/stage4/input.xsm","w");
    fp_read = fopen("input.txt","r");
    yyin = fp_read;
    bind = 4096;

    yyparse();

    return 0;
}