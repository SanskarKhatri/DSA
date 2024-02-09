#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10
typedef struct treeNode
{
    int utype;
    union
    {
        char operater;
        float operand;
    }u;
    struct treeNode *left;
    struct treeNode *right;
}NODE;
static int top=-1;
void push(NODE* nn,NODE *stack[])
{
    if(top<MAX)//not full
    {
        stack[++top]=nn;
    }
}
NODE* pop(NODE **stack)
{
   if(top==-1)
    printf("STACK EMPTY");
   else
    return stack[top--];
}
NODE* construct(char exp[])
{
    NODE *nn,stack[MAX];
    int i=0;
    while(exp[i])
    {
        if(isdigit(exp[i]))//operand
        {
           nn=(NODE*)malloc(sizeof(NODE));
           nn->utype=1;
           nn->u.operand=exp[i]-'0';
           nn->left=NULL;
           nn->right=NULL;
           push(nn,&stack);
        }
        else//operator
        {
            nn=(NODE*)malloc(sizeof(NODE));
            nn->utype=2;
            nn->u.operater=exp[i];
            nn->right=pop(&stack);
            nn->left=pop(&stack);
            push(nn,&stack);
        }
        i++;
    }
return pop(&stack);
}
void inorder(NODE *bst)
{
    if(bst!=NULL)
    {
        inorder(bst->left);
        if(bst->utype==1)
            printf("%g ",bst->u.operand);
        else
            printf("%c ",bst->u.operater);
        inorder(bst->right);
    }
}
float calculate(float x,char op,float y)
{
    float res;
    switch(op)
    {
    case '+':
        res=x+y;
        break;
    case '-':
        res=x-y;
        break;
    case '*':
        res=x*y;
        break;
    case '/':
        res=x/y;
        break;
    }
    return res;
}
float evaluate(NODE *bst)
{
    if(bst->utype==1)
        return bst->u.operand;
    float x=evaluate(bst->left);
    float y=evaluate(bst->right);
    return calculate(x,bst->u.operater,y);
}
int main()
{
    NODE *bst;
    char exp[MAX]="567*+8-";
    bst=construct(exp);
    inorder(bst);
    printf("%g",evaluate(bst));
}
