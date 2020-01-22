struct tnode* createTree(int val, int type, int ttype, char* c, struct tnode *l, struct tnode *r, struct tnode* mid)
{
    struct tnode *tmp = (struct tnode*)malloc(sizeof(tnode));
    tmp -> val = val;
    tmp -> type = type;
    tmp -> ttype = ttype;
    tmp -> left = l;
    tmp -> right = r; 
    tmp -> mid = mid;

    if(type == var_node)
    {
        tmp -> varname = (char *)malloc(sizeof(c));
        strcpy(tmp -> varname,c);    
    }

    return tmp;
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

void CheckType(struct tnode* t1,struct tnode* t2)
{
    if(!(t1->ttype == int_type && t2->ttype == int_type))
    {
        printf("Type mismatch of operands\n");
        exit(1);
    }
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

int label = -1;
int get_label()
{
    label++;
    return label;
}

int BasicCodeGen(struct tnode* t)
{
    if(t->type == var_node)
    {
        int i = get_reg();
        int addr = 4096 + t->varname[0] - 'a';

        fprintf(fp,"MOV R%d,[%d]\n",i,addr);

        return i;
    }

    else if(t->type == num_node)
    {
        int i = get_reg();
        fprintf(fp,"MOV R%d,%d\n",i,t->val);

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
    }
    
    free_reg();

    return p;
}

void readCodeGen(char c)
{
    int i = get_reg();  //to push values in the stack
    fprintf(fp,"MOV R%d,\"Read\"\n",i);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"MOV R%d,%d\n",i,-1);
    fprintf(fp,"PUSH R%d\n",i);
    fprintf(fp,"MOV R%d,%d\n",i,4096+c-'a');
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


void MainCodeGen(struct tnode* t)
{
    if(t == NULL)
        return;

    if(t->type == assign_node)
    {
        int i = BasicCodeGen(t->right); //result is stored in Ri
        int dest_addr = 4096 + t->left->varname[0] - 'a';

        fprintf(fp,"MOV [%d],R%d\n",dest_addr,i);

        free_reg(); //Ri is no longer needed
    }

    else if(t->type == read_node)
    {
        readCodeGen(t->left->varname[0]);
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
    fprintf(fp,"BRKP\n");
    fprintf(fp,"MOV SP,4121\n");
    
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




