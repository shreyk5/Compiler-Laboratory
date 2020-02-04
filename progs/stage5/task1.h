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

int line;

typedef struct Paramstruct{

	char* name;
	int type;	//int or string
	int binding;
	struct Paramstruct* next;

} Paramstruct;

struct Paramstruct* head;	//for saving parameters
struct Paramstruct* tail;

typedef struct Lsymbol {

	char* name;	//name of the variable
	int type;	//variable type(intger or string)
	int binding;	
	struct Lsymbol* next;	//pointer to next variable

} Lsymbol;

struct Lsymbol* head2;
struct Lsymbol* tail2;
int list_size;

typedef struct Gsymbol {

	char *name;	//name of the variable
	int type;	//type of the variable(int,str)
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
int variable_type;

struct Lsymbol* LocalLookup(char* variable_name);
struct Paramstruct* ParamLookup(char* variable_name);
struct Gsymbol* Lookup2(char* variable_name);

typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	char* str_val; //string for STRING nodes
	int type;	//type of node
	char* varname;	//name of a variable for ID nodes  
	int ttype;  // int type or string or bool type
	struct tnode* Arglist;
	struct tnode *left,*right,*mid;	//left,right and mid branches   
}tnode;

/*Create a node tnode*/
struct tnode* createTree(int val, char* str_val, int type, int ttype, char* c, struct tnode *l, struct tnode *r,struct tnode* mid);

typedef struct stack_node{
	struct stack_node* next;
	int break_label;
	int continue_label;
} stack_node;

stack_node* top;
void clearParamList();