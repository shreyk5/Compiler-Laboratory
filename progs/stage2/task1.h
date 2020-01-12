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

typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*right;	//left and right branches   
}tnode;

/*Create a node tnode*/
struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r);