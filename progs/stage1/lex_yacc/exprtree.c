struct tnode* makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

int evaluate(struct tnode *t){
    if(t->op == NULL)
    {
        return t->val;
    }
    else{
        switch(*(t->op)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
}
FILE *fp;
int used = -1;
int get_reg()
{
    used++;
    return used;
}

void free_reg()
{
    used--;
}

int code_gen(struct tnode* t)
{
    if(t->op == NULL)
    {
        int i = get_reg();
        fprintf(fp,"MOV R%d,%d\n",i,t->val);

        return i;
    }

    int p = code_gen(t->left);
    int q = code_gen(t->right);

    switch(*t->op)
    {
        case '+':
            fprintf(fp,"ADD R%d,R%d\n",p,q);
            break;
        case '-':
            fprintf(fp,"SUB R%d,R%d\n",p,q);
            break;
        case '*':
            fprintf(fp,"MUL R%d,R%d\n",p,q);
            break;
        case '/':
            fprintf(fp,"DIV R%d,R%d\n",p,q);
            break;
    }
    
    free_reg();

    return p;
}

void prefix(struct tnode* t)
{
    if(!t)
        return;

    if(t->op)
    {
        printf("%c ",*t->op);
    }
    else
    {
        printf("%d ",t->val);
    }

    prefix(t->left);
    prefix(t->right);
}

void postfix(struct tnode* t)
{
    if(!t)
        return;
    
    postfix(t->left);
    postfix(t->right);
        
    if(t->op)
    {
        printf("%c ",*t->op);
    }
    else
    {
        printf("%d ",t->val);
    }

}