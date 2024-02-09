#include<stdio.h>
#include<conio.h>
#define MAX 10
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;
typedef struct stack
{
    NODE *stack[MAX];
    int top;
}STACK;
void push(NODE *t,STACK *s)
{
    s->stack[++(s->top)]=t;
}
NODE* pop(STACK *s)
{
    return s->stack[(s->top)--];
}
NODE* createnode(int data)
{
    NODE *nn=(NODE*)malloc(sizeof(NODE));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
int isempty(NODE *t)
{
    return (t==NULL);
}

NODE* insertNode(NODE *root,int data)
{
    if(isempty(root))
        root=createnode(data);
    else if(data<=root->data)
        root->left=insertNode(root->left,data);
    else
        root->right=insertNode(root->right,data);
    return root;
}
void inorder(NODE *t)
{
    if(isempty(t))
        printf("Tree is empty");
    else{
    STACK *s;
    s=(STACK*)malloc(sizeof(STACK));
    NODE *temp;
    s->top=-1;
    do  {
        while(t!=NULL)
            {
            push(t,s);
            t=t->left;
            }
        temp=pop(s);
        printf("%d ",temp->data);
        t=temp->right;
        }while(t!=NULL || s->top!=-1);
    }
}
void preorder(NODE *t)
{
    if(isempty(t))
        printf("Tree ie empty");
    else
    {
        NODE *temp;
        STACK *s;
        s=(STACK*)malloc(sizeof(STACK));
        s->top=-1;
        push(t,s);
        while(s->top!=-1)
        {
            temp=pop(s);
            printf("%d ",temp->data);
            if(temp->right!=NULL)
                push(temp->right,s);
            if(temp->left!=NULL)
                push(temp->left,s);
        }
    }
}
void postorder(NODE *t)
{
    NODE *temp;
    if(isempty(t))
        printf("Tree ie empty");
    else{
        STACK *s1,*s2;
        s1=(STACK*)malloc(sizeof(STACK));
        s2=(STACK*)malloc(sizeof(STACK));
        s1->top=-1;
        s2->top=-1;
        push(t,s1);
        while(s1->top!=-1)
        {
            temp=pop(s1);
            push(temp,s2);
            if(temp->left!=NULL)
                push(temp->left,s1);
            if(temp->right!=NULL)
                push(temp->right,s1);
        }
        while(s2->top!=-1)
        {
            temp=pop(s2);
            printf("%d ",temp->data);
        }
    }
}
int main()
{
    int n,d,ch;
    NODE *root=NULL;
    printf("\nEnter the no of nodes");
    scanf("%d",&n);
    printf("\nEnter the data");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d);
        root=insertNode(root,d);
    }
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);


}

