#include<stdio.h>
#define SIZE 5
int deque[SIZE];

void init(int *front,int *rear)
{
    front=rear=-1;
}
int isempty(int front,int rear)
{
    return(front==rear && front==-1);
}
int isOneElement(int front,int rear)
{
    return(front==rear && front!=-1);
}
int isfull(int front,int rear)
{
    return ((front==0 && rear==SIZE-1) || (front==rear+1))
}
void insertFront(int *front,int *rear,int data)
{
    if(isfull(*front,*rear))
    {
        printf("The Deque is full");
    }
    else if(isempty(*front,*rear))
    {
        *front=*rear=0;
        deque[*front]=data;
    }
    else if(*front==0)
        {
        *front=SIZE-1;
        deque[*front]=data;
        }
    else
    {
        deque[--(*front)]=data;
    }
}

void insertRear(int *front,int *rear,int data)
{
    if(isfull(*front,*rear))
    {
        printf("The Deque is full");
    }
    else if(isempty(*front,*rear))
    {
        *front=*rear=0;
        deque[*rear]=data;
    }
    else
        {
           *rear=((*rear)+1)%SIZE;
           deque[*rear]=data;
        }
}
void deleteFront(int *front,int *rear)
{
    if(isempty(*front,*rear))
        printf("DEQUE is empty");
    else if(isOneElement(*front,*rear))
        *front=*rear=-1;
    else
        *front=((*front)+1)%SIZE;
}
void deleteRear(int *front,int *rear)
{
    if(isempty(*front,*rear))
        printf("DEQUE is empty");
    else if(isOneElement(*front,*rear))
        *front=*rear=-1;
    else if(*rear == 0)
        *rear=SIZE-1;
    else
        (*rear)--;
}
void display(front,rear)
{
    int i;
    if(isempty(front,rear))
        printf("DEQUE is empty");
    else if(front > rear)
    {
        for(i=front;i<=SIZE-1;i++)
            print("%d ",deque[i]);
        for(i=0;i<=rear;i++)
            print("%d ",deque[i])
    }
    else{
        for(i=front;i<=rear;i++)
            print("%d ",deque[i]);
    }

}
int main()
{
    int front,rear;
    init(&front,&rear);

}
