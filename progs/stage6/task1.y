%{	
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "task1.h"
	FILE *fp;
	FILE *fp_read;
	struct Typetable *Thead = NULL, *Ttail = NULL;	//points to the head and tail of Typetable list
	struct Typetable *DeclType = NULL;	//points to the Typetable entry for the current type
	struct Typetable *PDeclType = NULL; //points to the Typetable entry of current parameter type
	struct Typetable *FuncType = NULL;	//return type of a function

	char* TypeInfo = NULL;	//for keeping types which are not yet declared(for eg same type or undeclared)

	struct Fieldlist *Fhead = NULL, *Ftail = NULL;	//points to the head and tail of field list of a type

	#include "task1.c"
	extern FILE* yyin;
	int yylex(void); 
%}

%union
{
	struct tnode* node;
};


%token START END DECL ENDDECL MAIN INT STR NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV MOD IF THEN ELSE ENDIF LT GT EQ NEQ GTE LTE DO WHILE ENDWHILE BREAK CONTINUE REPEAT UNTIL STRING RETURN TYPE ENDTYPE ALLOC FREE INITIALIZE SENTINEL

%type<node> Program SLIST stmt asgStmt inputStmt outputStmt IfStmt RepeatStmt expr START END NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV WhileStmt DoWhileStmt BREAK CONTINUE STRING ArgList FDef Body RetStmt GDeclBlock FDefBlock MainBlock TypeDefBlock
DECL ENDDECL FIELD INITIALIZE

%left PLUS MINUS
%left MUL DIV MOD
%nonassoc LT GT EQ NEQ GTE LTE
%start Program
%%

//---------------------------------PROGRAM-------------------------------------
Program :	TypeDefBlock GDeclBlock FDefBlock MainBlock
		|	GDeclBlock FDefBlock MainBlock
		|	TypeDefBlock FDefBlock MainBlock
		|	TypeDefBlock GDeclBlock MainBlock
		|	TypeDefBlock MainBlock
		|	GDeclBlock MainBlock
		|	MainBlock	
		;
//-----------------------------------------------------------------------------

//-------------------------------TYPE DECLARATION------------------------------
TypeDefBlock : TYPE TypeDefList ENDTYPE	{PrintTypetable();}
			;

TypeDefList : TypeDefList TypeDef
			| TypeDef
			;

TypeDef : ID '{' FieldDeclList '}'	{TInstall($1->varname,0,Fhead);}
		;

FieldDeclList : FieldDeclList FieldDecl
			| 	FieldDecl
			;

FieldDecl : TypeName ID ';'	{
								FieldInstall(DeclType,$2->varname);
							}
		;

TypeName :	INT	{DeclType = TLookup("int");}
		|	STR	{DeclType = TLookup("string");}
		| 	ID	{
					DeclType = TLookup($1->varname);

					if(DeclType == NULL)	//type maybe undeclared or of the same type as the current user-defined type
					{
						DeclType = TLookup("dummy");
						TypeInfo = malloc(sizeof($1->varname));
						strcpy(TypeInfo,$1->varname);
					}
				}
		;
//-----------------------------------------------------------------------------

//-------------------------------TYPE------------------------------------------

Type :	INT	{DeclType = TLookup("int");}
	|	STR	{DeclType = TLookup("string");}
	|	ID	{
				DeclType = TLookup($1->varname);

				if(DeclType == NULL)
				{
					printf("%s type does not exist\n",$1->varname);
					exit(1);
				}
			}	
	;

ParamType : INT	{PDeclType = TLookup("int");}
		|	STR	{PDeclType = TLookup("string");}
		|	ID	{
					PDeclType = TLookup($1->varname);
					if(!PDeclType)
					{
						printf("%s type not declared\n",$1->varname);
						exit(1);
					}
				}						
		;
//-----------------------------------------------------------------------------


//---------------------------GLOBAL DECLARATION--------------------------------
GDeclBlock : DECL GDeclList ENDDECL	{	
										GenerateHeader();
										PrintSymbolTable();
									}
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

Gid : ID                   	{Install($1->varname,DeclType,0,1);}
	| ID '[' NUM ']'        {Install($1->varname,DeclType,1,$3->val);}
	| ID '(' ParamList ')'	{
								Install($1->varname,DeclType,2,1);
							  	InsertParamList($1->varname);
							  	clearParamList();	
							}

	| ID '(' ')'           	{	
								Install($1->varname,DeclType,2,1);
								InsertParamList($1->varname);
								clearParamList();   
						   	}
	;
//-----------------------------------------------------------------------------

//----------------------------FUNCTION DEFINITION------------------------------

ReturnType :	INT	{FuncType = TLookup("int");}
		|	STR		{FuncType = TLookup("string");}
		|	ID		{
						FuncType = TLookup($1->varname);
						if(!FuncType)
						{
							printf("%s type not declared\n",$1->varname);
							exit(1);
						}
					}						
		;

FDefBlock : FDefBlock FDef
			| FDef
			;

FDef :  ReturnType ID '(' ParamList ')' '{' LDeclBlock Body'}'	
		{
			CheckIfFunction($2->varname);
			CheckReturnType($2->varname,FuncType);
			CheckReturnVal($8->right,$2->ttype);
			CheckParamList($2->varname);
			InsertLST($2->varname);

			ActRecordSetup($2 -> varname);

			MainCodeGen($8);

			PopLocalVariables($2->varname);

			fprintf(fp,"MOV BP,[SP]\n");
			fprintf(fp,"SUB SP,1\n");
			fprintf(fp,"RET\n");
			clearParamList();
			clearLSTList();	
		}

	|   ReturnType ID '(' ')' '{' LDeclBlock Body'}'
		{ 
			CheckIfFunction($2->varname);
			CheckReturnType($2->varname,FuncType);
			CheckReturnVal($7->right,DeclType);
			CheckParamList($2->varname);
			InsertLST($2->varname);
			
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

Param : ParamType ID    {
							InsertParam($2->varname,PDeclType);
						}
		;

LDeclBlock : DECL LDeclList ENDDECL
		| DECL ENDDECL
		|
		;

LDeclList : LDeclList  LDecl
		| LDecl
		;

LDecl : Type IDList ';'
		;

IDList : IDList ',' ID      	{InsertLocalSymbol($3->varname,DeclType);}
	|	ID           			{InsertLocalSymbol($1->varname,DeclType);}
	;

//-----------------------------------------------------------------------------

//-----------------------------MAIN BLOCK--------------------------------------

MainBlock : INT MAIN '(' ')' '{' LDeclBlock Body '}'	{

			CheckReturnVal($7->right,TLookup("int"));
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
			$$ = createTree(0,NULL,connector_node,TLookup("void"),NULL,$2,$3,NULL);
		}

	|   START RetStmt END
		{
			$$ = createTree(0,NULL,connector_node,TLookup("void"),NULL,$2,NULL,NULL);
		}
	;

//-----------------------------------------------------------------------------

//------------------------------STATEMENTS-------------------------------------

SLIST : stmt        {$$ = $1;}
	| SLIST stmt    {$$ = createTree(0,NULL,connector_node,TLookup("void"),NULL,$1,$2,NULL);}
	;

//-----------------------------------------------------------------------------

//----------------------------RETURN STATEMENT---------------------------------

RetStmt : RETURN expr ';'   {$$ = createTree(0,NULL,return_node,$2->ttype,NULL,$2,NULL,NULL);}
		;
//-----------------------------------------------------------------------------


stmt :	asgStmt      	{$$ = $1;}
	|	inputStmt     	{$$ = $1;}
	|	outputStmt    	{$$ = $1;}
	|	IfStmt			{$$ = $1;}
	|	WhileStmt 		{$$ = $1;}
	|	DoWhileStmt   	{$$ = $1;}
	|	RepeatStmt    	{$$ = $1;}
	|	BREAK  ';'    	{$$ = $1;}
	|	CONTINUE ';'  	{$$ = $1;}
	|	INITIALIZE  '(' ')' ';'	{$$ = $1;}
	;

asgStmt :	ID ASSIGN expr ';'    		{		
											checkID($1->varname);    
											AssignCheckType($1,$3);
											$$ = createTree(0,NULL,assign_node,TLookup("void"),NULL,$1,$3,NULL);
										}	

		|  ID '[' expr ']' ASSIGN expr ';'      
										{
											checkID($1->varname);
											CheckIfArray($1->varname);
											CheckIntType($3);
											AssignCheckType($1,$6);
											$$ = createTree(0,NULL,assignArray_node,TLookup("void"),NULL,$1,$3,$6);
										}
		
		|	FIELD ASSIGN expr ';'    	{		
											//checkID($1->varname);    
											//AssignCheckType($1,$3);
											$$ = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,$1,$3,NULL);
										}
			

		|	ID ASSIGN ALLOC	'(' ')' ';'	{
											struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL);

											$$ = createTree(0,NULL,assign_node,TLookup("void"),NULL,$1,tmp,NULL);
										}
		
		|	FIELD ASSIGN ALLOC '(' ')' ';'	{
												struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL);

												$$ = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,$1,tmp,NULL);
											}

		|	FREE '(' ID ')' ';'			{
											$$ = createTree(0,NULL,free_node,TLookup("void"),NULL,$3,NULL,NULL);
										}

		|	FREE '(' FIELD ')' ';'		{
											$$ = createTree(0,NULL,free_node,TLookup("void"),NULL,$3,NULL,NULL);
										}
		;

inputStmt :	READ '(' ID ')' ';'     
								{
									checkID($3->varname);
									MatchType($3,var_node);
									if($3->ttype == TLookup("int") || $3->ttype == TLookup("string"))
									{
										$$ = createTree(0,NULL,read_node,TLookup("void"),NULL,$3,NULL,NULL);
									}
									else
									{
										yyerror("Error : cannot be read\n");
										exit(1);
									}
								}

		|	READ '(' ID '[' expr ']'  ')' ';'     
								{	
									checkID($3->varname);
									CheckIfArray($3->varname);
									CheckIntType($5);
									$$ = createTree(0,NULL,readArray_node,TLookup("void"),NULL,$3,$5,NULL);
								}
		|	READ '(' FIELD ')' ';'
								{
									if($3->ttype == TLookup("int") || $3->ttype == TLookup("string"))
									{
										$$ = createTree(0,NULL,read_field_node,TLookup("void"),NULL,$3,NULL,NULL);
									}
									else
									{
										yyerror("Error : cannot be read\n");
										exit(1);
									}
								}
		;

outputStmt : WRITE '(' expr ')' ';' 
					   {
							if($3->ttype != TLookup("int") && $3->ttype != TLookup("string"))
							{
								printf("Incorrect type in write\n");
								exit(1);
							}
							$$ = createTree(0,NULL,write_node,TLookup("void"),NULL,$3,NULL,NULL);
						};

IfStmt : 	IF '(' expr ')' THEN SLIST ENDIF ';'	
					   	{
							CheckBoolType($3);
							$$ = createTree(0,NULL,if_node,TLookup("void"),NULL,$3,$6,NULL);
						}

			|	IF '(' expr ')' THEN SLIST ELSE SLIST ENDIF ';'
						{
							CheckBoolType($3);
							$$ = createTree(0,NULL,ifElse_node,TLookup("void"),NULL,$3,$6,$8);
						}
		;

WhileStmt : WHILE '(' expr ')' DO SLIST ENDWHILE ';'	
						{	
							CheckBoolType($3);
							$$ = createTree(0,NULL,while_node,TLookup("void"),NULL,$3,$6,NULL);
						};

DoWhileStmt : DO '{' SLIST '}' WHILE '(' expr ')' ';'    
						{
							CheckBoolType($7);
							$$ = createTree(0,NULL,Dowhile_node,TLookup("void"),NULL,$7,$3,NULL);
						};

RepeatStmt : REPEAT '{' SLIST '}' UNTIL '(' expr ')' ';'  
						{			
							CheckBoolType($7);
							$$ = createTree(0,NULL,repeat_node,TLookup("void"),NULL,$7,$3,NULL);
						};


//----------------------------------------------FIELDS--------------------------------------------------------
FIELD	: ID '.' ID		{
							struct Fieldlist* tmp = FLookup($1->ttype,$3->varname);
							if(!tmp)
							{
								printf("Error : %s does not belongs to %s\n",$3->varname,$1->ttype->name);
								exit(1);
							}

							$$ = createTree(0,NULL,field_node,tmp->type,NULL,$1,$3,NULL);
						}

    	|	FIELD '.' ID	{
								struct Fieldlist* tmp = FLookup($1->ttype,$3->varname);
								if(!tmp)
								{
									printf("Error : %s does not belongs to %s\n",$3->varname,$1->ttype->name);
									exit(1);
								}

								struct tnode* tmp_new = createTree(0,NULL,field_node,TLookup("void"),NULL,NULL,$3,NULL);	
								struct tnode* tmp1 = $1;
								while(tmp1 -> mid)
								{
									tmp1 = tmp1 -> mid;	
								} 
								tmp1 -> mid = tmp_new;
								tmp1 -> ttype = tmp -> type;

								$$ = $1;
							}  
        ;
//-----------------------------------------------------------------------------------------------------------

expr : expr PLUS expr   {
							CheckType($1,$3);
							$$ = createTree(0,NULL,plus_node,TLookup("int"),NULL,$1,$3,NULL);
						}

	|  expr MINUS expr  {
							CheckType($1,$3);
							$$ = createTree(0,NULL,minus_node,TLookup("int"),NULL,$1,$3,NULL);
						}

	|  expr MUL expr    {
							CheckType($1,$3);
							$$ = createTree(0,NULL,mul_node,TLookup("int"),NULL,$1,$3,NULL);
						}

	|  expr DIV expr    {
							CheckType($1,$3);
							$$ = createTree(0,NULL,div_node,TLookup("int"),NULL,$1,$3,NULL);
						}

	|  expr MOD expr    {
							CheckType($1,$3);
							$$ = createTree(0,NULL,mod_node,TLookup("int"),NULL,$1,$3,NULL);
						}

	|  expr LT expr     {
							CheckType($1,$3);
							$$ = createTree(0,NULL,lt_node,TLookup("bool"),NULL,$1,$3,NULL);
						}

	|  expr GT expr     {
							CheckType($1,$3);
							$$ = createTree(0,NULL,gt_node,TLookup("bool"),NULL,$1,$3,NULL);
						}

	|  expr EQ expr     {
							//CheckType($1,$3);
							$$ = createTree(0,NULL,eq_node,TLookup("bool"),NULL,$1,$3,NULL);
						}

	|  expr NEQ expr    {
							//CheckType($1,$3);
						   	$$ = createTree(0,NULL,neq_node,TLookup("bool"),NULL,$1,$3,NULL);
						}

	|  expr LTE expr    {
							CheckType($1,$3);
							$$ = createTree(0,NULL,lte_node,TLookup("bool"),NULL,$1,$3,NULL);
						}

	|  expr GTE expr    {
							CheckType($1,$3);
							$$ = createTree(0,NULL,gte_node,TLookup("bool"),NULL,$1,$3,NULL);
						}                      

	| '(' expr ')'      {$$ = $2;}
	|  ID               {checkID($1->varname); $$ = $1;}
	|  ID '[' expr ']'  {
							checkID($1->varname); 
							CheckIfArray($1->varname);
							CheckIntType($3);
							$$ = createTree(0,NULL,array_node,$1->ttype,NULL,$1,$3,NULL);
						}

	|	FIELD			{$$ = $1;}
	| 	SENTINEL		{$$ = createTree(0,NULL,null_node,TLookup("dummy"),NULL,NULL,NULL,NULL);}
	|	NUM             {$$ = $1;}
	|	STRING          {$$ = $1;}
	|	ID '(' ')'			{	
								checkID($1->varname);
								CheckIfFunction($1->varname);
								struct Gsymbol* idx = Lookup2($1->varname);

								$$ = createTree(0,NULL,function_node,idx->type,idx->name,$1,NULL,NULL);

						   		CheckInformalParamList($$);
									
								$$ -> Arglist = NULL;	
							}

	|	ID '(' ArgList ')'	
								{
									checkID($1->varname);
									CheckIfFunction($1->varname);
									struct Gsymbol* idx = Lookup2($1->varname);

						   			$$ = createTree(0,NULL,function_node,idx->type,idx->name,$1,$3,NULL);

						   			CheckInformalParamList($$);

									$$ -> Arglist = $3;
								}
	;

ArgList : ArgList ',' expr	
								{
									$$ = createTree(0,NULL,arg_node,-1,NULL,$3,$1,NULL);
								}

		| expr    				{
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
	variable_type = -1; 
   	p_variable_type = -1;
   	bind = 4096;

   	fp = fopen("/home/shrey/xsm_expl/progs/stage6/input.xsm","w");
   	fp_read = fopen(argv[1],"r");
  	yyin = fp_read;

	InitTypeTable();
   	yyparse();

   	return 0;
}
