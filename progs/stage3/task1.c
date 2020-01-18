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

    switch(t->type)
    {
        case lt_node:
            p = BasicCodeGen(t->left);
            q = BasicCodeGen(t->right);

            fprintf(fp, "LT %d,%d\n",p,q);
            free_reg();
            
            break;

        case gt_node:
            break;
        
        case eq_node:
            break;
        
        case neq_node:
            break;
        
        case gte_node:
            break;
        
        case lte_node:
            break;
    }
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




