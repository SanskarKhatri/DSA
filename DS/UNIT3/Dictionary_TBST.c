#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char word[25];
    char meaning[125];
    int rthread;
    int lthread;
    struct node *left;
    struct node *right;
}NODE;
NODE* createNode(char *word,char *meaning)
{
    NODE *nn;
    nn=(NODE*)malloc(sizeof(NODE));
    strcpy(nn->word,word);
    strcpy(nn->meaning,meaning);
    return nn;
}
NODE* insertNode(NODE *root,char *word,char *meaning)
{

    int res;
    NODE *t=root,*parent=NULL,*nn;
    nn=createNode(word,meaning);
    if(root==NULL)
        {
            root=nn;
            root->rthread=1;
            root->lthread=1;
            root->left=NULL;
            root->right=NULL;
            return root;
        }
    while(t!=NULL)
        {
        parent=t;
        res=strcasecmp(word,t->word);
        if(res<0)//left tree
            {
                if(t->lthread==0)
                    t=t->left;
                else
                    break;
            }
        else if(res>0)
            {
                if(t->rthread==0)
                    t=t->right;
                else
                    break;
            }
        else
        {
            printf("Duplicate data");
            return root;
        }
        }
    res=strcasecmp(word,parent->word);
    if(res<0)//insert as left child
    {
        nn->lthread=1;
        nn->rthread=1;
        nn->right=parent;
        nn->left=parent->left;
        parent->lthread=0;
        parent->left=nn;
    }
    else if(res>0)
    {
        nn->lthread=1;
        nn->rthread=1;
        nn->right=parent->right;
        nn->left=parent;
        parent->rthread=0;
        parent->right=nn;
    }
return root;
}
NODE* in_succ(NODE *ptr)
{
        if(ptr->rthread==1)
                return ptr->right;
        else
        {
                ptr=ptr->right;
                while(ptr->lthread==0)
                    ptr=ptr->left;
                return ptr;
        }
}
void inorder( NODE *root)
{
        NODE *ptr;
        if(root == NULL )
        {
        printf("Tree is empty");
        return;
        }
        ptr=root;
        while(ptr->lthread==0)
              ptr=ptr->left;
        while( ptr!=NULL )
        {
        printf("\n%s - %s",ptr->word,ptr->meaning);
        ptr=in_succ(ptr);
        }
}
char* search(NODE *t,char *word)
{
    int res=strcasecmp(word,t->word);
    if(res==0)
        return t->meaning;
    else if(res<0 && t->lthread==0)
        return search(t->left,word);
    else if(res>0 && t->rthread==0)
        return search(t->right,word);
    else
        return "Not found";
}
int main()
{
    NODE *tbst=NULL;
    char w[20],m[100];
    int ch;
    do{
    printf("\nEnter the word: ");
    scanf("%s",w);
    printf("\nEnter the meaning: ");
    scanf("%s",m);
    tbst=insertNode(tbst,w,m);
    printf("\nTo Continue Press 1: ");
    scanf("%d",&ch);
    }while(ch);
    printf("\n");
    inorder(tbst);
    printf("\nEnter the word: ");
    scanf("%s",w);
    printf("\n%s - %s",w,search(tbst,w));
}

