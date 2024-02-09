#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;
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
    else if(data<root->data)
        root->left=insertNode(root->left,data);
    else
        root->right=insertNode(root->right,data);
    return root;
}
void preorder(NODE *root)
{
    if(isempty(root))
        printf("Tree is empty");
    else{
        printf("%d ",root->data);
        if(root->left!=NULL)//Left subtree exist
            preorder(root->left);
        if(root->right!=NULL)
            preorder(root->right);
    }
}
void postorder(NODE *root)
{
    if(isempty(root))
        printf("Tree is empty");
    else{
        if(root->left!=NULL)//Left subtree exist
            postorder(root->left);
        if(root->right!=NULL)
            postorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(NODE *root)
{
    if(isempty(root))
        printf("Tree is empty");
    else{
        if(root->left!=NULL)//Left subtree exist
            inorder(root->left);
        printf("%d ",root->data);
        if(root->right!=NULL)
            inorder(root->right);
    }
}
void searchElement(NODE **t,int data,NODE **parent)
{
    while((*t)->data!=data && (*t)!=NULL)
    {
        *parent=*t;
        if(data<(*t)->data)
            *t=(*t)->left;
        else
            *t=(*t)->right;
    }
}
NODE* inordersuccessor(NODE *t)
{
    NODE *s;
    s=t->right;
    while(s->left!=NULL)
        s=s->left;
    return s;
}
NODE* deletenode(NODE* root,int data)
{
    NODE *t=root,*parent=NULL;
    if(data!=t->data)
        searchElement(&t,data,&parent);
    if(t==NULL)
    {
        printf("Element not found");
        return NULL;
    }
    //case 1: Leaf Node
    if(t->left==NULL && t->right==NULL)
    {
        if(parent==NULL)//root node
        {
            root=NULL;
        }
        else if(parent->left==t)//left child
        {
           parent->left=NULL;
        }
        else{
           parent->right=NULL; //right child
        }
    free(t);
    }
    //case 2 : One child
    else if(t->left==NULL || t->right==NULL)
    {
        if(parent==NULL)//root
        {
            if(t->left!=NULL)
                root=root->left;
            else
                root=root->right;
        }
        else if(parent->left==t)//t is left child
        {
            if(t->left!=NULL)//t has left child
                parent->left=t->left;
            else//t has right child
                parent->left=t->right;
        }
        else //t is right child
        {
            if(t->left!=NULL)//t has left child
                parent->right=t->left;
            else//t has right child
                parent->right=t->right;
        }
    free(t);
    }
    // case 3: Node with two children
    else{
        NODE *s;
        int val;
        s=inordersuccessor(t);
        val=s->data;
        root=deletenode(root,s->data);
        t->data=val;
    }
return root;
}
int main()
{
    int n,d,ch;
    NODE *root=NULL;
    printf("\nEnter the no of nodes");
    scanf("%d",&n);
    printf("\nEnter the data:");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d);
        root=insertNode(root,d);
    }
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    do{
    printf("\nEnter the data to be deleted");
    scanf("%d",&d);
    root=deletenode(root,d);
    printf("\n");
    inorder(root);
    printf("\nEnter your choice");
    scanf("%d",&ch);
    }while(ch);
}
