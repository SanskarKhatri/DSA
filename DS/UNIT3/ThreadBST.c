#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int rthread;
    int lthread;
    struct node *left;
    struct node *right;
}NODE;

NODE* createNode(int data)
{
    NODE *nn=(NODE*)malloc(sizeof(NODE));
    nn->data=data;
    return nn;
}

NODE* insertNode(NODE *root,int data)
{
    NODE *t=root,*parent,*nn;
    nn=createNode(data);
    if(root==NULL)//tree is empty
    {
        root=nn;
        root->lthread=0;
        root->rthread=0;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    while(t!=NULL)
    {
        parent=t;
        if(data<t->data)
        {
            if(t->lthread==0)
                t=t->left;
            else
                break;
        }
        else if(data>t->data)
        {
            if(t->lthread==0)
                t=t->right;
            else
                break;
        }
        else
        {
            printf("Duplicate key");
            return root;
        }
    }
    if(data<parent->data)
    {
        nn->rthread=1;
        nn->lthread=1;
        nn->left=parent->left;//Inorder Predesseccor
        nn->right=parent;//Inorder Successor
        parent->left=nn;
        parent->lthread=0;
    }
    else
    {
        nn->rthread=1;
        nn->lthread=1;
        nn->left=parent;//Inorder Predesseccor
        nn->right=parent->right;//Inorder Successor
        parent->right=nn;
        parent->rthread=0;
    }
    return root;
}
NODE* inorderSuccessor(NODE *t)
{

}
void inorder(NODE* root)
{
    NODE *t=root;
    if(root==NULL)
        printf("Empty Tree");
    else
    {
        while(t->lthread==0)//left link has a child
            t=t->left;
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t=inorderSuccessor(t);
        }
    }
}
