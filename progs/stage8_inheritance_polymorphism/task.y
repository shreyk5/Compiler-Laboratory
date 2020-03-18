%{	
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "task.h"
	FILE *fp, *fp1, *fp2;
	FILE *fp_read;
	struct Typetable *Thead = NULL, *Ttail = NULL;	//points to the head and tail of Typetable list
	struct Typetable *DeclType = NULL;	//points to the Typetable entry for the current type
	struct Typetable *PDeclType = NULL; //points to the Typetable entry of current parameter type
	struct Typetable *FuncType = NULL;	//return type of a function

	char* TypeInfo = NULL;	//for keeping types which are not yet declared(for eg same type or undeclared)

	struct Fieldlist *Fhead = NULL, *Ftail = NULL;	//points to the head/tail of field list of a type/class
	struct Classtable *Chead = NULL,*Ctail = NULL;	//points to the head/tail of class table list
	struct Classtable* class = NULL;
	struct Classtable* DeclClass = NULL;
	struct Memberfunclist *Mfhead = NULL, *Mftail = NULL;  //points to head/tail of func list of class	
	int class_idx = 0;	//to keep track of class indices
	int final_installation = 0;
	int inheritance = 0;

	#include "task.c"
	extern FILE* yyin;
	int yylex(void); 
%}

%union
{
	struct tnode* node;
};


%token START END DECL ENDDECL MAIN INT STR NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV MOD IF THEN ELSE ENDIF LT GT EQ NEQ GTE LTE DO WHILE ENDWHILE BREAK CONTINUE REPEAT UNTIL STRING RETURN TYPE ENDTYPE ALLOC FREE INITIALIZE SENTINEL CLASS ENDCLASS SELF NEW DELETE EXTENDS

%type<node> Program SLIST stmt asgStmt inputStmt outputStmt IfStmt RepeatStmt expr START END NUM ASSIGN READ WRITE ID PLUS MINUS MUL DIV WhileStmt DoWhileStmt BREAK CONTINUE STRING ArgList FDef Body RetStmt GDeclBlock FDefBlock MainBlock TypeDefBlock FieldFunction SELF ClassDefBlock ClassDefList ClassDef CLASS ENDCLASS
DECL ENDDECL FIELD INITIALIZE

%left PLUS MINUS
%left MUL DIV MOD
%nonassoc LT GT EQ NEQ GTE LTE
%start Program
%%

//--------------------------------------PROGRAM---------------------------------------------
Program :	TypeDefBlock ClassDefBlock GDeclBlock FDefBlock MainBlock
		|	ClassDefBlock GDeclBlock FDefBlock MainBlock
		|	TypeDefBlock ClassDefBlock FDefBlock MainBlock
		|	TypeDefBlock ClassDefBlock GDeclBlock MainBlock
		|	TypeDefBlock ClassDefBlock MainBlock
		|	ClassDefBlock GDeclBlock MainBlock
		|	ClassDefBlock MainBlock	
		;
//-------------------------------------------------------------------------------------------

//------------------------------------TYPE DECLARATION----------------------------------------
TypeDefBlock : TYPE TypeDefList ENDTYPE	{}
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
//------------------------------------------------------------------------------------------

//--------------------------------------CLASS DECLARATION-----------------------------------
ClassDefBlock : CLASS ClassDefList ENDCLASS	{}

			|								{}
            ;

ClassDefList : ClassDefList ClassDef
	        | ClassDef
			;

ClassDef : Cname '{' DECL CFieldlists CMethodDecls ENDDECL CMethodDefns '}'	{
																				//set the function list and fieldlist
																				if(!final_installation)
																				{
																					final_installation = 1;
																					CInstallFinal();
																				}

																				class = NULL;
																				inheritance = 0;
																				Fhead = Ftail = NULL;
																			    Mfhead = Mftail = NULL;
																				bind += 8;    
																			}
																			
		|	Cname '{' DECL CMethodDecls ENDDECL CMethodDefns '}'			{
																				//set the function list and fieldlist
																				if(!final_installation)
																				{
																					final_installation = 1;
																					CInstallFinal();
																				}

																				class = NULL;
																				inheritance = 0;
																				Fhead = Ftail = NULL;
																			    Mfhead = Mftail = NULL;
																				bind += 8;    
																			}
		;

Cname : ID	{
				final_installation = 0;
				class = CInstall($1->varname,NULL);
			}

	|	ID EXTENDS ID	{
							inheritance = 1;
							final_installation = 0;
							class = CInstall($1->varname,$3->varname);

							InheritMemberFields($3->varname);
							InheritFunctions($3->varname);
						} 	
	;

CFieldlists : CFieldlists CField
		|	CField
		;

CField : Type ID ';'	{
							//field of a class can be any primitive type,user-defined type or class type
							Class_FieldInstall($2->varname,DeclType,DeclClass);
						}
	;

CMethodDecls : CMethodDecls MethodDecl
			|	MethodDecl
			;

MethodDecl :	Type ID '(' ParamList ')' ';'	{
													//return type of a function cannot be of class-type
													if(DeclClass != NULL)
													{
														printf("Error: Type of func %s is a class\n",$2->varname);
														yyerror("");
														exit(1);
													}

													if(DeclType == NULL)
													{
														printf("Error: Type of func %s is invalid\n",$2->varname);
														yyerror("");
														exit(1);
													}
													
													Class_MethodInstall($2->varname,DeclType,head);	
													clearParamList();		
												}

		|		Type ID '(' ')' ';'				{
													//return type of a function cannot be of class-type
													if(DeclClass != NULL)
													{
														printf("Error: Type of func %s is a class\n",$2->varname);
														yyerror("");
														exit(1);
													}

													if(DeclType == NULL)
													{
														printf("Error: Type of func %s is invalid\n",$2->varname);
														yyerror("");
														exit(1);
													}

													Class_MethodInstall($2->varname,DeclType,head);
													clearParamList();			
												}	

		;

CMethodDefns : CMethodDefns FDef
			| FDef
			;

//--------------------------------------------------------------------------------------------

//----------------------------------------TYPE------------------------------------------------

Type :	INT	{
				DeclType = TLookup("int");
				DeclClass = NULL;
			}

	|	STR	{
				DeclType = TLookup("string");
				DeclClass = NULL;
			}

	|	ID	{
				DeclType = TLookup($1->varname);
				DeclClass = CLookup($1->varname);

				if(DeclType == NULL && DeclClass == NULL)
				{
					printf("%s type does not exist\n",$1->varname);
					yyerror("");
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
//------------------------------------------------------------------------------------------


//-----------------------------------GLOBAL DECLARATION-------------------------------------
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

Gid : ID                   	{
								if(!DeclClass)	//non-class variable
								{
									GInstall($1->varname,DeclType,DeclClass,0,1);
								}
								else	//class variable
								{
									GInstall($1->varname,DeclType,DeclClass,0,2);
								}
							}

	| ID '[' NUM ']'        {
								if(DeclClass)
								{
									printf("Error : array of class not allowed\n");
									yyerror("");
									exit(1);
								}
								
								GInstall($1->varname,DeclType,DeclClass,1,$3->val);
							}

	| ID '(' ParamList ')'	{
								if(DeclClass)
								{
									printf("Error : class return type not allowed\n");
									yyerror("");
									exit(1);
								}	

								GInstall($1->varname,DeclType,DeclClass,2,1);
							  	InsertParamList($1->varname);
							  	clearParamList();	
							}

	| ID '(' ')'           	{	
								if(DeclClass)
								{
									printf("Error : class return type not allowed\n");
									yyerror("");
									exit(1);
								}

								GInstall($1->varname,DeclType,DeclClass,2,1);
								InsertParamList($1->varname);
								clearParamList();   
						   	}
	;
//---------------------------------------------------------------------------------------------


//-----------------------------------FUNCTION DEFINITION---------------------------------------

ReturnType :	INT	{FuncType = TLookup("int");}
		|	STR		{FuncType = TLookup("string");}
		|	ID		{
						FuncType = TLookup($1->varname);
						if(!FuncType)
						{
							printf("%s type not declared\n",$1->varname);
							yyerror("");
							exit(1);
						}
					}						
		;

FDefBlock : FDefBlock FDef
			| FDef
			;

FDef :  ReturnType ID '(' ParamList ')' '{' LDeclBlock Body'}'	
		{
			if(class)
			{
				if(!final_installation)
				{
					final_installation = 1;
					CInstallFinal();
				}

				ClassCheckFunction($2->varname,FuncType);
				InsertSelfToParam();
				ClassFunctionSetup($2->varname);

				MainCodeGen($8);

				ClassFunctionPopLocal();
				
				fprintf(fp,"MOV BP,[SP]\n");
				fprintf(fp,"SUB SP,1\n");
				fprintf(fp,"RET\n");
				clearParamList();
				clearLSTList();
			}

			else
			{
				checkID($2->varname);
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
		}

	|   ReturnType ID '(' ')' '{' LDeclBlock Body'}'
		{ 
			if(class)
			{
				if(!final_installation)
				{
					final_installation = 1;
					CInstallFinal();
				}
				ClassCheckFunction($2->varname,FuncType);
				InsertSelfToParam();
				ClassFunctionSetup($2->varname);

				MainCodeGen($7);

				ClassFunctionPopLocal();
				
				fprintf(fp,"MOV BP,[SP]\n");
				fprintf(fp,"SUB SP,1\n");
				fprintf(fp,"RET\n");
				clearParamList();
				clearLSTList();
			}
			else
			{
				checkID($2->varname);
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

//------------------------------------------------------------------------------------------

//--------------------------------------MAIN BLOCK------------------------------------------

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
//------------------------------------------------------------------------------------------


//------------------------------------------BODY--------------------------------------------

Body :  START SLIST RetStmt END 
		{
			$$ = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,$2,$3,NULL);
		}

	|   START RetStmt END
		{
			$$ = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,NULL,$2,NULL);
		}
	;

//------------------------------------------------------------------------------------------

//--------------------------------------STATEMENTS------------------------------------------

SLIST : stmt        {$$ = $1;}
	| SLIST stmt    {$$ = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,$1,$2,NULL);}
	;

//------------------------------------------------------------------------------------------

//----------------------------------RETURN STATEMENT----------------------------------------

RetStmt : RETURN expr ';'   {$$ = createTree(0,NULL,return_node,$2->ttype,NULL,NULL,$2,NULL,NULL);}
		;
//------------------------------------------------------------------------------------------


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
											$$ = createTree(0,NULL,assign_node,TLookup("void"),NULL,NULL,$1,$3,NULL);
										}	

		|  ID '[' expr ']' ASSIGN expr ';'      
										{
											checkID($1->varname);
											CheckIfArray($1->varname);
											CheckIntType($3);
											AssignCheckType($1,$6);
											$$ = createTree(0,NULL,assignArray_node,TLookup("void"),NULL,NULL,$1,$3,$6);
										}
		
		|	FIELD ASSIGN expr ';'    	{
											AssignCheckType($1,$3);		
											$$ = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,NULL,$1,$3,NULL);
										}
			

		|	ID ASSIGN ALLOC	'(' ')' ';'	{
											checkID($1->varname);
											//type of ID should not be int,string
											if($1->ttype == TLookup("string") || $1->ttype == TLookup("int"))
											{
												printf("Error: %s is not a user-defined type\n",$1->varname);
												yyerror("");
												exit(1);
											}

											struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);
											$$ = createTree(0,NULL,assign_node,TLookup("void"),NULL,NULL,$1,tmp,NULL);
										}
		
		|	FIELD ASSIGN ALLOC '(' ')' ';'	{
												struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);

												$$ = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,NULL,$1,tmp,NULL);
											}

		|	ID ASSIGN NEW '(' ID ')' ';'	{
												struct Classtable *ctmp = CLookup($5->varname);
												if(!ctmp)
												{
													printf("Error:Class %s does not exist\n",$5->varname);
													yyerror("");
													exit(1);
												}

												struct Gsymbol *tmp = GLookup($1->varname);
												if(!tmp)
												{
													printf("Error: variable %s not declared\n",$1->varname);
													yyerror("");
													exit(1);
												}

												if(!tmp->ctype)
												{
													printf("Error:Wrong assignment\n");
													yyerror("");
													exit(1);
												}	

												struct tnode* tmp2 = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);
												$$ = createTree(0,NULL,assign_node,TLookup("void"),NULL,NULL,$1,tmp2,$5);
										
											}
		
		|	FIELD ASSIGN NEW '(' ID ')' ';'	{
												struct Classtable *ctmp = CLookup($5->varname);
												if(!ctmp)
												{
													printf("Error:Class %s does not exist\n",$5->varname);
													yyerror("");
													exit(1);
												}

												if(!$1->ctype)
												{
													printf("Error:Wrong assignment\n");
													yyerror("");
													exit(1);	
												}

												struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);
												$$ = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,NULL,$1,tmp,$5);
											}

		|	FREE '(' ID ')' ';'			{
											if(!$3->ctype)
											{
												printf("Error:%s is not a class variable\n",$3->varname);
												yyerror("");
												exit(1);
											}
											$$ = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,$3,NULL,NULL);
										}

		|	FREE '(' FIELD ')' ';'		{
											if(!$3->ctype)
											{
												printf("Error: not a class variable\n");
												yyerror("");
												exit(1);
											}
											$$ = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,$3,NULL,NULL);
										}

		|	DELETE '(' ID ')' ';'		{
											if(!$3->ctype)
											{
												printf("Error:%s is not a class variable\n",$3->varname);
												yyerror("");
												exit(1);
											}
											$$ = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,$3,NULL,NULL);
										}

		|	DELETE '(' FIELD ')' ';'	{
											if(!$3->ctype)
											{
												printf("Error: not a class variable\n");
												yyerror("");
												exit(1);
											}
											$$ = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,$3,NULL,NULL);
										}
		;

inputStmt :	READ '(' ID ')' ';'     
								{
									checkID($3->varname);
									MatchType($3,var_node);
									if($3->ttype == TLookup("int") || $3->ttype == TLookup("string"))
									{
										$$ = createTree(0,NULL,read_node,TLookup("void"),NULL,NULL,$3,NULL,NULL);
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
									$$ = createTree(0,NULL,readArray_node,TLookup("void"),NULL,NULL,$3,$5,NULL);
								}
		|	READ '(' FIELD ')' ';'
								{
									if($3->ttype == TLookup("int") || $3->ttype == TLookup("string"))
									{
										$$ = createTree(0,NULL,read_field_node,TLookup("void"),NULL,NULL,$3,NULL,NULL);
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
							$$ = createTree(0,NULL,write_node,TLookup("void"),NULL,NULL,$3,NULL,NULL);
						};

IfStmt : 	IF '(' expr ')' THEN SLIST ENDIF ';'	
					   	{
							CheckBoolType($3);
							$$ = createTree(0,NULL,if_node,TLookup("void"),NULL,NULL,$3,$6,NULL);
						}

			|	IF '(' expr ')' THEN SLIST ELSE SLIST ENDIF ';'
						{
							CheckBoolType($3);
							$$ = createTree(0,NULL,ifElse_node,TLookup("void"),NULL,NULL,$3,$6,$8);
						}
		;

WhileStmt : WHILE '(' expr ')' DO SLIST ENDWHILE ';'	
						{	
							CheckBoolType($3);
							$$ = createTree(0,NULL,while_node,TLookup("void"),NULL,NULL,$3,$6,NULL);
						};

DoWhileStmt : DO '{' SLIST '}' WHILE '(' expr ')' ';'    
						{
							CheckBoolType($7);
							$$ = createTree(0,NULL,Dowhile_node,TLookup("void"),NULL,NULL,$7,$3,NULL);
						};

RepeatStmt : REPEAT '{' SLIST '}' UNTIL '(' expr ')' ';'  
						{			
							CheckBoolType($7);
							$$ = createTree(0,NULL,repeat_node,TLookup("void"),NULL,NULL,$7,$3,NULL);
						};


//----------------------------------------------FIELDS--------------------------------------------------------
FIELD	: ID '.' ID		{
							checkID($1->varname);
							struct Fieldlist* tmp = FLookup($1->ttype,$3->varname);
							if(!tmp)
							{
								printf("Error : %s does not belongs to %s\n",$3->varname,$1->ttype->name);
								yyerror("");
								exit(1);
							}
							
							$$ = createTree(0,NULL,field_node,tmp->type,NULL,NULL,$1,$3,NULL);
						}

    	|	FIELD '.' ID	{
								struct Fieldlist* tmp = FLookup($1->ttype,$3->varname);
								if(!tmp)
								{
									printf("Error : %s does not belongs to %s\n",$3->varname,$1->ttype->name);
									yyerror("");
									exit(1);
								}

								struct tnode* tmp_new = createTree(0,NULL,field_node,TLookup("void"),NULL,NULL,NULL,$3,NULL);	
								struct tnode* tmp1 = $1;
								while(tmp1 -> mid)
								{
									tmp1 = tmp1 -> mid;	
								} 
								tmp1 -> mid = tmp_new;
								tmp1 -> ttype = tmp -> type;

								$$ = $1;
							}

		|	SELF '.' ID		{
								if(!class)
								{
									printf("Self is not defined\n");
									yyerror("");
									exit(1);
								}

								//check if ID is a field of the class or not
								struct Fieldlist* curr = Fhead;
								while(curr)
								{
									if(!strcmp(curr->name,$3->varname))
									{
										break;
									}
									curr = curr -> next;
								}

								if(curr == NULL)
								{
									printf("Error: %s is not a field of %s\n",$3->varname,class->name);
									yyerror("");
									exit(1);
								}

								$1 -> ctype = class;	
								$$ = createTree(0,NULL,field_node,curr->type,curr->ctype,NULL,$1,$3,NULL);

							}  
        ;

FieldFunction :	SELF '.' ID '(' ArgList ')'	{
												if(!class)
												{
													printf("Error: Self is not defined\n");
													yyerror("");
													exit(1);
												}

												struct Memberfunclist *idx = Mfhead;
												while(idx)
												{
													if(!strcmp(idx->name,$3->varname))
													{
														break;
													}
													idx = idx -> next;
												}

												if(!idx)
												{
													printf("Error: Undefined function %s\n",$3->varname);
													yyerror("");
													exit(1);
												}

												CheckInformalParamList(idx->paramlist,$5);
												
												$1 -> ctype = class;
												$$ = createTree(0,NULL,field_function_node,idx->type,NULL,idx->name,$1,$3,NULL);
												$$ -> Arglist = $5;
											}

            	|	ID '.' ID '(' ArgList ')'	{
													struct Gsymbol *tmp = GLookup($1->varname);
													if(!tmp)
													{
														printf("Error:Variable %s is undeclared\n",$1->varname);
														yyerror("");
														exit(1);
													}

													if(!tmp->ctype)
													{
														printf("Error: %s is not a class variable\n",$1->varname);
														yyerror("");
														exit(1);
													}

													struct Memberfunclist* tmp2 = MLookup(tmp->ctype,$3->varname);
													if(!tmp2)
													{
														printf("Error:%s function not delcared\n",$3->varname);
														yyerror("");
														exit(1);
													}

													CheckInformalParamList(tmp2->paramlist,$5);
													
													$1->ctype = tmp -> ctype;
													$$ = createTree(0,NULL,field_function_node,tmp2->type,NULL,tmp2->name,$1,$3,NULL);
													$$ -> Arglist = $5;
												}

            	|	FIELD '.' ID '(' ArgList ')'	{
														struct Memberfunclist *tmp = MLookup($1->ctype,$3->varname); 
														if(!tmp)
														{
															printf("Error:Invalid function call\n");
															yyerror("");
															exit(1);
														}

														CheckInformalParamList(tmp->paramlist,$5);

														$$ = createTree(0,NULL,field_function_node,tmp->type,NULL,tmp->name,$1,$3,NULL);
														$$ -> Arglist = $5;
													}	  
//-----------------------------------------------------------------------------------------------------------

expr : expr PLUS expr   {
							CheckType($1,$3);
							$$ = createTree(0,NULL,plus_node,TLookup("int"),NULL,NULL,$1,$3,NULL);
						}

	|  expr MINUS expr  {
							CheckType($1,$3);
							$$ = createTree(0,NULL,minus_node,TLookup("int"),NULL,NULL,$1,$3,NULL);
						}

	|  expr MUL expr    {
							CheckType($1,$3);
							$$ = createTree(0,NULL,mul_node,TLookup("int"),NULL,NULL,$1,$3,NULL);
						}

	|  expr DIV expr    {
							CheckType($1,$3);
							$$ = createTree(0,NULL,div_node,TLookup("int"),NULL,NULL,$1,$3,NULL);
						}

	|  expr MOD expr    {
							CheckType($1,$3);
							$$ = createTree(0,NULL,mod_node,TLookup("int"),NULL,NULL,$1,$3,NULL);
						}

	|  expr LT expr     {
							CheckType($1,$3);
							$$ = createTree(0,NULL,lt_node,TLookup("bool"),NULL,NULL,$1,$3,NULL);
						}

	|  expr GT expr     {
							CheckType($1,$3);
							$$ = createTree(0,NULL,gt_node,TLookup("bool"),NULL,NULL,$1,$3,NULL);
						}

	|  expr EQ expr     {
							CheckCompType($1,$3);
							$$ = createTree(0,NULL,eq_node,TLookup("bool"),NULL,NULL,$1,$3,NULL);
						}

	|  expr NEQ expr    {
							CheckCompType($1,$3);
						   	$$ = createTree(0,NULL,neq_node,TLookup("bool"),NULL,NULL,$1,$3,NULL);
						}

	|  expr LTE expr    {
							CheckType($1,$3);
							$$ = createTree(0,NULL,lte_node,TLookup("bool"),NULL,NULL,$1,$3,NULL);
						}

	|  expr GTE expr    {
							CheckType($1,$3);
							$$ = createTree(0,NULL,gte_node,TLookup("bool"),NULL,NULL,$1,$3,NULL);
						}                      

	| '(' expr ')'      {$$ = $2;}
	|  ID               {
							checkID($1->varname);

							$$ = $1;
						}

	|  ID '[' expr ']'  {
							checkID($1->varname); 
							CheckIfArray($1->varname);
							CheckIntType($3);
							$$ = createTree(0,NULL,array_node,$1->ttype,NULL,NULL,$1,$3,NULL);
						}

	|	FIELD			{$$ = $1;}
	|	FieldFunction	{$$ = $1;}
	| 	SENTINEL		{$$ = createTree(0,NULL,null_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);}
	|	NUM             {$$ = $1;}
	|	STRING          {$$ = $1;}

	|	ID '(' ArgList ')'	
								{
									checkID($1->varname);
									CheckIfFunction($1->varname);
									struct Gsymbol* idx = GLookup($1->varname);

						   			$$ = createTree(0,NULL,function_node,idx->type,NULL,idx->name,$1,$3,NULL);

						   			CheckInformalParamList(idx -> ParamList,$3);

									$$ -> Arglist = $3;
								}
	;

ArgList : ArgList ',' expr	
								{
									$$ = createTree(0,NULL,arg_node,TLookup("void"),NULL,NULL,$3,$1,NULL);
								}

		| expr    				{
									$$ = createTree(0,NULL,arg_node,TLookup("void"),NULL,NULL,$1,NULL,NULL);
								}

		|						{
									$$ = NULL;
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
	bind = 4096;

   	fp = fopen("/home/shrey/xsm_expl/progs/stage8_inheritance_polymorphism/tmp.xsm","w");
	fp1 = fopen("input.xsm","w");
	fp2 = fopen("tmp2.xsm","w");
   	fp_read = fopen(argv[1],"r");
  	yyin = fp_read;

	InitTypeTable();
   	yyparse();

   	return 0;
}
