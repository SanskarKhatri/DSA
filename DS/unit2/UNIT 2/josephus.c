#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *nn,*temp;
struct node* createnode(int data)
{
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    //nn->next=NULL;
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
   {
       *front=*rear=nn;//First node inserted
       (*rear)->next=*front;//changes //nn->next=*front
   }
   else{
        (*rear)->next=nn;
        *rear=(*rear)->next;
        (*rear)->next=*front;//changes//nn->next=*front
        }
}
int isOneElement(struct node *front,struct node *rear)
{
    return front==rear;
}
void dequeue(struct node **front,struct node **rear)
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
        (*rear)->next=*front;//change
        temp->next=NULL;
        free(temp);
    }
}
void display(struct node *front,struct node *rear)
{
    struct node *i;
    printf("\n");
    if(!(isempty(front,rear)))
       {
           for(i=front;i->next!=front;i=i->next)
                {
                  printf("%d ",i->data);
                }

           printf("%d",i->data);
       }
}
int main()
{
    int i,n,c;
    struct node *front=NULL,*rear=NULL;
    printf("\nEnter the number of people");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        enqueue(&front,&rear,i);
    }
    display(front,rear);
    printf("\n Choose a random number less than %d",n);
    scanf("%d",&c);
    while((front->next)!=front)
    {
        struct node *t1=front;
        for(i=1;i<c;i++)
        {
            front=front->next;
            rear=rear->next;
        }
      dequeue(&front,&rear);
      display(front,rear);
    }
    return 0;
}
