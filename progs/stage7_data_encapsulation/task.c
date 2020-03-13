struct tnode* createTree(int val, char* str_val, int type, struct Typetable* ttype,struct Classtable *ctype, char* c, struct tnode *l, struct tnode *r, struct tnode* mid)
{
    struct tnode *tmp = (struct tnode*)malloc(sizeof(tnode));
    tmp -> val = val;
    tmp -> str_val = str_val;
    tmp -> type = type;
    tmp -> ctype = ctype;
    tmp -> ttype = ttype;
    tmp -> left = l;
    tmp -> right = r; 
    tmp -> mid = mid;

    if(type == var_node)
    {
        tmp -> varname = malloc(sizeof(c));
        strcpy(tmp -> varname,c);  

        struct Lsymbol* curr1 = LocalLookup(c);
        struct Paramstruct* curr2 = ParamLookup(c);
        struct Gsymbol* curr3 = GLookup(c);

        if(curr1)
        {
            tmp -> ttype = curr1 -> type;
        }
        else if(curr2)
        {
            tmp -> ttype = curr2 -> type;
        }
        else if(curr3)
        {
            tmp -> ttype = curr3 -> type;
        }
    }

    return tmp;
}

int used = -1;
int get_reg()
{
    used++;
    if(used>=20)
    {
        printf("Not enough registers\n");
        exit(1);
    }
    return used;
}

void free_reg()
{
    if(used>=0)
        used--;
}

int label = 0;
int get_label()
{
    label++;
    return label;
}

void push(struct stack_node* node)
{   
    if(top == NULL)
    {
        top = node;
        return;
    }

    node->next = top;
    top = node;
}

void pop()
{
    if(top == NULL)
    {
        return;
    }

    struct stack_node* tmp = top;
    top = top->next;

    free(tmp);
}

void CheckCompType(struct tnode* t1,struct tnode* t2)
{
    if(t1->ttype == TLookup("int") && t2->ttype == TLookup("int"))
    {

    }
    else if((t1->ttype != TLookup("int") && t1->ttype != TLookup("string")) && (t2->ttype == TLookup("dummy")))
    {

    }
    else if((t2->ttype != TLookup("int") && t2->ttype != TLookup("string")) && (t1->ttype == TLookup("dummy")))
    {

    }
    else
    {
        yyerror("Error : Incorrect types being compared\n");
        exit(1);
    }
    
}

void CheckType(struct tnode* t1,struct tnode* t2)
{
    if(!(t1->ttype == TLookup("int") && t2->ttype == TLookup("int")))
    {
        yyerror("Error:Type mismatch of operands");
        yyerror("");
        exit(1);
    }
}

void MatchType(struct tnode* t,int type)
{
    if(t->type != type)
    {
        printf("Error:Type mismatch\n");
        yyerror("");
        exit(1);
    }
}

void CheckIfArray(char* varname)
{
	struct Gsymbol* idx = GLookup(varname);

	if(idx == NULL)
	{
		printf("Error : %s Variable not found\n",varname);
        yyerror("");
		exit(1);
	} 

	if(idx->_type == 0)
	{
		printf("Error : %s is not array type\n",varname);
        yyerror("");
		exit(1);
	}
}

void AssignCheckType(struct tnode* t1,struct tnode* t2)
{
	if(t1->ttype != t2->ttype && (t1->ttype!=TLookup("dummy") && t2->ttype!=TLookup("dummy")))
    {
        printf("Error:Type mismatch of operands in assign\n");
        yyerror("");
        exit(1);
    }
}

void CheckBoolType(struct tnode* t)
{
    if(t->ttype != TLookup("bool"))
    {
        printf("Expression is not bool type\n");
        yyerror("");
        exit(1);   
    }
}

void CheckIntType(struct tnode* t)
{
    if(t->ttype != TLookup("int"))
    {
        printf("Expression is not int type\n");
        yyerror("");
        exit(1);
    }
}

struct Gsymbol* GLookup(char* variable_name)
{
    if(!variable_name)
    {
        return NULL;
    }

	struct Gsymbol* curr = start;
    
	while(curr!=NULL)
	{
		if(strcmp(curr->name,variable_name) == 0)
		{
			return curr;
		}
		curr = curr->next;
	}

	return NULL;
}

struct Lsymbol* LocalLookup(char* variable_name)
{
    if(!variable_name)
    {
        return NULL;
    }

    struct Lsymbol* curr = head2;

    while(curr != NULL)
    {
        if(strcmp(curr->name,variable_name) == 0)
        {
            return curr;
        }

        curr = curr->next;
    }

    return NULL;
}

struct Paramstruct* ParamLookup(char* variable_name)
{
    if(!variable_name)
    {
        return NULL;
    }

    struct Paramstruct* curr = head;

    while(curr != NULL)
    {
        if(strcmp(curr->name,variable_name) == 0)
        {
            return curr;
        }

        curr = curr->next;
    }

    return NULL;   
}



//checks if a particular ID is valid or not
void checkID(char* varname)
{

   struct Lsymbol* curr1 = LocalLookup(varname);
   struct Paramstruct* curr2 = ParamLookup(varname);
   struct Gsymbol* curr3 = GLookup(varname); 

	if(!curr1 && !curr2 && !curr3)
   {	
    	printf("Error : %s Variable/function not declared",varname);
        yyerror("");
    	exit(1);
   }                                
}

void GInstall(char* variable_name, struct Typetable* type, struct Classtable* ctype ,int _type, int size)
{
    if(!variable_name)
    {
        return;
    }
    //check if already declared
    struct Gsymbol* curr = start;
	while(curr)
	{
		if(!strcmp(curr -> name,variable_name))
		{
			printf("Error: %s Variable redeclaration\n",curr->name);
            yyerror("");
			exit(1);
		}
		curr = curr->next;
	}

	struct Gsymbol* new_entry = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	new_entry -> name = variable_name;
	new_entry -> type = type;
    new_entry -> ctype = ctype;
	new_entry -> _type = _type;
	new_entry -> size = size;
	new_entry -> ParamList = NULL;
	new_entry -> LocalSymbols = NULL;
	new_entry -> next = NULL;

	if(_type != 2)
	{
		new_entry -> binding = bind;
		bind += size;
	}
	else
	{
		new_entry -> binding = get_label();
	}

	if(start == NULL)
	{
		start = new_entry;
		end = new_entry;
	}
	else
	{
		end->next = new_entry;
		end = new_entry;
	}
}

void PLocal()
{
    struct Lsymbol* curr = head2;

    while(curr)
    {
        printf("%s   %s    %d\n",curr->name,curr->type->name,curr->binding);
        curr = curr->next;
    }
}

//checks if same para variable name is already present
void CheckDuplicateParam(char* name)
{
    if(!name)
    {
        return;
    }
    struct Paramstruct* curr = head;

    while(curr != NULL)
    {
        if(strcmp(curr -> name,name) == 0)
        {
            printf("Error %s variable name already present\n",name);
            yyerror("");
            exit(1);
        }
        curr = curr -> next;
    }
}

void InsertParam(char* name,struct Typetable* type)
{

    CheckDuplicateParam(name);

	struct Paramstruct* new_node = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
	new_node -> name = name;
	new_node -> type = type;
    new_node -> ctype = NULL;
    new_node -> binding = bind_param--;
	new_node -> next = NULL;

	if(head == NULL)
	{
		head = new_node;
		tail = new_node;
	}

	else
	{
		tail -> next = new_node;
		tail = new_node;
	}
}

void InsertSelfToParam()
{
    struct Paramstruct *tmp = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    char *s = (char*)malloc(sizeof("self "));
    tmp -> name = (char*)malloc(sizeof(s));

    strcpy(tmp->name,"self");
    tmp -> type = NULL;
    tmp -> ctype = class;
    tmp -> binding = 0;
    tmp -> next = NULL;

    if(head == NULL)
    {
        head = tail = tmp;
    }
    else
    {
        tail -> next = tmp;
        tail = tmp;
    }
}

void clearParamList()
{
	head = NULL;
	tail = NULL;

    bind_param = -3;
}

void clearLSTList()
{
	head2 = NULL;
	tail2 = NULL;

	list_size = 0;
}

//insert parameter list in a given function name
void InsertParamList(char* name)
{
	struct Gsymbol* curr = GLookup(name);
	curr -> ParamList = head;
}

//checks if same local variable name is already present
void CheckDuplicateLocalSymbol(char* name)
{
    if(!name)
    {
        return;
    }
	struct Lsymbol* curr = head2;

	while(curr != NULL)
	{
		if(strcmp(curr -> name,name) == 0)
		{
			printf("Error %s variable name already present\n",name);
			exit(1);
		}
		curr = curr -> next;
	}
}


//insert local symbol into current local symbol list
void InsertLocalSymbol(char* name, struct Typetable* type)
{
	struct Lsymbol* new_node = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
	new_node -> name = name;
	new_node -> type = type;
	new_node -> binding = ++list_size;
	new_node -> next = NULL;

	CheckDuplicateLocalSymbol(name);
    CheckDuplicateParam(name);

	if(head2 == NULL)
	{
		head2 = tail2 = new_node;
	}
	else
	{
		tail2 -> next = new_node;
		tail2 = new_node;
	}
}

void InsertLST(char *name)
{
	struct Gsymbol* idx = GLookup(name);

	idx -> LocalSymbols = head2;

}

void PrintSymbolTable()
{
	struct Gsymbol* curr = start;
	//printf("Name            Type      _Type     Size     Binding\n");
	while(curr!=NULL)
	{
		//printf("%s               %s         %d        %d         %d\n",curr->name,curr->type->name,curr->_type,curr->size,curr->binding);
		curr = curr->next;
	}
}

void PrintLST(char* name)
{
	struct Gsymbol* idx = GLookup(name);

	struct Lsymbol* curr = idx -> LocalSymbols;

	printf("Function %s: Local variables\n",name);
	while(curr)
	{
		printf("%s   %s    %d\n",curr->name,curr->type->name,curr->binding);
		curr = curr -> next;
	}
}

void PrintParamList(char* name)
{
    struct Paramstruct* curr = head;
    printf("Function %s: Parameters\n",name);    
    while(curr)
    {
     	printf("%s    %s\n",curr->name,curr->type->name);
     	curr = curr -> next;
    }
	// struct Gsymbol* idx = GLookup(name);

	// struct Paramstruct* curr = idx -> ParamList;
	// printf("Function %s: Parameters\n",name);

	// while(curr)
	// {
	// 	printf("%s    %d\n",curr->name,curr->type);
	// 	curr = curr -> next;
	// }
}

void CheckReturnType(char* name,struct Typetable* t)
{
	struct Gsymbol* idx = GLookup(name);

	if(idx == NULL)
	{
		printf("Function %s not declared\n",name);
        yyerror("");
		exit(1);
	}

    if(idx->type != t)
	{
		printf("Return type of declared & defined function %s does not match",name);
        yyerror("");
		exit(1);
	}
}

void CheckReturnVal(struct tnode* t,struct Typetable* type)
{
    if(t->ttype != type)
    {
        printf("Value returned does not match with return type\n");
        yyerror("");
        exit(1);
    }
}

void CheckIfFunction(char* name)
{
	struct Gsymbol* idx = GLookup(name);

	if(idx -> _type != 2)
	{
		printf("%s is not a function\n",name);
        yyerror("");
		exit(1);
	}
}

void CheckParamList(char *name) //checks if parameters in declaration and definition are consistent
{
	struct Gsymbol* idx = GLookup(name);

	struct Paramstruct* curr = idx -> ParamList;
	struct Paramstruct* curr2 = head;
	while(curr && curr2)
	{
		if(curr -> type != curr2 ->type)
		{
			printf("%s function declaration & definition param do not match\n",name);
            yyerror("");
			exit(1);
		}

		curr -> name = curr2 -> name;

		curr = curr -> next;
		curr2 = curr2 -> next;
	}

	if(curr != curr2)
	{
		printf("%s function declaration & definition param do not match\n",name);
        yyerror("");
		exit(1);
	}

}

//check if function is declared in a class,match the return type and parameter list
void ClassCheckFunction(char *function_name,struct Typetable *return_type)
{
    if(!function_name)
    {
        return;
    }
    struct Memberfunclist *curr = class -> Vfuncptr;
    while(curr)
    {
        if(!strcmp(function_name,curr->name))
        {
            break;
        }
        curr = curr -> next;
    }

    if(curr == NULL)
    {
        printf("Error: %s func not declared\n",function_name);
        yyerror("");
        exit(1);
    }

    //check if return types match
    if(curr -> type != return_type)
    {
        printf("Error: return type of declared and defined func %s do not match\n",function_name);
        yyerror("");
        exit(1);
    }

    struct Paramstruct* declared_list = curr -> paramlist;
    struct Paramstruct* defined_list = head;

    while(declared_list && defined_list)
    {
        if(strcmp(declared_list->name, defined_list->name) || declared_list->type!=defined_list->type)
        {
            printf("Error:%s declaration and defn do not match\n",function_name);
            yyerror("");
            exit(1);
        }

        declared_list = declared_list -> next;
        defined_list = defined_list -> next;
    }

    if(declared_list || defined_list)
    {
        printf("Error:%s Number of param in declaration and defn do not match\n",function_name);
        yyerror("");
        exit(1);
    } 
}


void CheckInformalParamList(struct Paramstruct* formal_param,struct tnode* t)  //checks if informalparam matches with formal param during a function call
{
	struct Paramstruct* curr = formal_param;
	struct tnode* curr2;

    int cnt_formal = 0;
    while(curr)
    {
        cnt_formal++;
        curr = curr->next;
    }
    curr = formal_param;

    int cnt_informal = 0;
    curr2 = t; 
    while(curr2)
    {
        cnt_informal++;
        curr2 = curr2 -> right;
    }

    if(cnt_informal != cnt_formal)
    {
        printf("%s Incorrect no. of arguments",t->left->varname);
        yyerror("");
        exit(1);
    }

    cnt_informal--;
    while(curr)
    {
        curr2 = t;

        for(int i=0;i<cnt_informal;i++)
        {
            curr2 = curr2 -> right;
        }

        if(curr->type != curr2->left->ttype)
        {
            printf("%s function declaration & definition param do not match\n",t->left->varname);
            yyerror("");
            exit(1);    
        }
        cnt_informal--;
        curr = curr -> next;
    }
	
}

//check if a field-name is already present in current list of fields
struct Fieldlist* FieldNameLookup(char* name)
{
    if(!name)
    {
        return NULL;
    }

    struct Fieldlist* curr = Fhead;
    while(curr)
    {
        if(!strcmp(curr->name,name))
        {
            return curr;
        }
        curr = curr -> next;
    }

    return NULL;
}

//checks if a particular field belongs to a type or not(if yes then returns a pointer to the field)
struct Fieldlist* FLookup(struct Typetable *type, char* name)
{
    if(!type || !name)
    {
        return NULL;
    }

    struct Fieldlist* curr = type -> fields;
    while(curr)
    {
        if(!strcmp(curr->name,name))
        {
            return curr;
        }
        curr = curr -> next;
    }
    return NULL;
}

void FieldInstall(struct Typetable *type, char* name)
{
    struct Fieldlist* tmp; 

    tmp = FieldNameLookup(name);
    if(tmp)
    {
        printf("Error : Same named field already present\n");
        yyerror("");
        exit(1);
    }

    tmp = FLookup(type,name);
    if(tmp)
    {
        printf("Error : Same named field already present\n");
        yyerror("");
        exit(1);
    }

    tmp = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
    tmp -> name  = malloc(sizeof(name));
    strcpy(tmp->name,name);

    if(TypeInfo)
    {
        tmp -> typename  = malloc(sizeof(TypeInfo));
        strcpy(tmp->typename,TypeInfo);
    }
    else
    {
        tmp -> typename = NULL;
    }
    

    tmp -> type = type;
    tmp -> next = NULL;

    if(Fhead == NULL)
    {
        Fhead = Ftail = tmp;
    }
    else
    {
        Ftail -> next = tmp;
        Ftail = tmp;
    }

    TypeInfo = NULL;
}

struct Typetable* TLookup(char *name)
{
    if(!name)
    {
        return NULL;
    }

    struct Typetable* curr = Thead;

    while(curr)
    {
        if(!strcmp(curr->name,name))
        {
            return curr;
        }
        curr = curr -> next;
    }

    return NULL;
}

void TInstall(char *name,int size,struct Fieldlist* fields)
{
    //check if type with same name is already present
    struct Typetable* tmp = TLookup(name);
    if(tmp)
    {
        printf("Error : %s type already exists",name);
        yyerror("");
        exit(1);
    }

    tmp = (struct Typetable*)malloc(sizeof(struct Typetable));
    tmp -> name = name;
    tmp -> fields = fields;
    if(!fields)
    {
        tmp -> size = size;
    }
    tmp -> next = NULL;

    if(Thead == NULL)
    {
        Thead = Ttail = tmp;
    }
    else
    {
        Ttail -> next = tmp;
        Ttail = tmp;
    }

    struct Fieldlist* curr = fields;
    int cnt = 0;    //to keep track of field index

    while(curr)
    {
        if(!strcmp(curr -> type -> name,"dummy"))    //either type is same as current type or does not exist
        {
            if(strcmp(curr->typename,name))
            {
                printf("Error : %s type does not exist\n",curr->typename);
                yyerror("");
                exit(1);
            }
            else
            {
                curr -> type = TLookup(name);
            }
        }
        curr -> fieldIndex = cnt++;
        curr =  curr -> next;
    }

    if(fields)
    {
        tmp -> size = cnt;
    }
    
    if(cnt>8)
    {
        printf("Error : %s type has more than 8 fields\n",name);
        yyerror("");
        exit(1);
    }

    Fhead = Ftail = NULL;   //reset the fields list   
}

void InitTypeTable()
{
    TInstall("int",1,NULL);
    TInstall("string",1,NULL);
    TInstall("bool",1,NULL);
    TInstall("void",0,NULL);
    TInstall("dummy",0,NULL);
}

void PrintTypetable()
{
    struct Typetable* curr = Thead;

    while(curr)
    {
        printf("Type Name : %s\n",curr->name);

        struct Fieldlist* fcurr = curr->fields;
        while (fcurr)
        {
            printf("Field : %s, Type : %s\n",fcurr->name,fcurr->type->name);
            fcurr = fcurr -> next;
        }
        printf("\n");
        curr = curr -> next;
    }
}

void PrintClassTable()
{
    struct Classtable *curr = Chead;
    printf("CLASS: ");
    while(curr)
    {
        printf("%s\n",curr->name);
        curr = curr -> next;
    }
}

struct Classtable* CLookup(char *name)
{
    if(!name)
    {
        return NULL;
    }

    struct Classtable *curr = Chead;

    while(curr)
    {
        if(!strcmp(curr->name,name))
        {
            return curr;
        }
        curr = curr -> next;
    }

    return NULL;
} 

struct Classtable* CInstall(char *name,char *parent_name)
{
    //first check if this name is already a type name or a class name
    if(TLookup(name))
    {
        printf("Error : %s exists as a type name\n",name);
        yyerror("");
        exit(1);
    }
    if(CLookup(name))
    {
        printf("Error : %s exists as a class name\n",name);
        yyerror("");
        exit(1);
    }

    struct Classtable* tmp = (struct Classtable*)malloc(sizeof(struct Classtable));
    tmp -> name = name;
    tmp -> Memberfield = NULL;  //will be set by final installation
    tmp -> Vfuncptr = NULL;     //will be set by final installation
    tmp -> Parentptr = NULL;    //in later stages
    if(parent_name)
    {
        if(!CLookup(parent_name))
        {
            printf("Error : %s parent class not declared\n",parent_name);
            yyerror("");
            exit(1);
        }
        tmp -> Parentptr = CLookup(parent_name);
    }
    tmp -> Class_index = class_idx++;
    tmp -> Fieldcount = 0;  //will be set by final installation
    tmp -> Methodcount = 0; //will be set by final installation
    tmp -> next = NULL;

    if(Chead == NULL)
    {
        Chead = Ctail = tmp;
    }

    else
    {
        Ctail -> next = tmp;
        Ctail = tmp;
    }

    return tmp;
}

void CInstallFinal()
{
    struct Fieldlist *tmp1 = Fhead;
    struct Memberfunclist *tmp2 = Mfhead;

    int field_count = 0, method_count = 0;

    while(tmp1)
    {
        field_count++;
        tmp1 = tmp1->next;
    }
    class -> Fieldcount = field_count;

    while(tmp2)
    {
        method_count++;
        tmp2 = tmp2->next;
    }
    class -> Methodcount = method_count;

    class -> Memberfield = Fhead;
    class -> Vfuncptr = Mfhead;
}

struct Fieldlist* Class_FLookup(struct Classtable *ctype,char *field_name)
{
    if(!field_name)
    {
        return NULL;
    }

    struct Fieldlist *tmp = ctype -> Memberfield;
    while(tmp)
    {
        if(!strcmp(tmp->name,field_name))
        {
            return tmp;
        }
        tmp = tmp -> next;
    }

    return NULL;
}

//first checks if field name is already present
//if not then adds the field to the fieldlist
void Class_FieldInstall(char* name,struct Typetable *type, struct Classtable *ctype)
{
    if(type == NULL && ctype == NULL)
    {
        printf("Error : Type of is not defined\n");
        yyerror("");
        exit(1);
    }
    
    if(!name)
    {
        return;
    }
    //check if this name is already present in current list of fields
    struct Fieldlist *curr = Fhead;
    int cnt = 0;
    while(curr)
    {
        if(!strcmp(curr->name,name))
        {
            printf("Error: %s field already exists\n",name);
            yyerror("");
            exit(1);
        }
        curr = curr -> next;
        cnt++;
    }

    struct Fieldlist *tmp = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
    tmp -> name = (char*)malloc(sizeof(name));
    strcpy(tmp -> name,name);
    tmp -> fieldIndex = cnt;
    tmp -> type = type;
    tmp -> ctype = ctype;
    tmp -> typename = NULL;
    tmp -> next = NULL;

    if(Fhead == NULL)
    {
        Fhead = Ftail = tmp;
    }
    else
    {
        Ftail -> next = tmp;
        Ftail = tmp;
        Ftail -> next = NULL;
    }
}


void Class_MethodInstall(char *function_name,struct Typetable *type,struct Paramstruct* plist)
{
    
    if(!function_name)
    {
        return;
    }
    
    //check if this function name already exists in current list of methods
    struct Memberfunclist* curr = Mfhead;
    while(curr)
    {
        if(!strcmp(curr->name,function_name))
        {
            printf("Error: %s function already exists\n",function_name);
            yyerror("");
            exit(1);
        }
        curr = curr -> next;
    }

    struct Memberfunclist *tmp = (struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
    tmp -> name = (char*)malloc(sizeof(function_name));
    strcpy(tmp -> name,function_name);
    tmp -> type = type;
    tmp -> paramlist = plist;
    tmp -> Flabel = get_label();
    tmp -> next = NULL;

    if(Mfhead == NULL)
    {
        Mfhead = Mftail = tmp;
    }
    else
    {
        Mftail -> next = tmp;
        Mftail = tmp;
    }

}

struct Memberfunclist* MLookup(struct Classtable *ctype,char *function_name)
{
    if(ctype == NULL || !function_name)
    {
        return NULL;
    }

    struct Memberfunclist* tmp = ctype -> Vfuncptr;
    while(tmp)
    {
        if(!strcmp(tmp->name,function_name))
        {
            return tmp;
        }
        tmp = tmp -> next;
    }

    return NULL;
}

void ClassFunctionSetup(char *function_name)
{
    if(!function_name)
    {
        return;
    }

    struct Memberfunclist *curr = Mfhead;
    while(curr)
    {
        if(!strcmp(function_name,curr->name))
        {
            break;
        }
        curr = curr -> next;
    }

    fprintf(fp,"F%d: ",curr->Flabel);	//label for the function
	fprintf(fp,"PUSH BP\n");
    fprintf(fp,"MOV BP,SP\n");

    //now push local variables
    struct Lsymbol *curr2 = head2;
    int local_vars = 0;
	while(curr2 != NULL)
	{
		local_vars++;
		curr2 = curr2 -> next;
	}	

    fprintf(fp,"ADD SP,%d\n",local_vars);
}

void ClassFunctionPopLocal()
{
    struct Lsymbol *curr2 = head2;
    int local_vars = 0;
	while(curr2 != NULL)
	{
		local_vars++;
		curr2 = curr2 -> next;
	}	

    fprintf(fp,"SUB SP,%d\n",local_vars);
}

void ActRecordSetup(char* name)
{
	struct Gsymbol* idx = GLookup(name);
	fprintf(fp,"F%d: ",idx->binding);	//label for the function
	fprintf(fp,"PUSH BP\n");
    fprintf(fp,"MOV BP,SP\n");
			
	//now push local variables(contained in LocalSymbols)
	struct Lsymbol* curr = idx -> LocalSymbols;
    int local_vars = 0;
	while(curr != NULL)
	{
		local_vars++;
		curr = curr -> next;
	}	

    fprintf(fp,"ADD SP,%d\n",local_vars);
}

void PopLocalVariables(char* name)
{
	struct Gsymbol* idx = GLookup(name);
	struct Lsymbol* curr = idx -> LocalSymbols;

	int cnts = 0;

	while(curr != NULL)
	{
		cnts++;
		curr = curr -> next;
	}

	fprintf(fp,"SUB SP,%d\n",cnts);
}



int BasicCodeGen(struct tnode* t)
{
    if(!t)
    {
        return -1;
    }
    if(t->type == var_node)
    {
        int i = get_reg();

        struct Lsymbol* curr1 = LocalLookup(t->varname);
        struct Paramstruct* curr2 = ParamLookup(t->varname);
        struct Gsymbol* curr3 = GLookup(t->varname);

        if(curr1)
        {
            fprintf(fp,"MOV R%d,BP\n",i);
            fprintf(fp,"ADD R%d,%d\n",i,curr1->binding);
            fprintf(fp,"MOV R%d,[R%d]\n",i,i);

            return i;
        }

        else if(curr2)
        {
            int cnt = 0,cnt1 = 0;
            struct Paramstruct* curr = head;

            while(curr)
            {
                curr = curr -> next;
                cnt++;
            }

            curr = head;
            while(curr)
            {
                cnt1++;
                if(strcmp(curr -> name,t->varname) == 0)
                {
                    break;
                }
                curr = curr -> next;
            }

            fprintf(fp,"MOV R%d,BP\n",i);
            fprintf(fp,"SUB R%d,%d\n",i,2+cnt1);
            fprintf(fp,"MOV R%d,[R%d]\n",i,i);

            return i;
        }

        else if(curr3)
        {
            int addr = curr3->binding;
            fprintf(fp,"MOV R%d,[%d]\n",i,addr);

            return i;
        }

        else
        {
        	printf("hi1Error : %s Variable not declared\n",t->varname);
            yyerror("");
        	exit(1);
        }
        return i;
    }

    else if(t->type == field_node)
    {
        int i = get_reg();

        struct Lsymbol* curr1 = LocalLookup(t->left->varname);
        struct Paramstruct* curr2 = ParamLookup(t->left->varname);
        struct Gsymbol* curr3 = GLookup(t->left->varname);

        if(curr1)
        {
            fprintf(fp,"MOV R%d,BP\n",i);
            fprintf(fp,"ADD R%d,%d\n",i,curr1->binding);
            fprintf(fp,"MOV R%d,[R%d]\n",i,i);
        }

        else if(curr2)
        {
            int cnt = 0,cnt1 = 0;
            struct Paramstruct* curr = head;

            while(curr)
            {
                curr = curr -> next;
                cnt++;
            }

            curr = head;
            while(curr)
            {
                cnt1++;
                if(strcmp(curr -> name,t->left->varname) == 0)
                {
                    break;
                }
                curr = curr -> next;
            }

            fprintf(fp,"MOV R%d,BP\n",i);
            fprintf(fp,"SUB R%d,%d\n",i,2+cnt1);
            fprintf(fp,"MOV R%d,[R%d]\n",i,i);
        }

        else if(curr3)
        {
            int addr = curr3->binding;
            fprintf(fp,"MOV R%d,[%d]\n",i,addr);
        }

        else
        {
        	printf("hi2Error : %s Variable not declared\n",t->varname);
            yyerror("");
        	exit(1);
        }
        
        //now register i contains the value of the variable at a stack location which is the heap address
        //now we need to find the final value using attributes of the field node
        struct tnode* curr = t;
        struct Typetable* curr_type = t -> left -> ttype;
        struct Classtable* curr_ctype = t -> left -> ctype; 
        while(curr)
        {
            if(curr_type)
            {
                struct Fieldlist* field = FLookup(curr_type,curr->right->varname);
                if(!field)
                {
                    printf("Error : %s field does not belong to %s\n",curr->right->varname,curr_type->name);
                    yyerror("");
                    exit(1);
                }

                fprintf(fp,"ADD R%d,%d\n",i,field->fieldIndex);
                fprintf(fp,"MOV R%d,[R%d]\n",i,i);

                curr_ctype = field -> ctype;
                curr_type = field -> type;
                curr = curr -> mid;
            }

            else
            {
                struct Fieldlist* field = Class_FLookup(curr_ctype,curr->right->varname);
                if(!field)
                {
                    printf("Error : %s field does not belong to %s\n",curr->right->varname,curr_ctype->name);
                    yyerror("");
                    exit(1);
                }

                fprintf(fp,"ADD R%d,%d\n",i,field->fieldIndex);
                fprintf(fp,"MOV R%d,[R%d]\n",i,i);

                curr_type = field -> type;    
                curr_ctype = field -> ctype;
                curr = curr -> mid;
            }
            
        }

        return i;   //value of the field node
    }

    else if(t->type == num_node)
    {
        int i = get_reg();
        fprintf(fp,"MOV R%d,%d\n",i,t->val);

        return i;
    }

    else if(t->type == str_node)
    {
    	int i = get_reg();
    	fprintf(fp,"MOV R%d,%s\n",i,t->str_val);

        return i;
    }

    else if(t->type == array_node)
    {
    	int i = get_reg();
    	int j = BasicCodeGen(t->right);
    	
    	struct Gsymbol* idx = GLookup(t->left->varname);
    	if(idx == NULL)
    	{
    		printf("Error : %s Variable not found",t->left->varname);
    		exit(1);
    	}

    	int addr = idx->binding;
    	fprintf(fp,"ADD R%d,%d\n",j,addr);
    	fprintf(fp,"MOV R%d,[R%d]\n",i,j);

    	free_reg();

    	return i;
    }

    else if(t->type == function_node)
    {
        int i = FunctionCodeGen(t);
        return i;
    }

    else if(t->type == field_function_node)
    {
        int i = FieldFunctionCodeGen(t);
        return i;
    }

    else if(t->type == alloc_node)
    {
        int i = get_reg();
        int j = get_reg();
        fprintf(fp,"MOV R%d, \"Alloc\"\n", j);
        fprintf(fp,"PUSH R%d\n",j);
        fprintf(fp,"MOV R%d, 8\n", j);
        fprintf(fp,"PUSH R%d\n",j);
        fprintf(fp,"PUSH R%d\n",j);
        fprintf(fp,"PUSH R%d\n",j);
        fprintf(fp,"PUSH R%d\n",j);
        fprintf(fp,"CALL 0\n");
        fprintf(fp,"POP R%d\n",i);
        fprintf(fp,"POP R%d\n",j);
        fprintf(fp,"POP R%d\n",j);
        fprintf(fp,"POP R%d\n",j);
        fprintf(fp,"POP R%d\n",j);
        free_reg(); //register j gets freed
    
        return i;
    }

    else if(t->type == null_node)
    {
        int i = get_reg();
        fprintf(fp,"MOV R%d,-1\n", i);

        return i;
    }

    int p = BasicCodeGen(t->left);
    int q = BasicCodeGen(t->right);

    switch(t->type)
    {
        case 3:
            fprintf(fp,"ADD R%d,R%d\n",p,q);
            break;
        case 4:
            fprintf(fp,"SUB R%d,R%d\n",p,q);
            break;
        case 5:
            fprintf(fp,"MUL R%d,R%d\n",p,q);
            break;
        case 6:
            fprintf(fp,"DIV R%d,R%d\n",p,q);
            break;
        case 36:
        	fprintf(fp,"MOD R%d,R%d\n",p,q);
            break;
    }
    
    free_reg();

    return p;
}

void AssignArrayCodeGen(struct tnode* t)
{
	int i = BasicCodeGen(t->mid); //value to be assigned,result is stored in Ri
    struct Gsymbol* idx = GLookup(t->left->varname);

    if(idx == NULL)
    {
       	printf("hi3Error : %s Variable not declared",t->left->varname);
        yyerror("");
        exit(1);
    }

    int j = BasicCodeGen(t->right);	//value of index to be accessed

    int addr = idx->binding;
    int k = get_reg();

    fprintf(fp,"MOV R%d,%d\n",k,addr);	//value of base address
    fprintf(fp,"ADD R%d,R%d\n",k,j);	//now k contains final address
    fprintf(fp,"MOV [R%d],R%d\n",k,i);
	
    free_reg();
    free_reg();
    free_reg();
}

void readCodeGen(char* c)
{	
    struct Lsymbol* curr1 = LocalLookup(c);
    struct Paramstruct* curr2 = ParamLookup(c);
    struct Gsymbol* curr3 = GLookup(c);

    int j = get_reg();

    if(curr1)
    {
        fprintf(fp,"MOV R%d,BP\n",j);
        fprintf(fp,"ADD R%d,%d\n",j,curr1->binding);
    }

    else if(curr2)
    {
        fprintf(fp,"MOV R%d,BP\n",j);
        fprintf(fp,"ADD R%d,%d\n",j,curr2->binding);
    }

    else if(curr3)
    {
        int addr = curr3->binding;
        fprintf(fp,"MOV R%d,%d\n",j,addr);
    }

    else
    {
        printf("hi4Error : %s Variable not declared\n",c);
        yyerror("");
        exit(1);
    }

    int i = get_reg();  //to push values in the stack
    fprintf(fp,"MOV R%d,\"Read\"\n",i);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"MOV R%d,%d\n",i,-1);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"MOV R%d,R%d\n",i,j);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"CALL 0\n");
    fprintf(fp,"POP R%d\n",i);
    fprintf(fp,"POP R%d\n",i);
    fprintf(fp,"POP R%d\n",i);
    fprintf(fp,"POP R%d\n",i);
    fprintf(fp,"POP R%d\n",i);

    free_reg(); //for Ri
    free_reg(); //for Rj
}

void readFieldCodeGen(struct tnode *t)
{
    int i = get_reg();

    struct Lsymbol* curr1 = LocalLookup(t->left->left->varname);
    struct Paramstruct* curr2 = ParamLookup(t->left->left->varname);
    struct Gsymbol* curr3 = GLookup(t->left->left->varname);

    if(curr1)
    {
        fprintf(fp,"MOV R%d,BP\n",i);
        fprintf(fp,"ADD R%d,%d\n",i,curr1->binding);
        fprintf(fp,"MOV R%d,[R%d]\n",i,i);
    }

    else if(curr2)
    {
        int cnt = 0,cnt1 = 0;
        struct Paramstruct* curr = head;

        while(curr)
        {
            curr = curr -> next;
            cnt++;
        }

        curr = head;
        while(curr)
        {
            cnt1++;
            if(strcmp(curr -> name,t->left->left->varname) == 0)
            {
                break;
            }
            curr = curr -> next;
        }

        fprintf(fp,"MOV R%d,BP\n",i);
        fprintf(fp,"SUB R%d,%d\n",i,2+cnt1);
        fprintf(fp,"MOV R%d,[R%d]\n",i,i);
    }

    else if(curr3)
    {
        int addr = curr3->binding;
        fprintf(fp,"MOV R%d,[%d]\n",i,addr);
    }

    else
    {
        printf("hi5Error : %s Variable not declared\n",t->varname);
        yyerror("");
        exit(1);
    }
    
    //now register i contains the value of the variable at a stack location which is the heap address

    struct tnode* curr = t -> left;
    struct Typetable* curr_type = t -> left -> left -> ttype;
    struct Classtable* curr_ctype = t -> left -> left -> ctype; 
     
    while(curr -> mid)
    {
        if(curr_type)
        {
            struct Fieldlist* field = FLookup(curr_type,curr->right->varname);
            if(!field)
            {
                printf("Error : %s field does not belong to %s\n",curr->right->varname,curr_type->name);
                exit(1);
            }

            fprintf(fp,"ADD R%d,%d\n",i,field->fieldIndex);
            fprintf(fp,"MOV R%d,[R%d]\n",i,i);

            curr_type = field -> type;
            curr_ctype = field -> ctype;
            curr = curr -> mid;
        }
        else
        {
            struct Fieldlist* field = Class_FLookup(curr_ctype,curr->right->varname);
            if(!field)
            {
                printf("Error : %s field does not belong to %s\n",curr->right->varname,curr_ctype->name);
                exit(1);
            }

            fprintf(fp,"ADD R%d,%d\n",i,field->fieldIndex);
            fprintf(fp,"MOV R%d,[R%d]\n",i,i);

            curr_type = field -> type;
            curr_ctype = field -> ctype;
            curr = curr -> mid;
        }
        
    }

    if(curr_type)
    {
        struct Fieldlist* tmp_field = FLookup(curr_type,curr->right->varname);
        if(!tmp_field)
        {
            printf("Error : %s field does not belong to %s\n",curr->right->varname,curr_type->name);
            exit(1);
        }

        fprintf(fp,"ADD R%d,%d\n",i,tmp_field->fieldIndex); //register i contains the address where the value is to be stored
    }

    else
    {
        struct Fieldlist* ctmp_field = Class_FLookup(curr_ctype,curr->right->varname);
        if(!ctmp_field)
        {
            printf("Error : %s field does not belong to %s\n",curr->right->varname,curr_ctype->name);
            exit(1);
        }

        fprintf(fp,"ADD R%d,%d\n",i,ctmp_field->fieldIndex); //register i contains the address where the value is to be stored
    }
    
    int j = get_reg();  //to push values in the stack
    fprintf(fp,"MOV R%d,\"Read\"\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"MOV R%d,%d\n",j,-1);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"MOV R%d,R%d\n",j,i);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"CALL 0\n");
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);

    free_reg();
    free_reg();
}

void readArrayCodeGen(struct tnode* t)
{
	struct Gsymbol* idx = GLookup(t->left->varname);
	if(idx == NULL)
	{
		printf("Variable not declared\n");
        yyerror("");
		exit(1);
	}

	int addr = idx->binding;
	
   int i = get_reg();  //to push values in the stack
   int j = BasicCodeGen(t->right);

   fprintf(fp,"MOV R%d,\"Read\"\n",i);
   fprintf(fp,"PUSH R%d\n",i);
   fprintf(fp,"MOV R%d,%d\n",i,-1);
   fprintf(fp,"PUSH R%d\n",i);
   fprintf(fp,"MOV R%d,%d\n",i,addr);
   fprintf(fp,"ADD R%d,R%d\n",i,j);
   fprintf(fp,"PUSH R%d\n",i);
   fprintf(fp,"PUSH R%d\n",i);
   fprintf(fp,"PUSH R%d\n",i);
   fprintf(fp,"CALL 0\n");
   fprintf(fp,"POP R%d\n",i);
   fprintf(fp,"POP R%d\n",i);
   fprintf(fp,"POP R%d\n",i);
   fprintf(fp,"POP R%d\n",i);
   fprintf(fp,"POP R%d\n",i);

   free_reg();
   free_reg();
}

void writeCodeGen(struct tnode* t)
{
    int i = BasicCodeGen(t->left);  //value to be printed is in Ri
    int j = get_reg();      //dummy register for pushing values in stack
    fprintf(fp,"MOV R%d,\"Write\"\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"MOV R%d,%d\n",j,-2);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"MOV R%d,R%d\n",j,i);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"CALL 0\n");
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);

    free_reg();
    free_reg();
}

void ifCodeGen(struct tnode* t)
{
    int p,q;
    int lbl;

    p = BasicCodeGen(t->left->left);
    q = BasicCodeGen(t->left->right);
            
    switch(t->left->type)
    {
        case lt_node:
            fprintf(fp, "LT R%d,R%d\n",p,q);
            break;

        case gt_node:
            fprintf(fp, "GT R%d,R%d\n",p,q);
            break;
        
        case eq_node:
            fprintf(fp, "EQ R%d,R%d\n",p,q);
            break;
        
        case neq_node:
            fprintf(fp, "NE R%d,R%d\n",p,q);
            break;
        
        case gte_node:
            fprintf(fp, "GE R%d,R%d\n",p,q);
            break;
        
        case lte_node:
            fprintf(fp, "LE R%d,R%d\n",p,q);
            break;
    }
    free_reg();

    lbl = get_label();
    fprintf(fp,"JZ R%d,LABEL%d\n",p,lbl);

    free_reg();

    MainCodeGen(t->right);
    fprintf(fp,"LABEL%d: ",lbl);
            
}

void ifElseCodeGen(struct tnode* t)
{
    int p,q;
    int lbl1,lbl2;

    p = BasicCodeGen(t->left->left);
    q = BasicCodeGen(t->left->right);
            
    switch(t->left->type)
    {
        case lt_node:
            fprintf(fp, "LT R%d,R%d\n",p,q);
            break;

        case gt_node:
            fprintf(fp, "GT R%d,R%d\n",p,q);
            break;
        
        case eq_node:
            fprintf(fp, "EQ R%d,R%d\n",p,q);
            break;
        
        case neq_node:
            fprintf(fp, "NE R%d,R%d\n",p,q);
            break;
        
        case gte_node:
            fprintf(fp, "GE R%d,R%d\n",p,q);
            break;
        
        case lte_node:
            fprintf(fp, "LE R%d,R%d\n",p,q);
            break;
    }
    free_reg();
            
    lbl1 = get_label();
    lbl2 = get_label();
    fprintf(fp,"JZ R%d,LABEL%d\n",p,lbl1);
    free_reg();
    MainCodeGen(t->right);
    fprintf(fp, "JMP LABEL%d\n",lbl2);
    fprintf(fp,"LABEL%d: ",lbl1);
    MainCodeGen(t->mid);
    fprintf(fp,"LABEL%d: ",lbl2);
            
}

void BreakCodeGen(struct tnode* t)
{
    if(top)
    {
        fprintf(fp,"JMP LABEL%d\n",top->break_label);
    }
}

void ContinueCodeGen(struct tnode* t)
{
    if(top)
    {
        fprintf(fp,"JMP LABEL%d\n",top->continue_label);
    }
}

void WhileCodeGen(struct tnode* t)
{
    int p,q,lbl1,lbl2;

    lbl1 = get_label();
    lbl2 = get_label();

    stack_node* new_node = (stack_node*)malloc(sizeof(stack_node));
    new_node->next = NULL;
    new_node->continue_label = lbl1;
    new_node->break_label = lbl2;
    push(new_node);

    fprintf(fp,"LABEL%d: ",lbl1);
    p = BasicCodeGen(t->left->left);
    q = BasicCodeGen(t->left->right);

    switch(t->left->type)
    {
        case lt_node:
            fprintf(fp, "LT R%d,R%d\n",p,q);
            break;

        case gt_node:
            fprintf(fp, "GT R%d,R%d\n",p,q);
            break;
        
        case eq_node:
            fprintf(fp, "EQ R%d,R%d\n",p,q);
            break;
        
        case neq_node:
            fprintf(fp, "NE R%d,R%d\n",p,q);
            break;
        
        case gte_node:
            fprintf(fp, "GE R%d,R%d\n",p,q);
            break;
        
        case lte_node:
            fprintf(fp, "LE R%d,R%d\n",p,q);
            break;
    }
    free_reg();
    fprintf(fp,"JZ R%d,LABEL%d\n",p,lbl2);
    free_reg();

    MainCodeGen(t->right);
    fprintf(fp, "JMP LABEL%d\n",lbl1);
    fprintf(fp,"LABEL%d: ",lbl2);

    pop();
}

void DoWhileCodeGen(struct tnode* t)
{
    int p,q,lbl1,lbl2;

    lbl1 = get_label();
    lbl2 = get_label();

    MainCodeGen(t->right);

    stack_node* new_node = (stack_node*)malloc(sizeof(stack_node));
    new_node->next = NULL;
    new_node->continue_label = lbl1;
    new_node->break_label = lbl2;
    push(new_node);

    fprintf(fp,"LABEL%d: ",lbl1);
    p = BasicCodeGen(t->left->left);
    q = BasicCodeGen(t->left->right);

    switch(t->left->type)
    {
        case lt_node:
            fprintf(fp, "LT R%d,R%d\n",p,q);
            break;

        case gt_node:
            fprintf(fp, "GT R%d,R%d\n",p,q);
            break;
        
        case eq_node:
            fprintf(fp, "EQ R%d,R%d\n",p,q);
            break;
        
        case neq_node:
            fprintf(fp, "NE R%d,R%d\n",p,q);
            break;
        
        case gte_node:
            fprintf(fp, "GE R%d,R%d\n",p,q);
            break;
        
        case lte_node:
            fprintf(fp, "LE R%d,R%d\n",p,q);
            break;
    }
    free_reg();
    fprintf(fp,"JZ R%d,LABEL%d\n",p,lbl2);
    free_reg();

    MainCodeGen(t->right);
    fprintf(fp, "JMP LABEL%d\n",lbl1);
    fprintf(fp,"LABEL%d: ",lbl2);

    pop();
}

void RepeatCodeGen(struct tnode* t)
{
    int p,q,lbl1,lbl2;

    lbl1 = get_label();
    lbl2 = get_label();

    MainCodeGen(t->right);

    stack_node* new_node = (stack_node*)malloc(sizeof(stack_node));
    new_node->next = NULL;
    new_node->continue_label = lbl1;
    new_node->break_label = lbl2;
    push(new_node);

    fprintf(fp,"LABEL%d: ",lbl1);
    p = BasicCodeGen(t->left->left);
    q = BasicCodeGen(t->left->right);

    switch(t->left->type)
    {
        case lt_node:
            fprintf(fp, "GE R%d,R%d\n",p,q);
            break;

        case gt_node:
            fprintf(fp, "LE R%d,R%d\n",p,q);
            break;
        
        case eq_node:
            fprintf(fp, "NE R%d,R%d\n",p,q);
            break;
        
        case neq_node:
            fprintf(fp, "NE R%d,R%d\n",p,q);
            break;
        
        case gte_node:
            fprintf(fp, "LT R%d,R%d\n",p,q);
            break;
        
        case lte_node:
            fprintf(fp, "GT R%d,R%d\n",p,q);
            break;
    }
    free_reg();
    fprintf(fp,"JZ R%d,LABEL%d\n",p,lbl2);
    free_reg();

    MainCodeGen(t->right);
    fprintf(fp, "JMP LABEL%d\n",lbl1);
    fprintf(fp,"LABEL%d: ",lbl2);

    pop();
}

void AssignCodeGen(struct tnode* t)
{
    int i = BasicCodeGen(t->right); //result is stored in Ri
    int j = get_reg();

    struct Lsymbol* curr1 = LocalLookup(t->left->varname);
    struct Paramstruct* curr2 = ParamLookup(t->left->varname);
    struct Gsymbol* curr3 = GLookup(t->left->varname);

    if(curr1)
    {
        fprintf(fp,"MOV R%d,BP\n",j);
        fprintf(fp,"ADD R%d,%d\n",j,curr1->binding);
        fprintf(fp,"MOV [R%d],R%d\n",j,i);
    }

    else if(curr2)
    {
        fprintf(fp,"MOV R%d,BP\n",j);
        fprintf(fp,"ADD R%d,%d\n",j,curr2->binding);
        fprintf(fp,"MOV [R%d],R%d\n",j,i);

    }

    else if(curr3)
    {
        int addr = curr3->binding;
        fprintf(fp,"MOV [%d],R%d\n",addr,i);
    }

    else
    {
        printf("hi6Error : %s Variable not declared\n",t->varname);
        yyerror("");
        exit(1);
    }

    free_reg();
    free_reg();
}

void AssignFieldCodeGen(struct tnode* t)
{
    int i = get_reg();
    
    struct Lsymbol* curr1 = LocalLookup(t->left->left->varname);
    struct Paramstruct* curr2 = ParamLookup(t->left->left->varname);
    struct Gsymbol* curr3 = GLookup(t->left->left->varname);

    if(curr1)
    {
        fprintf(fp,"MOV R%d,BP\n",i);
        fprintf(fp,"ADD R%d,%d\n",i,curr1->binding);
        fprintf(fp,"MOV R%d,[R%d]\n",i,i);
    }

    else if(curr2)
    {
        int cnt = 0,cnt1 = 0;
        struct Paramstruct* curr = head;

        while(curr)
        {
            curr = curr -> next;
            cnt++;
        }

        curr = head;
        while(curr)
        {
            cnt1++;
            if(strcmp(curr -> name,t->left->left->varname) == 0)
            {
                break;
            }
            curr = curr -> next;
        }

        fprintf(fp,"MOV R%d,BP\n",i);
        fprintf(fp,"SUB R%d,%d\n",i,2+cnt1);
        fprintf(fp,"MOV R%d,[R%d]\n",i,i);
    }

    else if(curr3)
    {
        int addr = curr3->binding;
        fprintf(fp,"MOV R%d,[%d]\n",i,addr);
    }

    else
    {
        printf("hi7Error : %s Variable not declared\n",t->left->left->varname);
        yyerror("");
        exit(1);
    }
    
    //now register i contains the value of the variable at a stack location which is the heap address

    struct tnode* curr = t -> left;
    struct Typetable* curr_type = t -> left -> left -> ttype;
    struct Classtable* curr_ctype =  t -> left -> left -> ctype;
    while(curr -> mid)
    {
        if(curr_type)
        {
            struct Fieldlist* field = FLookup(curr_type,curr->right->varname);
            if(!field)
            {
                printf("Error : %s field does not belong to %s\n",curr->right->varname,curr_type->name);
                exit(1);
            }

            fprintf(fp,"ADD R%d,%d\n",i,field->fieldIndex);
            fprintf(fp,"MOV R%d,[R%d]\n",i,i);

            curr_type = field -> type;
            curr_ctype = field -> ctype;
            curr = curr -> mid;
        }
        else
        {
            struct Fieldlist* field = Class_FLookup(curr_ctype,curr->right->varname);
            if(!field)
            {
                printf("Error : %s field does not belong to %s\n",curr->right->varname,curr_ctype->name);
                exit(1);
            }

            fprintf(fp,"ADD R%d,%d\n",i,field->fieldIndex);
            fprintf(fp,"MOV R%d,[R%d]\n",i,i);

            curr_type = field -> type;
            curr_ctype = field -> ctype;
            curr = curr -> mid;
        }
        
    }

    if(curr_type)
    {
        struct Fieldlist* tmp_field = FLookup(curr_type,curr->right->varname);
        if(!tmp_field)
        {
            printf("Error : %s field does not belong to %s\n",curr->right->varname,curr_type->name);
            exit(1);
        }

        fprintf(fp,"ADD R%d,%d\n",i,tmp_field->fieldIndex); //register i contains the address where the value is to be stored
    }

    else
    {
        struct Fieldlist* ctmp_field = Class_FLookup(curr_ctype,curr->right->varname);
        if(!ctmp_field)
        {
            printf("Error : %s field does not belong to %s\n",curr->right->varname,curr_ctype->name);
            yyerror("");
            exit(1);
        }

        fprintf(fp,"ADD R%d,%d\n",i,ctmp_field->fieldIndex); //register i contains the address where the value is to be stored
        
    }
    
    int j = BasicCodeGen(t->right); //register j contains the value to be assigned to the field
    fprintf(fp,"MOV [R%d],R%d\n",i,j);

    free_reg();
    free_reg();
}

int FunctionCodeGen(struct tnode* t)
{
    //save local registers in the stack
    //printf("function called");
    int stored_reg = used;
    for(int i=0;i<=used;i++)
    {
        fprintf(fp,"PUSH R%d\n",i);
    }
    used = -1;   //all registers are make available for the called function

    MainCodeGen(t->right);  //for the argument list

    int label = GLookup(t->left->varname)->binding;  //label of c

    fprintf(fp,"ADD SP,1\n"); //for return value
    fprintf(fp,"CALL F%d\n",label);
    fprintf(fp,"SUB SP,1\n");

    //now pop out the arguments
    struct Paramstruct* curr = GLookup(t->left->varname)->ParamList;
    int parameters = 0;
    while(curr)
    {
        parameters++;
        curr = curr -> next;
    }
    fprintf(fp,"SUB SP,%d\n",parameters);   //pop out the arguments

    //now pop out stored registers
    for(int j = stored_reg;j>=0;j--)
    {
        fprintf(fp,"POP R%d\n",j);
    }

    used = stored_reg;  //setting the number of registers back to original value

    int i = get_reg();
    //now save the return value
    fprintf(fp,"MOV R%d,SP\n",i);
    fprintf(fp,"ADD R%d,%d\n",i,stored_reg + parameters + 2);
    fprintf(fp,"MOV R%d,[R%d]\n",i,i);  //return value stored in Ri

    return i;   
}

int FieldFunctionCodeGen(struct tnode *t)
{
    //save local registers in the stack
    int stored_reg = used;
    for(int i=0;i<=used;i++)
    {
        fprintf(fp,"PUSH R%d\n",i);
    }
    used = -1;   //all registers are make available for the called function

    //now push the heap address of field in the stack
    int i = BasicCodeGen(t->left);
    fprintf(fp,"PUSH R%d\n",i);

    MainCodeGen(t->Arglist);

    struct Memberfunclist *tmp = MLookup(t->left->ctype,t->right->varname); 
    if(!tmp)
    {
        printf("%s\n%s\n",t->left->ctype->name,t->right->varname);
        yyerror("");
        exit(1);
    }
    int label = tmp -> Flabel;

    fprintf(fp,"ADD SP,1\n"); //for return value
    fprintf(fp,"CALL F%d\n",label);
    fprintf(fp,"SUB SP,1\n");

    //now pop out the arguments
    struct Paramstruct* curr = tmp -> paramlist;
    int parameters = 0;
    while(curr)
    {
        parameters++;
        curr = curr -> next;
    }
    fprintf(fp,"SUB SP,%d\n",parameters + 1);   //pop out the arguments + field address

    //now pop out stored registers
    for(int j = stored_reg;j>=0;j--)
    {
        fprintf(fp,"POP R%d\n",j);
    }
    used = stored_reg;  //setting the number of registers back to original value

    //now save the return value
    i = get_reg();
    fprintf(fp,"MOV R%d,SP\n",i);
    fprintf(fp,"ADD R%d,%d\n",i,stored_reg + parameters + 3);
    fprintf(fp,"MOV R%d,[R%d]\n",i,i);  //return value stored in Ri

    return i;   
}

void ArgCodeGen(struct tnode* t)
{

    if(!t)
    {
        return;
    }
    
    int i = BasicCodeGen(t->left);
    fprintf(fp,"PUSH R%d\n",i);
    free_reg();

    MainCodeGen(t->right);
}

void ReturnCodeGen(struct tnode* t)
{
    int i = BasicCodeGen(t->left);
    int j = get_reg();

    fprintf(fp,"MOV R%d,BP\n",j);
    fprintf(fp,"SUB R%d,2\n",j);
    fprintf(fp,"MOV [R%d],R%d\n",j,i);

    free_reg();
    free_reg();
}

void InitializeCodeGen(struct tnode* t)
{
    int i = get_reg();
    fprintf(fp,"MOV R%d, \"Heapset\"\n", i);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"CALL 0\n");
    fprintf(fp,"POP R%d\n",i);
    fprintf(fp,"POP R%d\n",i);
    fprintf(fp,"POP R%d\n",i);
    fprintf(fp,"POP R%d\n",i);
    fprintf(fp,"POP R%d\n",i);
    free_reg();
}

int AllocCodeGen(struct tnode* t)   //return address of heap allocated or -1
{
    int i = get_reg();
    int j = get_reg();
    fprintf(fp,"MOV R%d, \"Alloc\"\n", j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"MOV R%d, 8\n", j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"CALL 0\n");
    fprintf(fp,"POP R%d\n",i);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    free_reg(); //register j gets freed

    return i;
}

void FreeCodeGen(struct tnode* t)
{
    int i = BasicCodeGen(t->left);  //register i contains value at variable's stack location
    int j = get_reg();

    fprintf(fp,"MOV R%d, \"Free\"\n", j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"CALL 0\n");
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);

    free_reg();
    free_reg();    
}

void MainCodeGen(struct tnode* t)
{
    if(t == NULL)
        return;

    if(t->type == assign_node)
    {
        AssignCodeGen(t);
    }

    else if(t->type == assign_field_node)
    {
        AssignFieldCodeGen(t);
    }

    else if(t->type == assignArray_node)
    {
    	AssignArrayCodeGen(t);
    }

    else if(t->type == read_node)
    {
        readCodeGen(t->left->varname);
    }

    else if(t->type == read_field_node)
    {
        readFieldCodeGen(t);
    }

    else if(t->type == readArray_node)
    {
        readArrayCodeGen(t);
    }

    else if(t->type == write_node)
    {
        writeCodeGen(t);
    }

    else if(t->type == if_node)
    {
        ifCodeGen(t);
    }

    else if(t->type == ifElse_node)
    {
        ifElseCodeGen(t);
    }

    else if(t->type == while_node)
    {
        WhileCodeGen(t);
    }

    else if(t->type == Dowhile_node)
    {
        DoWhileCodeGen(t);
    }

    else if(t->type == repeat_node)
    {
        RepeatCodeGen(t);
    }

    else if(t->type == break_node)
    {
        BreakCodeGen(t);
    }

    else if(t->type == continue_node)
    {
        ContinueCodeGen(t);
    }

    else if(t->type == function_node)
    {
        FunctionCodeGen(t);
    }

    else if(t->type == arg_node)
    {
        ArgCodeGen(t);
    }

    else if(t->type == return_node)
    {
        ReturnCodeGen(t);
    }

    else if(t->type == init_node)
    {
        InitializeCodeGen(t);
    }

    else if(t->type == alloc_node)
    {
        AllocCodeGen(t);
    }

    else if(t->type == free_node)
    {
        FreeCodeGen(t);
    }

    else if(t->type == connector_node)
    {
        MainCodeGen(t->left);
        MainCodeGen(t->right);
    }
}

void GenerateHeader()
{
    fprintf(fp1,"0\n");
    fprintf(fp1,"2056\n");
    fprintf(fp1,"0\n");
    fprintf(fp1,"0\n");
    fprintf(fp1,"0\n");
    fprintf(fp1,"0\n");
    fprintf(fp1,"0\n");
    fprintf(fp1,"0\n");
    fprintf(fp1,"MOV BP,%d\n",bind);
    fprintf(fp1,"MOV SP,%d\n",bind-1);
    fprintf(fp1,"ADD SP,1\n");   //for return value of main
    fprintf(fp1,"CALL MAIN\n");
    fprintf(fp1,"INT 10\n");    
}

void GenerateExit()
{
    int j = get_reg();
    fprintf(fp,"MOV R%d,\"Exit\"\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"PUSH R%d\n",j);
    fprintf(fp,"CALL 0\n");
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    fprintf(fp,"POP R%d\n",j);
    
    free_reg(); 
}

void GenerateCode(struct tnode* t)
{
    GenerateHeader();

    MainCodeGen(t);

    GenerateExit();
}





