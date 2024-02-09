#include<stdio.h>
#define SIZE 10
int queue[SIZE];

void init(int *front,int *rear)
{
    *front=-1;
    *rear=-1;
}
int isempty(int front,int rear)
{
    return (front==-1 && rear==-1);
}
int isfull(int front,int rear)
{
    return (rear==SIZE-1);
}
void enqueue(int *front,int *rear,int data)
{
   if(isfull(*front,*rear))
        printf("\nQueue is full");
   else if(isempty(*front,*rear))
        {
        *front=*rear=0;
        queue[*rear]=data;
        }
   else
        queue[++*rear]=data;

}
int isOneElement(int front,int rear)
{
    return front==rear && rear!=-1;
}
int dequeue(int *front,int *rear)
{
    if(isempty(*front,*rear))
    {
        printf("Queue is empty");
    }
    else if(isOneElement(*front,*rear)){
        *front=-1;
        *rear=-1;
    }
    else
    {
        //int d=queue[*front];
        //*front++;
        return queue[(*front)++];
    }
}
void display(int front,int rear)
{
    printf("\n");
    if(!(isempty(front,rear)))
       {
          for(int i=front;i<=rear;i++)
                printf("%d ",queue[i]);
       }
}
int main()
{
    int front,rear,i;
    init(&front,&rear);
    printf("\n%d %d",front,rear);
    for(i=0;i<=SIZE;i++)
        enqueue(&front,&rear,i);
    display(front,rear);
    for(i=0;i<3;i++)
        dequeue(&front,&rear);
    display(front,rear);
    return 0;
}
