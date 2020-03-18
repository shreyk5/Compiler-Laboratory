#define num_node 1
#define var_node 2
#define plus_node 3 
#define minus_node 4
#define mul_node 5
#define div_node 6
#define read_node 7
#define write_node 8
#define assign_node 9
#define begin_node 10
#define end_node   11
#define connector_node 12
#define if_node	13
#define ifElse_node 25
#define else_node 14
#define then_node	15
#define endif_node	16
#define bool_type 17
#define int_type 18
#define lt_node 19
#define gt_node 20
#define eq_node 21
#define neq_node 22
#define lte_node 23
#define gte_node 24
#define while_node 26
#define continue_node 27
#define break_node 28
#define repeat_node 29
#define Dowhile_node 30
#define str_type 31
#define str_node 32
#define array_node 33
#define assignArray_node 34
#define readArray_node 35
#define mod_node 36
#define function_node 37
#define arg_node 38
#define return_node 39
#define field_node 40
#define assign_field_node 41
#define free_node 42
#define init_node 43
#define alloc_node 44
#define read_field_node 45
#define null_node 46
#define field_function_node 47

int line;

struct Typetable{
    char *name;                 //type name
    int size;                   //size of the type
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *next;     // pointer to the next type table entry
};

struct Fieldlist{
  char *name;              //name of the field
  int fieldIndex;          //the position of the field in the field list
  struct Typetable *type;  //pointer to type table entry of the field's type
  struct Classtable *ctype;	//pointer to class table entry if the field is of class type
  char* typename;
  struct Fieldlist *next;  //pointer to the next field
};

struct Classtable {
 	char *name;                           //name of the class
	struct Fieldlist *Memberfield;        //pointer to list of fields in the class 
	struct Memberfunclist *Vfuncptr;      //pointer to list of functions in the class
	struct Classtable *Parentptr;         //pointer to the parent's class table
	int Class_index;                      //position of the class in the virtual function table
	int Fieldcount;                       //count of fields
  	int Methodcount;                      //count of methods
	struct Classtable *next;              //pointer to next class table entry
};

struct Memberfunclist {
 	char *name;                      //name of the member function in the class
	struct Typetable *type;          //pointer to typetable
	struct Paramstruct *paramlist;   //pointer to the head of the formal parameter list
	int FuncPosition;                //position of the function in the class table
 	int Flabel;                      //A label for identifying the starting address of the function's code in the memory
	struct Memberfunclist *next;     //pointer to next Memberfunclist entry
};


typedef struct Paramstruct{

	char* name;
	struct Typetable* type;	//pointer to Typetable entry
	struct Classtable* ctype;	//pointer to class table entry if it is self 
	int binding;
	struct Paramstruct* next;

} Paramstruct;

struct Paramstruct* head;	//points to the parameters of current function being parsed
struct Paramstruct* tail;

typedef struct Lsymbol {

	char* name;	//name of the variable
	struct Typetable* type;	//pointer to Typetable entry
	int binding;	
	struct Lsymbol* next;	//pointer to next variable

} Lsymbol;

struct Lsymbol* head2;	//points to the local variables of current function being parsed	
struct Lsymbol* tail2;
int list_size;

typedef struct Gsymbol {

	char *name;	//name of the variable
	struct Typetable *type;	//pointer to the Typetable if it is not a class variable
	struct Classtable *ctype;	//pointer to class table entry if it is a class variable
	int _type;	//0 for simple variable,1 for array, 2 for function
	int size;	
	int binding;	//static memory address corresponding to the variable
	struct Paramstruct *ParamList;
	struct Lsymbol* LocalSymbols;
	struct Gsymbol* next;	//next table entry

} Gsymbol;

struct Gsymbol* start;
struct Gsymbol* end;
int bind;
int bind_param;

typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	char* str_val; //string for STRING nodes
	int type;	//type of node
	struct Typetable* ttype;  // int type or string or bool type or any other user defined data type
	struct Classtable *ctype;
	char* varname;	//name of a variable for ID nodes  
	struct tnode* Arglist;
	struct tnode *left,*right,*mid;	//left,right and mid branches   
}tnode;


typedef struct stack_node{
	struct stack_node* next;
	int break_label;
	int continue_label;
} stack_node;
stack_node* top;

/*Create a node tnode*/
struct tnode* createTree(int val, char* str_val, int type, struct Typetable* ttype, struct Classtable *ctype,char* c, struct tnode *l, struct tnode *r,struct tnode* mid);
struct Lsymbol* LocalLookup(char* variable_name);
struct Paramstruct* ParamLookup(char* variable_name);
struct Gsymbol* GLookup(char* variable_name);

void yyerror(char *S);
void push(struct stack_node* node);
void pop();
void CheckCompType(struct tnode* t1,struct tnode* t2);
void CheckType(struct tnode* t1,struct tnode* t2);
void MatchType(struct tnode* t,int type);
void CheckIfArray(char* varname);
void AssignCheckType(struct tnode* t1,struct tnode* t2);
void CheckBoolType(struct tnode* t);
void CheckIntType(struct tnode* t);
void checkID(char* varname);
void Install(char* variable_name, struct Typetable* type, int _type, int size);
void PLocal();
void CheckDuplicateParam(char* name);
void InsertParam(char* name,struct Typetable* type);
void clearParamList();
void clearLSTList();
void InsertParamList(char* name);
void CheckDuplicateLocalSymbol(char* name);
void InsertLocalSymbol(char* name, struct Typetable* type);
void InsertLST(char *name);
void PrintSymbolTable();
void PrintLST(char* name);
void PrintParamList(char* name);
void CheckReturnType(char* name,struct Typetable* type);
void CheckReturnVal(struct tnode* t,struct Typetable* type);
void CheckIfFunction(char* name);
void CheckParamList(char *name);
void CheckInformalParamList(struct Paramstruct *paramlist,struct tnode* t);
struct Fieldlist* FieldNameLookup(char* name);
struct Fieldlist* FLookup(struct Typetable *type, char* name);
void FieldInstall(struct Typetable *type, char* name);
struct Typetable* TLookup(char *name);
void TInstall(char *name,int size,struct Fieldlist* fields);
void InitTypeTable();
void PrintTypetable();
void ActRecordSetup(char* name);
void PopLocalVariables(char* name);
void SetupVirtualTable();
int getVFTPtr(struct tnode *t);
int BasicCodeGen(struct tnode* t);
void AssignArrayCodeGen(struct tnode* t);
void readCodeGen(char* c);
void readFieldCodeGen(struct tnode *t);
void readArrayCodeGen(struct tnode* t);
void writeCodeGen(struct tnode* t);
void ifCodeGen(struct tnode* t);
void ifElseCodeGen(struct tnode* t);
void BreakCodeGen(struct tnode* t);
void ContinueCodeGen(struct tnode* t);
void WhileCodeGen(struct tnode* t);
void DoWhileCodeGen(struct tnode* t);
void RepeatCodeGen(struct tnode* t);
void AssignCodeGen(struct tnode* t);
void AssignFieldCodeGen(struct tnode* t);
void ArgCodeGen(struct tnode* t);
void ReturnCodeGen(struct tnode* t);
void InitializeCodeGen(struct tnode* t);
int AllocCodeGen(struct tnode* t);
int FunctionCodeGen(struct tnode* t);
int FieldFunctionCodeGen(struct tnode* t);
void FreeCodeGen(struct tnode* t);
void checkDescendant(struct Classtable *c1,struct Classtable *c2);
void MainCodeGen(struct tnode* t);
void GenerateHeader();
void GenerateExit();
void GenerateCode(struct tnode* t);
void printTree(struct tnode* t);
struct Classtable* CLookup(char *name);
struct Classtable* CInstall(char *name,char *parent_name);
void CInstallFinal();
void Class_FieldInstall(char* name,struct Typetable *type, struct Classtable *ctype);
void Class_MethodInstall(char *function_name,struct Typetable *type,struct Paramstruct* plist);
void ClassCheckFunction(char *function_name,struct Typetable *return_type);
void ClassFunctionSetup(char *function_name);
void ClassFunctionPopLocal();
