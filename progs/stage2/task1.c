struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r)
{
    struct tnode *tmp = (struct tnode*)malloc(sizeof(tnode));
    tmp -> val = val;
    tmp -> type = type;
    tmp -> left = l;
    tmp -> right = r; 
    
    if(type == var_node)
    {
        tmp -> varname = (char *)malloc(sizeof(c));
        strcpy(tmp -> varname,c);    
    }

    return tmp;
}

void print(struct tnode* root)
{
    if(root == NULL)
        return;
    
    print(root->left);
    switch (root->type)
    {
    case num_node:
        printf("%d ",root->val);
        break;
    
    case var_node:
        printf("%s ",root->varname);
        break;

    case plus_node:
        printf("+ ");
        break;
    
    case minus_node:
        printf("- ");
        break;
    
    case mul_node:
        printf("* ");
        break;
    
    case div_node:
        printf("/ ");
        break;
    
    case connector_node:
        printf("\n");
        break;

    case read_node:
        printf("read ");
        break;
    
    case write_node:
        printf("write ");
        break;

    case assign_node:
        printf("= ");    
        break;

    default:
        break;
    }
    print(root->right);

}



