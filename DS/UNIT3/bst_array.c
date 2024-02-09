#include<stdio.h>
#define SIZE 10
typedef struct node{
 int data;
 int flag;
}NODE;
void insert(NODE *bst,int data,int index)
{
    if(bst[index].flag==0 && index<SIZE)//exit criteria
    {
       bst[index].data=data;
       bst[index].flag=1;
    }
    else if(data<=bst[index].data && index<SIZE)
    {
    index=2*index+1;
    insert(bst,data,index);
    }
    else if(data>bst[index].data   && index<SIZE)
    {
      index=2*index+2;
      insert(bst,data,index);
    }
    else
        printf("Insertion not possible");
}
void inorder(NODE *bst,int i)
{
    if(bst[i].flag && i<SIZE)
    {
        inorder(bst,2*i+1);
        printf("%d ",bst[i].data);
        inorder(bst,2*i+2);
    }
}
int main()
{
    int d,ch=0;
    NODE bst[SIZE]={};
    do{
    printf("Enter the data:");
    scanf("%d",&d);
    insert(bst,d,0);
    printf("To Continue press 1");
    scanf("%d",&ch);
    }while(ch);
    inorder(bst,0);
    return 0;
}
