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
    // nn->next=NULL;
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
    nn=create(data);
    if(isempty(*front,*rear))
    {
        *front=*rear=nn;
        (*rear)->next=*front;
    }
    else
    {
        (*rear)->next=nn;
        *rear=(*rear)->next;
        (*rear)->next=*front;
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
        (*rear)->next=*front;
        temp->next=NULL; //optional
        free(temp);
    }
}
void display(struct node* front,struct node* rear)
{
    if(!isempty(front,rear))
    {
        struct node *i;
        for(i=front;i->next!=front;i=i->next)
        {
            printf("%d\t",i->data);
        }
        printf("%d\n",i->data);
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