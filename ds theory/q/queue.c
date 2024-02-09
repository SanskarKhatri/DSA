#include<stdio.h>
#define SIZE 10
int queue[SIZE];
void init(int *front,int *rear)
{
    *front=*rear=-1;
}
int isempty(int front,int rear)
{
    return(front==-1 && rear==-1);
}
int isfull(int front,int rear)
{
    return (front==0 && rear==SIZE-1)||(rear==front-1);
}
int isoneElement(int front,int rear)
{
    return(front==rear && front!=-1);
}
void enqueue(int *front,int *rear,int data)
{
    if(isfull(*front,*rear))
        printf("Queue is full");
    else if(isempty(*front,*rear))
    {
        (*front)++;
        (*rear)++;
        queue[*rear]=data;
    }
    else if(*rear==SIZE-1)
    {
        *rear=0;
        queue[*rear]=data;
    }
    else
    {
        (*rear)++;
        queue[*rear]=data;
    }
}
void dequeue(int *front,int *rear)
{
    if(isempty(*front,*rear))
    {
        printf("Queue is empty");
    }
    else if(isoneElement(*front,*rear))
    {
        *front=*rear=-1;
    }
    else if(*front==SIZE-1)
        *front=0;
    else
    {
        (*front)++;
    }
}
void display(int front,int rear)
{
    if(!isempty(front,rear))
    {
        if(front<rear)
        {
            for(int i=front;i<=rear;i++)
                printf("%d\t",queue[i]);
        }
        else 
        {
            for(int i=front;i<=SIZE-1;i++)
                printf("%d\t",queue[i]);
            for(int i=0;i<=rear;i++)
                printf("%d\t",queue[i]);
        }
    }
}
int main()
{
    int front,rear,i;
    init(&front,&rear);
    printf("\n%d %d\n",front,rear);
    for(i=0;i<=SIZE-1;i++)
        enqueue(&front,&rear,i);
    display(front,rear);
    printf("\n");
    for(int i=0;i<3;i++)
        dequeue(&front,&rear);
    display(front,rear);
    printf("\n");
    enqueue(&front,&rear,5);
    display(front,rear);    
}


 
