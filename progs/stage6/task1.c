struct tnode* createTree(int val, char* str_val, int type, struct Typetable* ttype, char* c, struct tnode *l, struct tnode *r, struct tnode* mid)
{
    struct tnode *tmp = (struct tnode*)malloc(sizeof(tnode));
    tmp -> val = val;
    tmp -> str_val = str_val;
    tmp -> type = type;
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
        struct Gsymbol* curr3 = Lookup2(c);

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
        exit(1);
    }
}

void MatchType(struct tnode* t,int type)
{
    if(t->type != type)
    {
        printf("Error:Type mismatch\n");
        exit(1);
    }
}

void CheckIfArray(char* varname)
{
	struct Gsymbol* idx = Lookup2(varname);

	if(idx == NULL)
	{
		printf("Error : %s Variable not found\n",varname);
		exit(1);
	} 

	if(idx->_type == 0)
	{
		printf("Error : %s is not array type\n",varname);
		exit(1);
	}
}

void AssignCheckType(struct tnode* t1,struct tnode* t2)
{
	if(t1->ttype != t2->ttype && (t1->ttype!=TLookup("dummy") && t2->ttype!=TLookup("dummy")))
    {
        printf("hiError:Type mismatch of operands\n");
        exit(1);
    }
}

void CheckBoolType(struct tnode* t)
{
    if(t->ttype != TLookup("bool"))
    {
        printf("Expression is not bool type\n");
        exit(1);   
    }
}

void CheckIntType(struct tnode* t)
{
    if(t->ttype != TLookup("int"))
    {
        printf("Expression is not int type\n");
        exit(1);
    }
}

struct Gsymbol* Lookup(char* variable_name)
{
	struct Gsymbol* curr = start;

	while(curr!=NULL)
	{
		if(strcmp(curr->name,variable_name) == 0)
		{
			printf("Error : %s Variable redeclaration\n",curr->name);
			exit(1);
			return curr;
		}
		curr = curr->next;
	}

	return NULL;
}

struct Gsymbol* Lookup2(char* variable_name)
{
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
   struct Gsymbol* curr3 = Lookup2(varname); 

	if(!curr1 && !curr2 && !curr3)
   {	
    	printf("Error : %s Variable/function not declared",varname);
    	exit(1);
   }                                
}

void Install(char* variable_name, struct Typetable* type, int _type, int size)
{
	struct Gsymbol* tmp = Lookup(variable_name);

	struct Gsymbol* new_entry = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	new_entry -> name = variable_name;
	new_entry -> type = type;
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
    struct Paramstruct* curr = head;

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

void InsertParam(char* name,struct Typetable* type)
{

    CheckDuplicateParam(name);

	struct Paramstruct* new_node = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
	new_node -> name = name;
	new_node -> type = type;
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
	struct Gsymbol* curr = Lookup2(name);
	curr -> ParamList = head;
}

//checks if same local variable name is already present
void CheckDuplicateLocalSymbol(char* name)
{
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
	struct Gsymbol* idx = Lookup2(name);

	idx -> LocalSymbols = head2;

}

void PrintSymbolTable()
{
	struct Gsymbol* curr = start;
	printf("Name            Type      _Type     Size     Binding\n");
	while(curr!=NULL)
	{
		printf("%s               %s         %d        %d         %d\n",curr->name,curr->type->name,curr->_type,curr->size,curr->binding);
		curr = curr->next;
	}
}

void PrintLST(char* name)
{
	struct Gsymbol* idx = Lookup2(name);

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
	// struct Gsymbol* idx = Lookup2(name);

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
	struct Gsymbol* idx = Lookup2(name);

	if(idx == NULL)
	{
		printf("Function %s not declared\n",name);
		exit(1);
	}

    if(idx->type != t)
	{
		printf("Return type of declared & defined function %s does not match",name);
		exit(1);
	}
}

void CheckReturnVal(struct tnode* t,struct Typetable* type)
{
    if(t->ttype != type)
    {
        printf("Value returned does not match with return type\n");
        exit(1);
    }
}

void CheckIfFunction(char* name)
{
	struct Gsymbol* idx = Lookup2(name);

	if(idx -> _type != 2)
	{
		printf("%s is not a function\n",name);
		exit(1);
	}
}

void CheckParamList(char *name) //checks if parameters in declaration and definition are consistent
{
	struct Gsymbol* idx = Lookup2(name);

	struct Paramstruct* curr = idx -> ParamList;
	struct Paramstruct* curr2 = head;
	while(curr && curr2)
	{
		if(curr -> type != curr2 ->type)
		{
			printf("%s function declaration & definition param do not match\n",name);
			exit(1);
		}

		curr -> name = curr2 -> name;

		curr = curr -> next;
		curr2 = curr2 -> next;
	}

	if(curr != curr2)
	{
		printf("%s function declaration & definition param do not match\n",name);
		exit(1);
	}

}


void CheckInformalParamList(struct tnode* t)  //checks if informalparam matches with formal param during a function call
{
	struct Paramstruct* curr = Lookup2(t->left->varname)->ParamList;
	struct tnode* curr2;

    int cnt_formal = 0;
    while(curr)
    {
        cnt_formal++;
        curr = curr->next;
    }
    curr = Lookup2(t->left->varname)->ParamList;

    int cnt_informal = 0;
    curr2 = t->right; 
    while(curr2)
    {
        cnt_informal++;
        curr2 = curr2 -> right;
    }

    if(cnt_informal != cnt_formal)
    {
        printf("%s Incorrect no. of arguments",t->left->varname);
    }

    cnt_informal--;
    while(curr)
    {
        curr2 = t->right;

        for(int i=0;i<cnt_informal;i++)
        {
            curr2 = curr2 -> right;
        }

        if(curr->type != curr2->left->ttype)
        {
            printf("%s function declaration & definition param do not match\n",t->left->varname);
            exit(1);    
        }
        cnt_informal--;
        curr = curr -> next;
    }
	
}

struct Fieldlist* FieldNameLookup(char* name)
{
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
        exit(1);
    }

    tmp = FLookup(type,name);
    if(tmp)
    {
        printf("Error : Same named field already present\n");
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
    struct Typetable* tmp = TLookup(name);

    if(tmp)
    {
        printf("Error : %s type already exists",name);
        exit(1);
    }

    tmp = (struct Typetable*)malloc(sizeof(struct Typetable));
    tmp -> name = name;
    tmp -> fields = fields;
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

    if(cnt>8)
    {
        printf("Error : %s type has more than 8 fields\n",name);
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

void ActRecordSetup(char* name)
{
	struct Gsymbol* idx = Lookup2(name);
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
	struct Gsymbol* idx = Lookup2(name);
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
        struct Gsymbol* curr3 = Lookup2(t->varname);

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
        	printf("Error : %s Variable not declared\n",t->varname);
        	exit(1);
        }
        return i;
    }

    else if(t->type == field_node)
    {
        int i = get_reg();

        struct Lsymbol* curr1 = LocalLookup(t->left->varname);
        struct Paramstruct* curr2 = ParamLookup(t->left->varname);
        struct Gsymbol* curr3 = Lookup2(t->left->varname);

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
        	printf("Error : %s Variable not declared\n",t->varname);
        	exit(1);
        }
        
        //now register i contains the value of the variable at a stack location which is the heap address
        //now we need to find the final value using attributes of the field node
        struct tnode* curr = t;
        struct Typetable* curr_type = t -> left -> ttype; 
        while(curr)
        {
            struct Fieldlist* field = FLookup(curr_type,curr->right->varname);
            if(!field)
            {
                printf("Error : %s field does not belong to %s\n",t->right->varname,curr_type->name);
                exit(1);
            }

            fprintf(fp,"ADD R%d,%d\n",i,field->fieldIndex);
            fprintf(fp,"MOV R%d,[R%d]\n",i,i);

            curr_type = field -> type;
            curr = curr -> mid;
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
    	
    	struct Gsymbol* idx = Lookup2(t->left->varname);
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
    struct Gsymbol* idx = Lookup2(t->left->varname);

    if(idx == NULL)
    {
       	printf("Error : %s Variable not declared",t->left->varname);
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
    struct Gsymbol* curr3 = Lookup2(c);

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
        printf("Error : %s Variable not declared\n",c);
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
    struct Gsymbol* curr3 = Lookup2(t->left->left->varname);

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
        printf("Error : %s Variable not declared\n",t->varname);
        exit(1);
    }
    
    //now register i contains the value of the variable at a stack location which is the heap address

    struct tnode* curr = t -> left;
    struct Typetable* curr_type = t -> left -> left -> ttype; 
    while(curr -> mid)
    {
        struct Fieldlist* field = FLookup(curr_type,curr->right->varname);
        if(!field)
        {
            printf("Error : %s field does not belong to %s\n",t->right->varname,curr_type->name);
            exit(1);
        }

        fprintf(fp,"ADD R%d,%d\n",i,field->fieldIndex);
        fprintf(fp,"MOV R%d,[R%d]\n",i,i);

        curr_type = field -> type;
        curr = curr -> mid;
    }

    struct Fieldlist* tmp_field = FLookup(curr_type,curr->right->varname);
    if(!tmp_field)
    {
        printf("Error : %s field does not belong to %s\n",t->right->varname,curr_type->name);
        exit(1);
    }

    fprintf(fp,"ADD R%d,%d\n",i,tmp_field->fieldIndex); //register i contains the address where the value is to be stored

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
	struct Gsymbol* idx = Lookup2(t->left->varname);
	if(idx == NULL)
	{
		printf("Variable not declared\n");
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
    struct Gsymbol* curr3 = Lookup2(t->left->varname);

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
        printf("Error : %s Variable not declared\n",t->varname);
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
    struct Gsymbol* curr3 = Lookup2(t->left->left->varname);

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
        printf("Error : %s Variable not declared\n",t->varname);
        exit(1);
    }
    
    //now register i contains the value of the variable at a stack location which is the heap address

    struct tnode* curr = t -> left;
    struct Typetable* curr_type = t -> left -> left -> ttype; 
    while(curr -> mid)
    {
        struct Fieldlist* field = FLookup(curr_type,curr->right->varname);
        if(!field)
        {
            printf("Error : %s field does not belong to %s\n",t->right->varname,curr_type->name);
            exit(1);
        }

        fprintf(fp,"ADD R%d,%d\n",i,field->fieldIndex);
        fprintf(fp,"MOV R%d,[R%d]\n",i,i);

        curr_type = field -> type;
        curr = curr -> mid;
    }

    struct Fieldlist* tmp_field = FLookup(curr_type,curr->right->varname);
    if(!tmp_field)
    {
        printf("Error : %s field does not belong to %s\n",t->right->varname,curr_type->name);
        exit(1);
    }

    fprintf(fp,"ADD R%d,%d\n",i,tmp_field->fieldIndex); //register i contains the address where the value is to be stored

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

    int label = Lookup2(t->left->varname)->binding;  //label of c

    fprintf(fp,"ADD SP,1\n"); //for return value
    fprintf(fp,"CALL F%d\n",label);
    fprintf(fp,"SUB SP,1\n");

    //now pop out the arguments
    struct Paramstruct* curr = Lookup2(t->left->varname)->ParamList;
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
    fprintf(fp,"0\n");
    fprintf(fp,"2056\n");
    fprintf(fp,"0\n");
    fprintf(fp,"0\n");
    fprintf(fp,"0\n");
    fprintf(fp,"0\n");
    fprintf(fp,"0\n");
    fprintf(fp,"0\n");
    fprintf(fp,"MOV BP,%d\n",bind);
    fprintf(fp,"MOV SP,%d\n",bind-1);
    fprintf(fp,"ADD SP,1\n");   //for return value of main
    fprintf(fp,"CALL MAIN\n");
    fprintf(fp,"INT 10\n");    
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


void printTree(struct tnode* t)
{
	if(t==NULL)
		return;

	printf("left ");printTree(t->left);
	printf("Mid :Type : %d\n",t->type);
	printf("right ");printTree(t->right);
}




