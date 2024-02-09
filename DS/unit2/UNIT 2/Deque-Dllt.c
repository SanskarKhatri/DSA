#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}NODE;

int isempty(NODE *front,NODE *rear)
{
    return front==rear && front==NULL;
}
int isOneElement(NODE *front,NODE *rear)
{
    return front==rear && front!=NULL;
}
NODE* createnode(int data)
{
    NODE *nn=(NODE*)malloc (sizeof(NODE));
    nn->data=data;
    nn->next=NULL;
    nn->prev=NULL;
    return nn;
}
void InsertFront(NODE **front,NODE **rear,int data)
{
    NODE *nn;
    nn=createnode(data);
    if(isempty(*front,*rear))
    {
       *front=*rear=nn;
    }
    else
    {
        nn->next=*front;
        (*front)->prev=nn;
        *front=nn;
    }
}
void InsertRear(NODE **front,NODE **rear,int data)
{
    NODE *nn;
    nn=createnode(data);
    if(isempty(*front,*rear))
    {
       *front=*rear=nn;
    }
    else
    {
        nn->prev=*rear;
        (*rear)->next=nn;
        *rear=nn;
    }
}
void deleteRear(NODE **front,NODE **rear)
{
    if(isempty(*front,*rear))
    {
        printf("DEQUE is empty");
    }
    else if(isOneElement(*front,*rear))
    {
        *rear=*front=NULL;
    }
    else{
        NODE *t=*rear;
        *rear=(*rear)->prev;
        (*rear)->next=NULL;
        t->prev=NULL;
        free(t);
    }
}
void deleteFront(NODE **front,NODE **rear)
{
    if(isempty(*front,*rear))
    {
        printf("DEQUE is empty");
    }
    else if(isOneElement(*front,*rear))
    {
        *rear=*front=NULL;
    }
    else{
        NODE *t=*front;
        *front=(*front)->next;
        (*front)->prev=NULL;
        t->next=NULL;
        free(t);
    }
}
void display(NODE *front,NODE *rear)
{
    printf("\n");
    if(!isempty(front,rear))
    {
        for(NODE *i=front;i!=NULL;i=i->next)
        {
            printf("%d ",i->data);
        }
    }
}
int main()
{
    NODE *front=NULL,*rear=NULL;
    InsertRear(&front,&rear,5); //First element
    display(front,rear);
    InsertFront(&front,&rear,10); //Front end insertion
    display(front,rear);
    InsertRear(&front,&rear,15);//Rear end insertion
    display(front,rear);
    deleteRear(&front,&rear); //Rear end deletion
    display(front,rear);
    deleteFront(&front,&rear); //Front end deletion
    display(front,rear);
    deleteFront(&front,&rear);//One element deletion
    display(front,rear);
}
