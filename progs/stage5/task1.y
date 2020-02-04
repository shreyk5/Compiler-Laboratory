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


%token START END DECL ENDDECL MAIN INT STR NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV MOD IF THEN ELSE ENDIF LT GT EQ NEQ GTE LTE DO WHILE ENDWHILE BREAK CONTINUE REPEAT UNTIL STRING RETURN

%type<node> Program SLIST stmt asgStmt inputStmt outputStmt IfStmt RepeatStmt expr START END NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV WhileStmt DoWhileStmt BREAK CONTINUE STRING ArgList FDef Body RetStmt GDeclBlock FDefBlock MainBlock
DECL ENDDECL

%left PLUS MINUS
%left MUL DIV MOD
%nonassoc LT GT EQ NEQ GTE LTE
%start Program
%%

//---------------------------------PROGRAM-------------------------------------
Program : GDeclBlock FDefBlock MainBlock
		| GDeclBlock MainBlock
		| MainBlock
		;
//-----------------------------------------------------------------------------


//-------------------------------TYPE------------------------------------------

Type : INT     {variable_type = int_type;}
		|  STR {variable_type = str_type;}
		;
//-----------------------------------------------------------------------------


//---------------------------GLOBAL DECLARATION--------------------------------
GDeclBlock : DECL GDeclList ENDDECL	{GenerateHeader();
                                        PrintSymbolTable();}
			| DECL ENDDECL
			;

GDeclList : GDeclList GDecl
			| GDecl
			;

GDecl : Type GidList ';'
		;

GidList : GidList ',' Gid
		| Gid
		;

Gid : ID 					{Install($1->varname,variable_type,0,1);}
	| ID '[' NUM ']'		{Install($1->varname,variable_type,1,$3->val);}
	| ID '(' ParamList ')'	{
								Install($1->varname,variable_type,2,1);
								InsertParamList($1->varname);
                                clearParamList();	
							}

    | ID '(' ')'            {
                                Install($1->varname,variable_type,2,1);
                                InsertParamList($1->varname);
                                clearParamList();   
                            }
	;
//-----------------------------------------------------------------------------

//----------------------------FUNCTION DEFINITION------------------------------
FDefBlock : FDefBlock FDef
			| FDef
			;

FDef :  Type ID '(' ParamList ')' '{' LDeclBlock Body'}'	
		{
			CheckIfFunction($2->varname);
			CheckReturnType($2->varname,variable_type);
			CheckParamList($2->varname);
			InsertLST($2->varname);
			//PrintLST($2->varname);
			//PrintParamList($2->varname);
			ActRecordSetup($2 -> varname);

			MainCodeGen($8);

			PopLocalVariables($2->varname);

			fprintf(fp,"MOV BP,[SP]\n");
			fprintf(fp,"SUB SP,1\n");
			fprintf(fp,"RET\n");
			clearParamList();
            clearLSTList();	
		}

    |   Type ID '(' ')' '{' LDeclBlock Body'}'
        { 
            CheckIfFunction($2->varname);
            CheckReturnType($2->varname,variable_type);
            CheckParamList($2->varname);
            InsertLST($2->varname);
            //PrintLST($2->varname);
            //PrintParamList($2->varname);
            ActRecordSetup($2 -> varname);

            MainCodeGen($7);

            PopLocalVariables($2->varname);

            fprintf(fp,"MOV BP,[SP]\n");
            fprintf(fp,"SUB SP,1\n");
            fprintf(fp,"RET\n");
            clearParamList();
            clearLSTList(); 
        }
    ;

ParamList : ParamList ',' Param
			| Param
			;

Param : Type ID     {
						InsertParam($2->varname,variable_type);
					}
		;

LDeclBlock : DECL LDeclList ENDDECL
			| DECL ENDDECL
			;

LDeclList : LDeclList  LDecl
			| LDecl
			;

LDecl : Type IDList ';'
		;

IDList : IDList ',' ID      {InsertLocalSymbol($3->varname,variable_type);}
		| ID           		{InsertLocalSymbol($1->varname,variable_type);}
		;

//-----------------------------------------------------------------------------

//-----------------------------MAIN BLOCK--------------------------------------

MainBlock : INT MAIN '(' ')' '{' LDeclBlock Body '}'	{
            
            fprintf(fp,"MAIN: ");   //label for the function
            fprintf(fp,"PUSH BP\n");
            fprintf(fp,"MOV BP,SP\n");
                    
            //now push local variables(contained in LocalSymbols)
            struct Lsymbol* curr = head2;
            
            int local_vars = 0;
            while(curr != NULL)
            {
                local_vars++;
                curr = curr -> next;
            }   

            fprintf(fp,"ADD SP,%d\n",local_vars);
            
            MainCodeGen($7);

            fprintf(fp,"SUB SP,%d\n",local_vars);

            fprintf(fp,"MOV BP,[SP]\n");
            fprintf(fp,"SUB SP,1\n");
            fprintf(fp,"RET\n");
            clearParamList();

}
			;
//-----------------------------------------------------------------------------


//------------------------------BODY-------------------------------------------

Body :  START SLIST RetStmt END 
        {
            $$ = createTree(0,NULL,connector_node,-1,NULL,$2,$3,NULL);
        }

    |   START RetStmt END
        {
            $$ = createTree(0,NULL,connector_node,-1,NULL,$2,NULL,NULL);
        }
	;

//-----------------------------------------------------------------------------

//------------------------------STATEMENTS-------------------------------------

SLIST : stmt        {$$ = $1;}
    | SLIST stmt    {$$ = createTree(0,NULL,connector_node,-1,NULL,$1,$2,NULL);}
    ;

//-----------------------------------------------------------------------------

//----------------------------RETURN STATEMENT---------------------------------

RetStmt : RETURN expr ';'   {$$ = createTree(0,NULL,return_node,$2->ttype,NULL,$2,NULL,NULL);}
		;
//-----------------------------------------------------------------------------


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

asgStmt : ID ASSIGN expr ';'        {
                                    checkID($1->varname);    
									AssignCheckType($1,$3);
									$$ = createTree(0,NULL,assign_node,$1->ttype,NULL,$1,$3,NULL);}

        |  ID '[' expr ']' ASSIGN expr ';'      
                                    {
                                    checkID($1->varname);
                                    CheckIfArray($1->varname);
                                    CheckIntType($3);
                                    AssignCheckType($1,$6);
                                    $$ = createTree(0,NULL,assignArray_node,$1->ttype,NULL,$1,$3,$6);}
        ;

inputStmt : READ '(' ID ')' ';'     {
        checkID($3->varname);
        MatchType($3,var_node);

        $$ = createTree(0,NULL,read_node,-1,NULL,$3,NULL,NULL);}

        | READ '(' ID '[' expr ']'  ')' ';'     {
        checkID($3->varname);
        CheckIfArray($3->varname);
        CheckIntType($5);
        $$ = createTree(0,NULL,readArray_node,-1,NULL,$3,$5,NULL);}
        ;

outputStmt : WRITE '(' expr ')' ';' {

if($3->ttype != int_type && $3->ttype != str_type)
{
    yyerror("Incorrect type in write\n");
}
$$ = createTree(0,NULL,write_node,-1,NULL,$3,NULL,NULL);

};

IfStmt : 	IF '(' expr ')' THEN SLIST ENDIF ';'	{
CheckBoolType($3);
$$ = createTree(0,NULL,if_node,-1,NULL,$3,$6,NULL);}

		|	IF '(' expr ')' THEN SLIST ELSE SLIST ENDIF	';' {
        CheckBoolType($3);
        $$ = createTree(0,NULL,ifElse_node,-1,NULL,$3,$6,$8);}
		;

WhileStmt : WHILE '(' expr ')' DO SLIST ENDWHILE ';'	{
CheckBoolType($3);
$$ = createTree(0,NULL,while_node,-1,NULL,$3,$6,NULL);};

DoWhileStmt : DO '{' SLIST '}' WHILE '(' expr ')' ';'    {
CheckBoolType($7);
$$ = createTree(0,NULL,Dowhile_node,-1,NULL,$7,$3,NULL);};

RepeatStmt : REPEAT '{' SLIST '}' UNTIL '(' expr ')' ';'  {
CheckBoolType($7);
$$ = createTree(0,NULL,repeat_node,-1,NULL,$7,$3,NULL);};


expr : expr PLUS expr   {CheckType($1,$3);
						$$ = createTree(0,NULL,plus_node,int_type,NULL,$1,$3,NULL);}

    |  expr MINUS expr  {CheckType($1,$3);
    					$$ = createTree(0,NULL,minus_node,int_type,NULL,$1,$3,NULL);}

    |  expr MUL expr    {CheckType($1,$3);
    					$$ = createTree(0,NULL,mul_node,int_type,NULL,$1,$3,NULL);}

    |  expr DIV expr    {CheckType($1,$3);
    					$$ = createTree(0,NULL,div_node,int_type,NULL,$1,$3,NULL);}

    |  expr MOD expr    {CheckType($1,$3);
                        $$ = createTree(0,NULL,mod_node,int_type,NULL,$1,$3,NULL);}

    |  expr LT expr     {CheckType($1,$3);
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

    | '(' expr ')'      {$$ = $2;}
    |  ID               {checkID($1->varname); $$ = $1;}
    |  ID '[' expr ']'  {checkID($1->varname); 

    CheckIfArray($1->varname);
    CheckIntType($3);
    $$ = createTree(                                       0,NULL,array_node,$1->ttype,NULL,$1,$3,NULL);}

    |  NUM              	{$$ = $1;}
    |  STRING           	{$$ = $1;}
    |  ID '(' ')'			{
    							checkID($1->varname);
    							CheckIfFunction($1->varname);
    							struct Gsymbol* idx = Lookup2($1->varname);

    							$$ = createTree(0,NULL,function_node,idx->type,idx->name,$1,NULL,NULL);

                                CheckInformalParamList($$,NULL);
                                    
    							$$ -> Arglist = NULL;	
    						}

    |  ID '(' ArgList ')'	{
    							checkID($1->varname);
    							CheckIfFunction($1->varname);
    							struct Gsymbol* idx = Lookup2($1->varname);

                                $$ = createTree(0,NULL,function_node,idx->type,idx->name,$1,$3,NULL);

                                CheckInformalParamList($$,$3);
                                

    							$$ -> Arglist = $3;
    						}
    ;

ArgList : ArgList ',' expr	
					{
						$$ = createTree(0,NULL,arg_node,-1,NULL,$3,$1,NULL);
					}

		| expr    	{
						$$ = createTree(0,NULL,arg_node,-1,NULL,$1,NULL,NULL);
					}
		;

%%

void yyerror(char *S)
{
    printf("Line number : %d\n%s",line,S);
}

int main(int argc,char* argv[])
{
	line = 1;
    fp = fopen("/home/shrey/xsm_expl/progs/stage5/input.xsm","w");

    fp_read = fopen(argv[1],"r");
    yyin = fp_read;
    bind = 4096;

    yyparse();

    return 0;
}