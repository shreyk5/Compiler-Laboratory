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

typedef struct Gsymbol {

	char *name;	//name of the variable
	int type;	//type of the variable
	int size;	
	int binding;	//static memory address corresponding to the variable
	struct Gsymbol* next;	//next table entry

} Gsymbol;

struct Gsymbol* start;
struct Gsymbol* end;
int bind;
int variable_type;

struct Gsymbol* Lookup2(char* variable_name);

typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	char* str_val; //string for STRING nodes
	int type;	//type of node
	char* varname;	//name of a variable for ID nodes  
	int ttype;  // int type or bool type
	struct Gsymbol* Gentry;	//pointer to GST entry
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