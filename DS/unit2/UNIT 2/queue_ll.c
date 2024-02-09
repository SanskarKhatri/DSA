#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL,*nn,*temp;
struct node* createnode(int data)
{
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    return nn;
}
int isempty(struct node *front,struct node *rear)
{
    return (front==NULL && rear==NULL);
}

void enqueue(struct node **front,struct node **rear,int data)
{
   nn=createnode(data);
   if(isempty(*front,*rear))
        *front=*rear=nn;
   else{
        (*rear)->next=nn;
        *rear=(*rear)->next;
        }
}
int isOneElement(struct node *front,struct node *rear)
{
    return front==rear;
}
int dequeue(struct node **front,struct node **rear)
{
    if(isempty(*front,*rear))
    {
        printf("Queue is empty");
    }
    else if(isOneElement(*front,*rear)){
        *front=*rear=NULL;
    }
    else
    {
        temp=*front;
        *front=(*front)->next;
        int data=temp->data;
        temp->next=NULL;
        free(temp);
        return data;
    }
}
void display(struct node *front)
{
    struct node *i;
    printf("\n");
    if(!(isempty(front,rear)))
       {
           for(i=front;i!=NULL;i=i->next)
                printf("%d ",i->data);
       }
}
int main()
{
    int i;
    for(i=0;i<=5;i++)
    {
        enqueue(&front,&rear,i);
        display(front);
    }

    for(int i=0;i<=6;i++)
        {
            dequeue(&front,&rear);
            display(front);
        }
    return 0;
}
