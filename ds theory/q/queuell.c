#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL,*nn,*temp;
struct node *create(int data)
{
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    return nn;
}
int isempty(struct node *front,struct node *rear)
{
    return(front==NULL && rear==NULL);
}
int isoneElement(struct node *front,struct node *rear)
{
    return(front==rear && front!=NULL);
}
void enqueue(struct node **front,struct node **rear,int data)
{
    if(isempty(*front,*rear))
    {
        nn=create(data);
        *front=*rear=nn;
    }
    else
    {
        nn=create(data);
        (*rear)->next=nn;
        *rear=(*rear)->next;
    } 
}
void dequeue(struct node **front,struct node **rear)
{
    if(isempty(*front,*rear))
    {
        printf("\nqueue is empty\n");
    }
    else if(isoneElement(*front,*rear))
    {
        *front=*rear=NULL;
    }
    else 
    {
        temp=*front;
        *front=(*front)->next;
        temp->next=NULL; //optional
        free(temp);
    }
}
void display(struct node* front,struct node* rear)
{
    if(!isempty(front,rear))
    {
        for(struct node *i=front;i!=NULL;i=i->next)
        {
            printf("%d\t",i->data);
        }
        printf("\n");
    }
}
int main()
{
    for(int i=1;i<=5;i++)
    {
        enqueue(&front,&rear,i);
        display(front,rear);
    }
     for(int i=1;i<=6;i++)
    {
        dequeue(&front,&rear);
        display(front,rear);
    }
}