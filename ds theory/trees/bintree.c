#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;
NODE* createnode(int data){
    NODE *nn=(NODE*)malloc(sizeof(NODE));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
int isempty(NODE *t){
    return (t==NULL);
}
NODE* insertNode(NODE *root, int data){
    if(isempty(root)){
        root=createnode(data);
    } else if(data<root->data){
        root->left=insertNode(root->left,data);
    } else {
        root->right=insertNode(root->right,data);
    }
    return root;
}
void preorder(NODE *root){
    if(isempty(root)){
        printf("Tree is empty!\n");
    } else {
        printf("%d\t",root->data);
        if(root->left!=NULL){
            preorder(root->left);
        } 
        if(root->right!=NULL){
            preorder(root->right);
        }
    }
}
void postorder(NODE *root){
    if(isempty(root)){
        printf("Tree is empty!\n");
    } else {
        if(root->left!=NULL){
            postorder(root->left);
        } 
        if(root->right!=NULL){
            postorder(root->right);
        }
        printf("%d\t",root->data);
    }
}
void inorder(NODE *root){
    if(isempty(root)){
        printf("Tree is empty!\n");
    } else {
        if(root->left!=NULL){
            inorder(root->left);
        } 
        printf("%d\t",root->data);
        if(root->right!=NULL){
            inorder(root->right);
        }
    }
}
searchElement(NODE **t,int data,NODE **parent){
    while((*t)->data!=data && t!=NULL){
        *parent=*t;
        if(data<(*t)->data)
            (*t)=(*t)->data;
        else 
            (*t)=(*t)->data;
    }
}
NODE* inordersuccessor(NODE *t){
    NODE *s;
    s=s->right;
    while(s->left!=NULL){
        s=s->left;
    }
    return s;
}
NODE* deletenode(NODE* root, int data){
    NODE *t=root, *parent=NULL;
    if(data!=t->data){
        searchElement(&t,data,&parent);
    } 
    if(t==NULL){
        printf("Element not found");
    }
    //case 1: Leaf node
    if(t->left==NULL && t->right==NULL){
        if(parent==root){//root node
            root=NULL;
        }
        if(parent->left==t){//left child
            parent->left=NULL;   
        } else {
            parent->right=NULL;
        }
        free(t);
    }
    //case 2: one child
    else if(t->left==NULL || t->right==NULL){
        if(parent==NULL){//root node
            if(t->left!=NULL){
                root=root->left;
            } else {
                root=root->right;
            }
        } else if(parent->left==t){
            if(t->left!=NULL){
                parent->left=t->left;
            } else {
                parent->left=t->right;
            }
        } else {
            if(t->left!=NULL){
                parent->right=t->left;
            } else {
                parent->right=t->right;
            }
        }
        free(t);
    }
    //case 3: two children
    else {
        NODE *s;
        int val;
        s=inordersuccessor(t);
        val=s->data;
        root=deletenode(root,s->data);
        t->data=val;     
    }
}
int main(){
    NODE *root=NULL;
    int n,i,d;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&d);
        root=insertNode(root,d);
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("Enter the data you want to delete:\n");
    scanf("%d",&n);
    root=delete(root,n);
}